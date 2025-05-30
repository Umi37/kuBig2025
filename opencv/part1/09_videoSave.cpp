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

    int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH)); // 프레임 너비
    int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)); // 프레임 높이
    double fps = cap.get(CAP_PROP_FPS); // 초당 프레임 수
    int fourcc = VideoWriter::fourcc('D','I','V','X'); // 비디오 코덱 (DIVX)

    VideoWriter outputVideo(folderPath + "inverse_vtest.avi", fourcc, fps, Size(w, h));

    if (!outputVideo.isOpened()) {
        cerr << "비디오 파일을 저장할 수 없습니다!" << endl;

        return -1;
    }

    Mat frame;
    while(true)
    {
        cap >> frame; // 프레임을 읽어옵니다.

        if (frame.empty()) { // 프레임이 비어있으면 종료합니다.
            cout << "비디오 스트림이 끝났습니다." << endl;
            break; // 마지막 프레임 처리 후 루프를 종료합니다.
        }
        
        frame = ~frame; // 프레임을 반전시킵니다. (색상을 반전시킴)
        outputVideo << frame; // 반전된 프레임을 비디오 파일에 저장합니다.

        imshow("frame", frame); // 프레임을 화면에 표시합니다.
        if (waitKey(1000 / fps) == 27 ) // fps 조절 숫자
            break;
    }

    cap.release(); // 비디오 캡처 객체를 해제합니다.
    outputVideo.release(); // 비디오 라이터 객체를 해제합니다.
    destroyAllWindows(); // 모든 창을 닫습니다.

    return 0;
}