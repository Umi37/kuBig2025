#include </home/woo/kuBig2025/opencv/part2/color.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

String folderPath = "/home/woo/kuBig2025/opencv/data/";

int main()
{
    Mat img1 = imread(folderPath + "lenna.bmp");
    Mat img2 = imread(folderPath + "mask_smile.bmp", IMREAD_GRAYSCALE);

    img1.setTo(yellow, img2); // img2의 마스크를 사용하여 img1에 yellow 색상을 적용
    imshow("img", img1);

    Mat airplan = imread(folderPath + "airplane.bmp");
    Mat maskAirplane = imread(folderPath + "mask_plane.bmp", IMREAD_GRAYSCALE);
    Mat sky = imread(folderPath + "field.bmp");

    airplan.copyTo(sky, maskAirplane); // maskAirplane의 마스크를 사용하여 sky에 airplan을 복사

    imshow("sky", sky);
    waitKey(0);
    destroyAllWindows();

    return 0;
}
