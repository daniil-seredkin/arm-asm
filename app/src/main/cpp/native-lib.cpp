#include <jni.h>
#include <string>
#include <android/log.h>
#include <thread>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

extern "C" {
    void program_main();
    void print(const char* text) {
        __android_log_print(ANDROID_LOG_DEBUG, "OUTPUT", "%s", text);
    }
}

extern "C" JNIEXPORT void JNICALL
Java_com_daniil_asm_MainActivity_runMain(
        JNIEnv*,
        jobject) {
    asm volatile("#my code start");
    program_main();
    asm volatile("#my code end");
}