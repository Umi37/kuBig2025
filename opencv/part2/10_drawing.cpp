#include <opencv2/opencv.hpp>
#include <iostream> 
#include </home/woo/kuBig2025/opencv/part2/color.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/woo/kuBig2025/opencv/data/";

int main()
{
    Mat img(400, 600, CV_8UC3, Scalar(255, 255, 255)); // 흰색 배경의 이미지 생성

    line(img, Point(50, 50), Point(200, 100), blue, 3, LINE_AA);
    line(img, Point(70, 70), Point(220, 120), blue, 3, LINE_4);
    line(img, Point(90, 90), Point(240, 140), blue, 3, LINE_8);

    arrowedLine(img, Point(110, 110), Point(260, 160), orange, 3, LINE_8);
    arrowedLine(img, Point(130, 130), Point(280, 180), orange, 3, LINE_8, 0, 0.05);

    drawMarker(img, Point(50, 200), red, MARKER_CROSS);
    drawMarker(img, Point(50, 200), black, MARKER_DIAMOND);
    drawMarker(img, Point(50, 200), green, MARKER_STAR);

    rectangle(img, Rect(50, 250, 50, 50), red, 2, LINE_AA);
    rectangle(img, Rect(50, 300, 50, 50), red, -1, LINE_AA);

    circle(img, Point(150, 250), 50, yellow, 2, LINE_AA);
    circle(img, Point(150, 300), 50, yellow, -1, LINE_AA);

    imshow("img", img); // 이미지 표시
    waitKey(0); // 키 입력 대기

    destroyAllWindows(); // 모든 창 닫기
    
    return 0; // 이 코드는 단순히 빈 main 함수로, 실제 기능은 구현되어 있지 않습니다.
}