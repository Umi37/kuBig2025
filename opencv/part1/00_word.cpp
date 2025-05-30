#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// String folderPath = "/home/woo/kuBig2025/opencv/data/";
// string folderPath = "/home/woo/kuBig2025/opencv/data/";


enum VideoCaptureAPIs {
    CAP_ANY = 0, // Auto detect default API.
    CAP_V4L = 1, // V4L/V4L2 capturing using video4linux v2 API.
    CAP_V4L2 = 2, // V4L2 capturing using video4linux v2 API.
    CAP_FIREWIRE = 3, // IEEE 1394 drivers.
    CAP_FIREWARE = 3, // IEEE 1394 drivers (alias).
    CAP_IEEE1394 = 3, // IEEE 1394 drivers (alias).
    CAP_DC1394 = 3, // IEEE 1394 drivers (alias).
    CAP_CMU1394 = 3, // IEEE 1394 drivers (alias).
    CAP_QT = 4, // QuickTime capturing using QuickTime API.
    CAP_UNICAP = 5, // Unicap drivers.
    CAP_DSHOW = 6, // DirectShow (via videoInput) capturing using DirectShow API.
    CAP_PVAPI = 7, // Prosilica GigE SDK.
    CAP_OPENNI = 8, // OpenNI (for Kinect) capturing using OpenNI API.
    CAP_OPENNI_ASUS = 9, // OpenNI (for Asus Xtion) capturing using OpenNI API.
    CAP_ANDROID = 10, // Android capturing using Android NDK camera API.
    CAP_XIAPI = 11, // XIMEA Camera API.
    CAP_AVFOUNDATION = 12, // AVFoundation framework for iOS and macOS.
    CAP_GIGANETIX = 13, // Giganetix GigE Vision SDK.
    CAP_INTELPERC = 14, // Intel Perceptual Computing SDK.
    CAP_REALSENSE = 15, // Intel RealSense SDK.
    CAP_OPENCV_MJPEG_SERVER = 16, // OpenCV MJPEG server for streaming video over HTTP.
    CAP_GPHOTO2 = 17, // GPhoto2 library for camera control.    
};

enum videoCatureProperties {
    CAP_PROP_POS_MSEC = 0, // Current position of the video file in milliseconds.
    CAP_PROP_POS_FRAMES = 1, // 0-based index of the frame to be decoded/captured next.
    CAP_PROP_POS_AVI_RATIO = 2, // Relative position of the video file.
    CAP_PROP_FRAME_WIDTH = 3, // Width of the frames in the video stream.
    CAP_PROP_FRAME_HEIGHT = 4, // Height of the frames in the video stream.
    CAP_PROP_FPS = 5, // Frame rate.
    CAP_PROP_FOURCC = 6, // Codec used to compress the frames.
    CAP_PROP_FRAME_COUNT = 7, // Number of frames in the video file.
    CAP_PROP_FORMAT = 8, // Format of the Mat objects returned by retrieve() .
    CAP_PROP_MODE = 9, // Backend-specific value indicating the current capture mode.
    CAP_PROP_BRIGHTNESS = 10, // Brightness of the image (only for cameras).
    CAP_PROP_CONTRAST = 11, // Contrast of the image (only for cameras).
    CAP_PROP_SATURATION = 12, // Saturation of the image (only for cameras).
    CAP_PROP_HUE = 13, // Hue of the image (only for cameras).
    CAP_PROP_GAIN = 14, // Gain of the image (only for cameras).
    CAP_PROP_EXPOSURE = 15, // Exposure time in seconds (only for cameras).
    CAP_PROP_CONVERT_RGB = 16, // Boolean flag indicating whether to convert images to RGB format.
};

int main()
{
    
}