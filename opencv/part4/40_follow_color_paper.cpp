#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

// 이 코드는 OpenCV를 사용하여 카메라에서 실시간으로 영상을 캡처하고,
// 그레이스케일로 변환한 후 블러링을 적용하고, 엣지 검출을 수행하여
// 윤곽선을 검출하고, 검출된 윤곽선을 파란색으로 채워서 화면에 표시하는 예제입니다.
// 윤곽선은 외곽선만을 검출하며, 내부의 윤곽선은 무시합니다.
// 이 코드는 OpenCV 라이브러리를 사용하여 작성되었습니다.
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
