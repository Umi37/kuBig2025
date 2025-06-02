#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

void onMouse(int event, int x, int y, int, void* userdata)
{
    if (event == EVENT_LBUTTONDOWN) {
        Mat* hsvClone = (Mat*)userdata;
        Vec3b color = hsvClone->at<Vec3b>(y, x);
        cout << "클릭 좌표 HSV Clone = (" << (int)color[0] << ", " << (int)color[1] << ", " << (int)color[2] << ")" << endl;
    }
}

int main() {
    VideoCapture cap(0);  // 0번 카메라 열기 (기본 웹캠)

    if (!cap.isOpened()) {
        cerr << "❌ 카메라를 열 수 없습니다!" << endl;
        return -1;
    }

    Mat frame, hsvClone, mask, cleanedMask;
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3)); // 노이즈 제거를 위한 커널 생성
    

    namedWindow("🟩 HSV Clone 이미지");
    setMouseCallback("🟩 HSV Clone 이미지", onMouse, &hsvClone);

    // 필터링 할 색상 범위 지정
    // Scalar lower(120, 0, 210);
    // Scalar upper(145, 60, 255);

    while (true) {
        cap >> frame; // 한 프레임 읽기
        if (frame.empty()) {
            cerr << "❌ 프레임을 가져오지 못했습니다!" << endl;
            break;
        }

        // ✅ 좌우 반전 추가
        flip(frame, frame, 1);
        
        // 1. HSV 변환
        cvtColor(frame, hsvClone, COLOR_BGR2HSV);

        // 1.1. HSV clone 만들기 + 양방향 필터 적용
        hsvClone = hsvClone.clone();
        bilateralFilter(hsvClone, hsvClone, 9, 75, 75);  // d=9, sigmaColor=75, sigmaSpace=75


        // 2. 평균 밝기(V) 계산 → Adaptive HSV 범위 설정
        Scalar avgHSV = mean(hsvClone);  // HSV 이미지의 평균 색상 계산
        double avgV = avgHSV[2];    // V 채널의 평균 값
        Scalar lower, upper;        // 색상 범위 초기화

           if (avgV > 230) {
            lower = Scalar(120, 0, 220);
            upper = Scalar(145, 60, 255);
        } else if (avgV > 200) {
            lower = Scalar(120, 0, 200);
            upper = Scalar(145, 70, 255);
        } else if (avgV > 170) {
            lower = Scalar(120, 10, 180);
            upper = Scalar(145, 80, 255);
        } else {
            lower = Scalar(120, 20, 160);
            upper = Scalar(145, 100, 255);
        }

        // 3. 마스크 생성 및 노이즈 제거
        inRange(hsvClone, lower, upper, mask);
        morphologyEx(mask, cleanedMask, MORPH_OPEN, kernel); // 노이즈 제거

        // 3.5. 윤곽선 검출 및 사각형 추출
        vector<vector<Point>> contours;
        findContours(cleanedMask, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE); // 외곽선 찾기
        
        for (const auto& contour : contours) {
            double area = contourArea(contour);
            if (area < 500) continue; // 너무 작은 건 무시

            vector<Point> approx;
            approxPolyDP(contour, approx, arcLength(contour, true) * 0.02, true);

            // 꼭짓점 4개 + 볼록한 도형만 필터링 (사각형 조건)
            if (approx.size() == 4 && isContourConvex(approx)) {
                polylines(frame, approx, true, Scalar(0, 255, 0), 2); // 연두색 사각형 그리기
            }
        }
        
        // 4. 화면 출력
        imshow("🟦 BGR 이미지", frame); // BGR 이미지 창에 출력
        imshow("🟩 HSV Clone 이미지", hsvClone); // 필터 적용 후 HSV
        imshow("🟨 마스크 이미지", mask); // 마스크 이미지 창에 출력
        imshow("🟧 노이즈 제거된 마스크 이미지", cleanedMask); // 노이즈 제거된 마스크 이미지 창에 출력

        // 🔎 평균 HSV 값 디버깅 출력 (선택)
        cout << "🌈 평균 HSV = (" << avgHSV[0] << ", " << avgHSV[1] << ", " << avgHSV[2] << ")" << endl;

        if (waitKey(1) == 27) { // ESC 키 누르면 종료
            cout << "📴 종료합니다!" << endl;
            break;
        }
    }

    cap.release();
    destroyAllWindows();
    return 0;
}
