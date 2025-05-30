#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;

String folderPath = "/home/woo/kuBig2025/opencv/data/";

int main()
{
    Mat original = imread(folderPath + "lenna.bmp");
    if (original.empty()) {
        cerr << "이미지 로딩 실패!" << endl;
        return -1;
    }

    namedWindow("Layered View");

    int brightness = 0; // 밝기 조절 단계 (-255 ~ +255)
    int keycode;

    while (true)
    {
        // original 복사 + 밝기 조절
        Mat foreground;
        original.convertTo(foreground, -1, 1, brightness); // α=1, β=brightness

        imshow("Layered View", foreground);

        keycode = waitKey(10);
        if (keycode == 27) break;

        if (keycode == 'a' || keycode == 'A') {
            brightness += 10;
            if (brightness > 255) brightness = 255;
            cout << "밝기 ↑: " << brightness << endl;
        }
        if (keycode == 'b' || keycode == 'B') {
            brightness -= 10;
            if (brightness < -255) brightness = -255;
            cout << "밝기 ↓: " << brightness << endl;
        }
        if (keycode == 'r' || keycode == 'R') {
            brightness = 0; // 초기화
            cout << "밝기 초기화" << endl;
        }
    }

    return 0;
}
