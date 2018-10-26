#include <iostream>
#include <jni.h>

extern "C"

JNIEXPORT void JNICALL Java_tina_com_tinaplayer_ExampleUnitTest_test(
        JNIEnv *env, jobject instance, jint i, jstring j)
{
    const char* str = env->GetStringUTFChars(j, 0);
    printf("c++打印 %d, %s", i, str);

}