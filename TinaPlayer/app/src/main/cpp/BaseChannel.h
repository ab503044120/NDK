//
// Created by xiucheng yin on 2018/10/27.
//

#ifndef TINAPLAYER_BASECHANNEL_H
#define TINAPLAYER_BASECHANNEL_H

#include "safe_queue.h"
extern "C"{
#include <libavcodec/avcodec.h>
};

class BaseChannel{
public:
    BaseChannel(int id, AVCodecContext *avCodecContext):id(id), avCodecContext(avCodecContext){}

    virtual ~BaseChannel(){
        packets.setRelaseCallback(BaseChannel::releaseAvPacket);
        packets.clear();
    }//子类必须实现

    static void releaseAvPacket(AVPacket** packet){
        if (packet){
            av_packet_free(packet);
            *packet = 0;
        }
    }

    static void releaseAvFrame(AVFrame** aVFrame){
        if (aVFrame){
            av_frame_free(aVFrame);
            *aVFrame = 0;
        }
    }

    virtual void play() = 0;

    int id;

    SafeQueue<AVPacket*> packets;
    AVCodecContext *avCodecContext;

    bool isPlaying;
};

#endif //TINAPLAYER_BASECHANNEL_H
