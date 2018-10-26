//
// Created by xiucheng yin on 2018/10/26.
//

#ifndef TINAPLAYER_TINAFFMPEG_H
#define TINAPLAYER_TINAFFMPEG_H

#include "JavaCallHelper.h"
#include "AudioChannel.h"
#include "VideoChannel.h"

extern "C" {
#include <libavformat/avformat.h>
}


class TinaFFmpeg {
public:
    TinaFFmpeg(JavaCallHelper *javaCallHelper, const char *dataSource);

    ~TinaFFmpeg();

    void prepare();

    void _prepare();

private:
    char *dataSource;
    pthread_t pid;
    AVFormatContext *formatContext;
    JavaCallHelper *callHelper;
    AudioChannel *audioChannel;
    VideoChannel *videoChannel;
};


#endif //TINAPLAYER_TINAFFMPEG_H
