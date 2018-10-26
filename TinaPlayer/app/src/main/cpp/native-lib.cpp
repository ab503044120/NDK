#include <jni.h>
#include <string>
#include "TinaFFmpeg.h"

/**
 * 解视频，获取视频相关的Info
 */
TinaFFmpeg *ffmpeg = 0;

JavaVM *javaVM = 0;

int JNI_OnLoad(JavaVM *vm, void *r) {
    javaVM = vm;
    return JNI_VERSION_1_6;

}

extern "C"
JNIEXPORT void JNICALL
Java_tina_com_player_TinaPlayer_nativePrepare(JNIEnv *env, jobject instance, jstring dataSource_) {
    const char *dataSource = env->GetStringUTFChars(dataSource_, 0);

    JavaCallHelper *callHelper = new JavaCallHelper(javaVM, env, instance);

    ffmpeg = new TinaFFmpeg(callHelper, dataSource);
    ffmpeg->prepare();

    env->ReleaseStringUTFChars(dataSource_, dataSource);
}