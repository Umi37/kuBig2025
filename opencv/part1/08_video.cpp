// core, imgproc, highgui, videoio, imgcodecs, video 등 기본 모듈 포함
#include <opencv2/opencv.hpp>
#include <iostream> 

using namespace std;
using namespace cv;

String folderPath = "/home/woo/kuBig2025/opencv/data/";

int main()
{
    VideoCapture cap(folderPath + "https://answers.opencv.org/questions/vtest.avi");
    Mat frame;

    while(true)
    {
        cap >> frame; // 프레임을 읽어옵니다.
        imshow("frame", frame); // 프레임을 화면에 표시합니다.
        if (waitKey(33) == 27 ) // fps 조절 숫자
            break;
    }

    return 0;
}