//
// Created by xiucheng yin on 2018/10/26.
//

#include "VideoChannel.h"
extern "C"{
#include <libavutil/imgutils.h>
#include <libavutil/time.h>
}

VideoChannel::VideoChannel(int id, AVCodecContext *avCodecContext) : BaseChannel(id, avCodecContext) {
    frames.setRelaseCallback(releaseAvFrame);
}

VideoChannel::~VideoChannel() {
    frames.clear();
}
void *decode_task(void *args) {
    VideoChannel *channel = static_cast<VideoChannel *>(args);
    channel->decode();
    return 0;
}


void *render_task(void *args) {
    VideoChannel *channel = static_cast<VideoChannel *>(args);
    channel->render();
    return 0;
}

void VideoChannel::play() {
    isPlaying = 1;
    //1.解码
    pthread_create(&pid_decode, 0, decode_task, this);

    //2. 播放
    pthread_create(&pid_render, 0, render_task, this);


}

//解码
void VideoChannel::decode() {
    AVPacket *packet = 0;
    while (isPlaying){
      int ret = packets.pop(packet);
        if(!isPlaying){
            break;
        }
        if (!ret){
            continue;
        }
        //把包丢给解码器
        ret = avcodec_send_packet(avCodecContext, packet);
        releaseAvPacket(&packet);
        while (ret != 0){
            break;
        }
        AVFrame *frame = av_frame_alloc();

        avcodec_receive_frame(avCodecContext, frame);
        if (ret == AVERROR(EAGAIN)){
            continue;
        } else if(ret != 0){
            break;
        }
        //再开一个线程 播放。
        frames.push(frame);
    }
    releaseAvPacket(&packet);
}


void VideoChannel::render() {
    //目标： RGBA, 没有缩放
    swsContext = sws_getContext(avCodecContext->width, avCodecContext->height, avCodecContext->pix_fmt,
                                            avCodecContext->width, avCodecContext->height, AV_PIX_FMT_RGBA,
                                            SWS_BILINEAR, 0, 0, 0);
    AVFrame *frame = 0;

    uint8_t *dst_data[4];
    int dst_linesize[4];
    av_image_alloc(dst_data, dst_linesize, avCodecContext->width, avCodecContext->height, AV_PIX_FMT_RGBA, 1);
    while (isPlaying){
        int ret = frames.pop(frame);
        if (!isPlaying){
            break;
        }
        //src_lines: 每一行存放的 字节长度
        sws_scale(swsContext, reinterpret_cast<const uint8_t *const *>(frame->data), frame->linesize, 0,
                  avCodecContext->height,
                  dst_data, dst_linesize);

        //把解出来的数据给到 window的Surface，回调出去进行播放
        callback(dst_data[0], dst_linesize[0], avCodecContext->width, avCodecContext->height);
        releaseAvFrame(&frame);
    }
    av_freep(&dst_data[0]);
    releaseAvFrame(&frame);

}

void VideoChannel::setRenderFrameCallback(RenderFrameCallback callback) {
    this->callback = callback;
}


