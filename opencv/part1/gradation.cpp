#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    // [1] 이미지 크기 설정
    int width = 640;
    int height = 480;

    // [2] 3채널 컬러 이미지 생성 (8비트)
    Mat grad_img(height, width, CV_8UC3);

    // [3] 좌 → 우 빨강 → 파랑 그라데이션
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            uchar red = (uchar)((width - x) * 255 / width);   // 좌측은 빨강
            uchar blue = (uchar)(x * 255 / width);            // 우측은 파랑
            grad_img.at<Vec3b>(y, x) = Vec3b(blue, 0, red);    // BGR 순서!
        }
    }

    // [4] 결과 이미지 윈도우에 표시
    namedWindow("Gradient", WINDOW_AUTOSIZE);
    imshow("Gradient", grad_img);

    // [5] 아무 키나 누를 때까지 대기
    waitKey(0);

    // [6] 이미지 저장 (선택사항)
    imwrite("gradient_red_to_blue.jpg", grad_img);

    return 0;
}
