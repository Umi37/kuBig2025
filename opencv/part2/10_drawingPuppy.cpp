#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    // 흰색 배경 (흑백 이미지)
    Mat img(500, 500, CV_8UC1, Scalar(255));

    // 얼굴 (원)
    circle(img, Point(250, 250), 120, Scalar(0), 2); // 얼굴 윤곽

    // 귀 (삼각형 느낌으로 선 2개씩)
    line(img, Point(150, 150), Point(100, 80), Scalar(0), 2); // 왼쪽 귀
    line(img, Point(100, 80), Point(180, 130), Scalar(0), 2);

    line(img, Point(350, 150), Point(400, 80), Scalar(0), 2); // 오른쪽 귀
    line(img, Point(400, 80), Point(320, 130), Scalar(0), 2);

    // 눈 (작은 원)
    circle(img, Point(210, 230), 10, Scalar(0), -1); // 왼쪽 눈
    circle(img, Point(290, 230), 10, Scalar(0), -1); // 오른쪽 눈

    // 코 (역삼각형 느낌)
    line(img, Point(250, 250), Point(240, 270), Scalar(0), 2);
    line(img, Point(250, 250), Point(260, 270), Scalar(0), 2);
    line(img, Point(240, 270), Point(260, 270), Scalar(0), 2);

    // 입 (반원 모양)
    ellipse(img, Point(250, 290), Size(30, 15), 0, 0, 180, Scalar(0), 2); // 웃는 입

    // 수염 (왼쪽, 오른쪽)
    line(img, Point(220, 280), Point(180, 275), Scalar(0), 1); // 왼쪽 수염
    line(img, Point(220, 285), Point(180, 285), Scalar(0), 1);
    line(img, Point(220, 290), Point(180, 295), Scalar(0), 1);

    line(img, Point(280, 280), Point(320, 275), Scalar(0), 1); // 오른쪽 수염
    line(img, Point(280, 285), Point(320, 285), Scalar(0), 1);
    line(img, Point(280, 290), Point(320, 295), Scalar(0), 1);

    // 결과 이미지 보여주기
    imshow("Puppy Face (Black & White)", img);
    waitKey(0);
    destroyAllWindows();

    return 0;
}
