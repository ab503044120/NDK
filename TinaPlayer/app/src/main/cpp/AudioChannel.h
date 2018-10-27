//
// Created by xiucheng yin on 2018/10/26.
//

#ifndef TINAPLAYER_AUDIOCHANNEL_H
#define TINAPLAYER_AUDIOCHANNEL_H

#include "BaseChannel.h"

class AudioChannel: public BaseChannel {
public:
    AudioChannel(int id, AVCodecContext *avCodecContext);
    void play();
};


#endif //TINAPLAYER_AUDIOCHANNEL_H
