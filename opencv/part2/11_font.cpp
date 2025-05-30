#include <opencv2/opencv.hpp>
#include <iostream> 
#include </home/woo/kuBig2025/opencv/part2/color.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/woo/kuBig2025/opencv/data/";

int main()
{
    Mat img(400, 600, CV_8UC3, white); // 흰색 배경의 이미지 생성
    int a = 0, b = 0, c = 0;

    while(true)
    {
        img.setTo(white); // 매 반복마다 흰색 배경으로 초기화
        putText(img, "This is kuBig2025 test Text", Point(20 + a, 50), FONT_HERSHEY_SIMPLEX, 2, red);
        putText(img, "This is kuBig2025 test Text", Point(20 + a, 100), FONT_ITALIC, 2, red);
        putText(img, "This is kuBig2025 test Text", Point(20 + a, 150), FONT_HERSHEY_DUPLEX, 3, blue);
        putText(img, "This is kuBig2025 test Text", Point(20 + a, 200), FONT_HERSHEY_PLAIN, 4, black);

        imshow("img", img); // 이미지 표시
        if (waitKey(33) == 27)
        {
            break; // ESC 키를 누르면 종료
        }
        a += 1; // x 좌표를 증가시켜 텍스트 위치를 이동
        b -= 1; // y 좌표를 감소시켜 텍스트 위치를 이동
        c += 3; // y 좌표를 증가시켜 텍스트 위치를 이동
    }
    destroyAllWindows(); // 모든 창 닫기
    return 0; // 프로그램 종료
}
