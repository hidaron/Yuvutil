#include "yuvutil.h"
//#include <android/log.h>

//#define TAG "libyuvutil"
//#define LOG_D(...) __android_log_print(ANDROID_LOG_INFO, TAG, __VA_ARGS__)

jint
Java_org_limlee_yuvutillib_YUVUtil_NV21ToI420
  (JNIEnv * env, jobject obj, jbyteArray src_y, jint src_stride_y, jbyteArray src_vu,
		  jint src_stride_vu, jbyteArray dst_y, jint dst_stride_y, jbyteArray dst_u, jint dst_stride_u,
		  jbyteArray dst_v, jint dst_stride_v, jint width, jint height){
	if(!src_y || !src_vu || !dst_y || !dst_u || !dst_v || width <= 0 || height <= 0){
		return -1;
	}
	jbyte* pSrc_y = (*env)->GetByteArrayElements(env, src_y, NULL);
	jbyte* pSrc_vu = (*env)->GetByteArrayElements(env, src_vu, NULL);
	jbyte* pDst_y = (*env)->GetByteArrayElements(env, dst_y, NULL);
	jbyte* pDst_u = (*env)->GetByteArrayElements(env, dst_u, NULL);
	jbyte* pDst_v = (*env)->GetByteArrayElements(env, dst_v, NULL);
	int result = NV21ToI420((uint8*)pSrc_y, src_stride_y, (uint8*)pSrc_vu, src_stride_vu, (uint8*)pDst_y, dst_stride_y,
			(uint8*)pDst_u, dst_stride_u, (uint8*)pDst_v, dst_stride_v, width, height);
	(*env)->ReleaseByteArrayElements(env, src_y, pSrc_y, 0);
	(*env)->ReleaseByteArrayElements(env, src_vu, pSrc_vu, 0);
	(*env)->ReleaseByteArrayElements(env, dst_y, pDst_y, 0);
	(*env)->ReleaseByteArrayElements(env, dst_u, pDst_u, 0);
	(*env)->ReleaseByteArrayElements(env, dst_v, pDst_v, 0);
	return result;
}

// rotation_mode
//0 kRotate0 = 0,  // No rotation.
//90 kRotate90 = 90,  // Rotate 90 degrees clockwise.
//180 kRotate180 = 180,  // Rotate 180 degrees.
//270 kRotate270 = 270,  // Rotate 270 degrees clockwise.
jint
Java_org_limlee_yuvutillib_YUVUtil_I420Rotate
	(JNIEnv *env, jobject obj, jbyteArray src_y, jint src_stride_y, jbyteArray src_u, jint src_stride_u,
			jbyteArray src_v, jint src_stride_v, jbyteArray dst_y,
			jint dst_stride_y, jbyteArray dst_u, jint dst_stride_u, jbyteArray dst_v, jint dst_stride_v,
			jint width, jint height, jint rotation_mode){
	if(!src_y || !src_u || !src_v || !dst_y || !dst_u || !dst_v || width <= 0 || height <= 0){
		return -1;
	}
	jbyte* pSrc_y = (*env)->GetByteArrayElements(env, src_y, NULL);
	jbyte* pSrc_u = (*env)->GetByteArrayElements(env, src_u, NULL);
	jbyte* pSrc_v = (*env)->GetByteArrayElements(env, src_v, NULL);
	jbyte* pDst_y = (*env)->GetByteArrayElements(env, dst_y, NULL);
	jbyte* pDst_u = (*env)->GetByteArrayElements(env, dst_u, NULL);
	jbyte* pDst_v = (*env)->GetByteArrayElements(env, dst_v, NULL);
	enum RotationMode mode;
	if(rotation_mode == 0){
		mode = kRotate0;
	}else if(rotation_mode == 90){
		mode = kRotate90;
	}else if(rotation_mode == 180){
		mode = kRotate180;
	}else if(rotation_mode == 270){
		mode = kRotate270;
	}else{
		mode = kRotate0;
	}
	int result = I420Rotate((uint8*)pSrc_y, src_stride_y, (uint8*)pSrc_u,
			src_stride_u, (uint8*)pSrc_v, src_stride_v, (uint8*)pDst_y, dst_stride_y,
			(uint8*)pDst_u, dst_stride_u, (uint8*)pDst_v, dst_stride_v, width, height, mode);
	(*env)->ReleaseByteArrayElements(env, src_y, pSrc_y, 0);
	(*env)->ReleaseByteArrayElements(env, src_u, pSrc_u, 0);
	(*env)->ReleaseByteArrayElements(env, src_v, pSrc_v, 0);
	(*env)->ReleaseByteArrayElements(env, dst_y, pDst_y, 0);
	(*env)->ReleaseByteArrayElements(env, dst_u, pDst_u, 0);
	(*env)->ReleaseByteArrayElements(env, dst_v, pDst_v, 0);
	return result;
}
/**
 *  kFilterNone = 0,  // Point sample; Fastest.
  	kFilterLinear = 1,  // Filter horizontally only.
  	kFilterBilinear = 2,  // Faster than box, but lower quality scaling down.
  	kFilterBox = 3  // Highest quality.
 */
