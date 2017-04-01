package org.limlee.yuvutillib;


public class YUVUtil {

    private YUVUtil() {

    }

    static {
        System.loadLibrary("yuvutil");
    }

    public static native int NV21ToI420(byte[] src_y, int src_stride_y,
                                        byte[] src_vu, int src_stride_vu,
                                        byte[] dst_y, int dst_stride_y,
                                        byte[] dst_u, int dst_stride_u,
                                        byte[] dst_v, int dst_stride_v,
                                        int width, int height);

    public static native int I420Rotate(byte[] src_y, int src_stride_y,
                                        byte[] src_u, int src_stride_u,
                                        byte[] src_v, int src_stride_v,
                                        byte[] dst_y, int dst_stride_y,
                                        byte[] dst_u, int dst_stride_u,
                                        byte[] dst_v, int dst_stride_v,
                                        int src_width, int src_height, int rotateMode);

    public static native int I420Scale(byte[] src_y, int src_stride_y,
                                       byte[] src_u, int src_stride_u,
                                       byte[] src_v, int src_stride_v,
                                       int src_width, int src_height,
                                       byte[] dst_y, int dst_stride_y,
                                       byte[] dst_u, int dst_stride_u,
                                       byte[] dst_v, int dst_stride_v,
                                       int dst_width, int dst_height,
                                       int filterMode);

}
