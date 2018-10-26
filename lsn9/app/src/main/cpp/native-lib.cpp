#include <jni.h>
#include <string>
#include <android/log.h>

extern "C" {
extern int test();
}

extern "C" JNIEXPORT jstring JNICALL
Java_tina_com_myapplication_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";

    __android_log_print(ANDROID_LOG_ERROR,"jni","libtest.so 里面的 test 方法:%d",test());
    return env->NewStringUTF(hello.c_str());
}
