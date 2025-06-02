#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void onMouse(int event, int x, int y, int, void* userdata)
{
    if (event == EVENT_LBUTTONDOWN) {
        Mat* hsv = (Mat*)userdata;
        Vec3b color = hsv->at<Vec3b>(y, x);
        cout << "클릭 좌표 HSV = (" << (int)color[0] << ", " << (int)color[1] << ", " << (int)color[2] << ")" << endl;
    }
}

int main() {
    VideoCapture cap(0);  // 0번 카메라 열기 (기본 웹캠)

    if (!cap.isOpened()) {
        cerr << "❌ 카메라를 열 수 없습니다!" << endl;
        return -1;
    }

    Mat frame, hsv, mask;
    
    namedWindow("🟩 HSV 이미지");
    setMouseCallback("🟩 HSV 이미지", onMouse, &hsv);

    // 필터링 할 색상 범위 지정
    Scalar lower(120, 5, 220);   // 보라핑크 계열 + 저채도 + 밝은색
    Scalar upper(145, 40, 255);  // S는 아주 낮게, V는 밝게 유지




    while (true) {
        cap >> frame; // 한 프레임 읽기
        if (frame.empty()) {
            cerr << "❌ 프레임을 가져오지 못했습니다!" << endl;
            break;
        }
        // BGR -> HSV 변환
        cvtColor(frame, hsv, COLOR_BGR2HSV);

        // 지정한 색상 범위에 해당하는 부분을 마스크로 생성
        inRange(hsv, lower, upper, mask);

        // 화면에 BGR과 HSV 이미지 출력
        imshow("🟦 BGR 이미지", frame); // BGR 이미지 창에 출력
        imshow("🟩 HSV 이미지", hsv); // HSV 이미지 창에 출력
        imshow("🟨 마스크 이미지", mask); // 마스크 이미지 창에 출력


        if (waitKey(1) == 27) { // ESC 키 누르면 종료
            cout << "📴 종료합니다!" << endl;
            break;
        }
    }

    cap.release();
    destroyAllWindows();
    return 0;
}
