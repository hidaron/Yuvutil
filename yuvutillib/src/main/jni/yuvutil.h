/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
#include "libyuv.h"
/* Header for class org_limlee_yuvutillib_YUVUtil */

#ifndef _Included_org_limlee_yuvutillib_YUVUtil
#define _Included_org_limlee_yuvutillib_YUVUtil
#ifdef __cplusplus
extern "C" {
#endif

JNIEXPORT jint JNICALL Java_org_limlee_yuvutillib_YUVUtil_NV21ToI420
        (JNIEnv *, jobject, jbyteArray, jint, jbyteArray, jint, jbyteArray, jint, jbyteArray, jint,
         jbyteArray, jint, jint, jint);

JNIEXPORT jint JNICALL Java_org_limlee_yuvutillib_YUVUtil_I420Rotate
        (JNIEnv *, jobject, jbyteArray, jint, jbyteArray, jint, jbyteArray, jint, jbyteArray, jint,
         jbyteArray, jint, jbyteArray, jint, jint, jint, jint);

JNIEXPORT jint JNICALL Java_org_limlee_yuvutillib_YUVUtil_I420Scale(JNIEnv *, jobject, jbyteArray,
                                                                    jint, jbyteArray, jint,
                                                                    jbyteArray, jint, jint, jint,
                                                                    jbyteArray, jint, jbyteArray,
                                                                    jint, jbyteArray, jint, jint,
                                                                    jint, jint);

#ifdef __cplusplus
}
#endif
#endif