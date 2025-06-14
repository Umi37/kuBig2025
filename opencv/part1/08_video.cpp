// core, imgproc, highgui, videoio, imgcodecs, video 등 기본 모듈 포함
#include <opencv2/opencv.hpp>
#include <iostream> 

using namespace std;
using namespace cv;

String folderPath = "/home/woo/kuBig2025/opencv/data/";

int main()
{
    VideoCapture cap(folderPath + "vtest.avi");
    if (!cap.isOpened()) {
        cerr << "비디오 파일을 열 수 없습니다!" << endl;
        return -1;
    }
    cout << "Frame Width: " << cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
    cout << "Frame Height: " << cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
    auto fps = cap.get(CAP_PROP_FPS);
    cout << "FPS: " << cvRound(fps) << endl; // cvRound() 함수는 double 값을 정수로 반올림합니다. (integer로 변환)


    Mat frame;
    while(true)
    {
        cap >> frame; // 프레임을 읽어옵니다.
        if (frame.empty()) { // 프레임이 비어있으면 종료합니다.
            cout << "비디오 스트림이 끝났습니다." << endl;
            break; // 마지막 프레임 처리 후 루프를 종료합니다.
        }
        imshow("frame", frame); // 프레임을 화면에 표시합니다.
        if (waitKey(1000 / fps) == 27 ) // fps 조절 숫자
            break;
    }

    return 0;
}