jint
Java_org_limlee_yuvutillib_YUVUtil_I420Scale
	(JNIEnv * env, jobject obj, jbyteArray src_y, jint src_stride_y, jbyteArray src_u, jint src_stride_u,
			jbyteArray src_v, jint src_stride_v, jint src_width, jint src_height, jbyteArray dst_y, jint dst_stride_y,
			jbyteArray dst_u, jint dst_stride_u, jbyteArray dst_v, jint dst_stride_v, jint dst_width, jint dst_height, jint filtering){
	if(!src_y || !src_u || !src_v || !dst_y || !dst_u || !dst_v
			|| src_width <= 0 || src_height <= 0 || dst_width <= 0 || dst_height <=0){
		return -1;
	}
	enum FilterMode mode;
	if(filtering == 0){
		mode = kFilterNone;
	}else if(filtering == 1){
		mode = kFilterLinear;
	}else if(filtering == 2){
		mode = kFilterBilinear;
	}else if(filtering == 3){
		mode = kFilterBox;
	}else{
		mode = kFilterNone;
	}
	jbyte* pSrc_y = (*env)->GetByteArrayElements(env, src_y, NULL);
	jbyte* pSrc_u = (*env)->GetByteArrayElements(env, src_u, NULL);
	jbyte* pSrc_v = (*env)->GetByteArrayElements(env, src_v, NULL);
	jbyte* pDst_y = (*env)->GetByteArrayElements(env, dst_y, NULL);
	jbyte* pDst_u = (*env)->GetByteArrayElements(env, dst_u, NULL);
	jbyte* pDst_v = (*env)->GetByteArrayElements(env, dst_v, NULL);
	int result = I420Scale((uint8*)pSrc_y, src_stride_y, (uint8*)pSrc_u, src_stride_u, (uint8*)pSrc_v, src_stride_v,
            src_width, src_height, (uint8*)pDst_y, dst_stride_y, (uint8*)pDst_u, dst_stride_u, (uint8*)pDst_v, dst_stride_v,
            dst_width, dst_height, mode);
	(*env)->ReleaseByteArrayElements(env, src_y, pSrc_y, 0);
	(*env)->ReleaseByteArrayElements(env, src_u, pSrc_u, 0);
	(*env)->ReleaseByteArrayElements(env, src_v, pSrc_v, 0);
	(*env)->ReleaseByteArrayElements(env, dst_y, pDst_y, 0);
	(*env)->ReleaseByteArrayElements(env, dst_u, pDst_u, 0);
	(*env)->ReleaseByteArrayElements(env, dst_v, pDst_v, 0);
	return result;
}
