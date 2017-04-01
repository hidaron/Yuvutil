LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_CPP_EXTENSION := .cc

LOCAL_SRC_FILES := \
	yuvutil.c			\
    compare.cc           \
    compare_common.cc    \
    convert.cc           \
    convert_argb.cc      \
    convert_from.cc      \
    convert_from_argb.cc \
    convert_to_argb.cc   \
    convert_to_i420.cc   \
    cpu_id.cc            \
    planar_functions.cc  \
    rotate.cc            \
    rotate_any.cc        \
    rotate_argb.cc       \
    rotate_common.cc     \
    row_any.cc           \
    row_common.cc        \
    scale.cc             \
    scale_any.cc         \
    scale_argb.cc        \
    scale_common.cc      \
    video_common.cc

ifeq ($(TARGET_ARCH_ABI),armeabi-v7a)
    LOCAL_CFLAGS += -DLIBYUV_NEON
    LOCAL_SRC_FILES += \
        compare_neon.cc.neon    \
        rotate_neon.cc.neon     \
        row_neon.cc.neon        \
        scale_neon.cc.neon
endif

ifeq ($(TARGET_ARCH_ABI),arm64-v8a)
    LOCAL_CFLAGS += -DLIBYUV_NEON
    LOCAL_SRC_FILES += \
        compare_neon64.cc    \
        rotate_neon64.cc     \
        row_neon64.cc        \
        scale_neon64.cc
endif

ifeq ($(TARGET_ARCH_ABI),$(filter $(TARGET_ARCH_ABI), x86 x86_64))
    LOCAL_SRC_FILES += \
        compare_gcc.cc       \
        rotate_gcc.cc        \
        row_gcc.cc           \
        scale_gcc.cc
endif


LOCAL_EXPORT_C_INCLUDES := $(LOCAL_PATH)/
LOCAL_C_INCLUDES += $(LOCAL_PATH)/

LOCAL_MODULE := libyuvutil
#LOCAL_MODULE_TAGS := optional

#LOCAL_LDLIBS+=-L$(SYSROOT)/usr/lib -llog

include $(BUILD_SHARED_LIBRARY)
#include $(BUILD_STATIC_LIBRARY)

