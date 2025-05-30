#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    VideoCapture cap(0);
    if (!cap.isOpened()) {
        cerr << "카메라를 열 수 없습니다!" << endl;
        return -1;
    }

    Mat frame, gray, blurred, edges, display;

    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        // 사본 복사
        display = frame.clone();

        // 그레이 변환 + 블러
        cvtColor(frame, gray, COLOR_BGR2GRAY);
        GaussianBlur(gray, blurred, Size(5, 5), 1.5);

        // 엣지 검출
        Canny(blurred, edges, 50, 150);

        // 윤곽선 검출
        vector<vector<Point>> contours;
        findContours(edges, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

        // 면을 파란색으로 채우기
        drawContours(display, contours, -1, Scalar(255, 0, 0), FILLED);

        // 결과 출력
        imshow("Original", frame);
        imshow("Edge", edges);
        imshow("Filled Blue Area", display);

        if (waitKey(1) == 27) break; // ESC 키로 종료
    }

    cap.release();
    destroyAllWindows();
    return 0;
}
