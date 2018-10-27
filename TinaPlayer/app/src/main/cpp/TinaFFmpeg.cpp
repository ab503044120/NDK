//
// Created by xiucheng yin on 2018/10/26.
//
#include <cstring>
#include <pthread.h>

#include "TinaFFmpeg.h"
#include "macro.h"

void *task_prepare(void *arges) {
    TinaFFmpeg *ffmpeg = static_cast<TinaFFmpeg *>(arges);

    ffmpeg->_prepare();
    return 0;
}

TinaFFmpeg::TinaFFmpeg(JavaCallHelper *callHelper, const char *dataSource) {
    //需要内存拷贝，否则会造成悬空指针
//    this->dataSource = const_cast<char *>(dataSource);
    this->callHelper = callHelper;
    //strlen 获得字符串的长度，不包括\0
    this->dataSource = new char[strlen(dataSource) + 1];
    stpcpy(this->dataSource, dataSource);
}


TinaFFmpeg::~TinaFFmpeg() {
    //释放
    DELETE(dataSource);
    DELETE(callHelper);
}


void TinaFFmpeg::prepare() {
    //创建线程
    pthread_create(&pid, 0, task_prepare, this);

}

void TinaFFmpeg::_prepare() {

    //初始化网络 让ffmpeg 能够
    avformat_network_init();
    //1. 打开播放的媒体地址（文件、直播地址）
    //AVFormatContext 包含了视频的信息（宽、高）
    formatContext = 0;

    int ret = avformat_open_input(&formatContext, dataSource, 0, 0);
    if (ret != 0){
        LOGE("打开媒体失败:%s",av_err2str(ret));
        callHelper->onError(THREAD_CHILD, FFMPEG_CAN_NOT_OPEN_URL);
        return;
    }

    //2. 查找音视频中的流
    ret = avformat_find_stream_info(formatContext, 0);
    if (ret < 0){
        LOGE("查找流失败:%s",av_err2str(ret));
        callHelper->onError(THREAD_CHILD, FFMPEG_CAN_NOT_FIND_STREAMS);
        return;
    }

    //nb_streams; 几个流（几段视频/音频）
    for (int i = 0; i < formatContext->nb_streams; ++i) {
        //可能代表是一个视频，也可以代表是一个音频
        AVStream *stream = formatContext->streams[i];
        //包含 解码这段流的工种参数信息
        AVCodecParameters *codecpar = stream->codecpar;

        //无论音频、视频，需要做的事情（获得解码器）
        AVCodec *dec = avcodec_find_decoder(codecpar->codec_id);

        if (dec == NULL){
            LOGE("查找解码器失败:%s",av_err2str(ret));
            callHelper->onError(THREAD_CHILD, FFMPEG_FIND_DECODER_FAIL);
            return;
        }

        //获得解码器上下文
        AVCodecContext *context = avcodec_alloc_context3(dec);
        if (context == NULL){
            LOGE("创建解码上下文失败:%s",av_err2str(ret));
            callHelper->onError(THREAD_CHILD, FFMPEG_ALLOC_CODEC_CONTEXT_FAIL);
            return;
        }

        //3. 设置上下文内的一些参数
        ret = avcodec_parameters_to_context(context, codecpar);
        if (ret < 0){
            LOGE("设置解码上下文参数失败:%s",av_err2str(ret));
            callHelper->onError(THREAD_CHILD, FFMPEG_OPEN_DECODER_FAIL);
            return;
        }

        //4. 打开解码器
        ret = avcodec_open2(context, dec, 0);
        if (ret != 0){
            LOGE("打开解码器失败:%s",av_err2str(ret));
            callHelper->onError(THREAD_CHILD, FFMPEG_ALLOC_CODEC_CONTEXT_FAIL);
            return;
        }

        //音频
        if (codecpar->codec_type == AVMEDIA_TYPE_AUDIO){//0
            audioChannel = new AudioChannel(i, context);
        } else if(codecpar->codec_type == AVMEDIA_TYPE_VIDEO){//视频
            videoChannel = new VideoChannel(i, context);
            videoChannel->setRenderFrameCallback(callback);
        }
    }

    if (!audioChannel && !videoChannel){
        LOGE("没有音视频");
        callHelper->onError(THREAD_CHILD,FFMPEG_NOMEDIA);
        return;
    }
    LOGE("native prepare流程准备完毕");
    // 准备完了 通知java 你随时可以开始播放
    callHelper->onPrepare(THREAD_CHILD);
}


void* play(void* args){
    TinaFFmpeg* fFmpeg = static_cast<TinaFFmpeg *>(args);
    fFmpeg->_start();
    return 0;
}

void TinaFFmpeg::start() {
    //重新开线程
    isPlaying = 1;
    if(videoChannel){
        //设置为工作状态
        videoChannel->packets.setWork(1);
        videoChannel->play();
    }
    if (audioChannel){
        //设置为工作状态
        audioChannel->packets.setWork(1);
        audioChannel->play();
    }
    pthread_create(&pid_play, 0, play, this);
}

void TinaFFmpeg::_start() {
    int ret;
    //1.读取媒体数据包（音频、视频数据）
    while (isPlaying){
        AVPacket *avPacket = av_packet_alloc();
        ret = av_read_frame(formatContext, avPacket);
        //等于0成功，其它失败
        if(ret == 0){
            if(audioChannel && avPacket->stream_index == audioChannel->id){
                //todo 音频
                //在audioChannel中执行 解码工作
                audioChannel->packets.push(avPacket);
            } else if(videoChannel && avPacket->stream_index == videoChannel->id){
                //在videoChannel中执行 解码工作
                videoChannel->packets.push(avPacket);
            }
        }else if(ret == AVERROR_EOF){

        }else{

        }

    }
}

void TinaFFmpeg::setRenderFrameCallback(RenderFrameCallback callback){
    this->callback = callback;
}

