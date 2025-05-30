#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// 마우스 콜백 함수
void on_mouse(int event, int x, int y, int flags, void* userdata) {
    Mat* img = reinterpret_cast<Mat*>(userdata);

    if (event == EVENT_LBUTTONDOWN) {
        cout << "왼쪽 버튼 클릭: (" << x << ", " << y << ")" << endl;
        circle(*img, Point(x, y), 5, Scalar(0, 0, 255), FILLED);
        imshow("Mouse Event", *img);
    }
    else if (event == EVENT_RBUTTONDOWN) {
        cout << "오른쪽 버튼 클릭: (" << x << ", " << y << ")" << endl;
        rectangle(*img, Point(x-10, y-10), Point(x+10, y+10), Scalar(255, 0, 0), 2);
        imshow("Mouse Event", *img);
    }
}

int main() {
    Mat img = Mat::zeros(400, 600, CV_8UC3);

    namedWindow("Mouse Event");
    setMouseCallback("Mouse Event", on_mouse, &img);

    imshow("Mouse Event", img);
    cout << "마우스 왼쪽/오른쪽 버튼을 클릭해보세요. ESC를 누르면 종료됩니다." << endl;

    while (true) {
        int key = waitKey(1);
        if (key == 27) break; // ESC 키
    }
    destroyAllWindows();
    return 0;
}