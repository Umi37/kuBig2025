#include </home/woo/kuBig2025/opencv/part2/color.hpp>
#include <chrono>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <thread>
#include <vector>

using namespace std;
using namespace cv;

String folderPath = "/home/woo/kuBig2025/opencv/data/";

int main()
{
    VideoCapture cap(0);  // 0번 카메라 장치 열기
    Mat img = imread(folderPath + "lenna.bmp", IMREAD_GRAYSCALE);
    vector<Mat> images;
    Mat edge;
    int low_v, high_v;
    namedWindow("img1");
    namedWindow("img");  // 엣지 결과 창
    createTrackbar("lowedge", "img1", &low_v, 255);
    createTrackbar("highedge", "img1", &high_v, 255);
    
    // vector img show 코드
    int i = 1;
    while(true)
    {
        cap >> img;
        Canny(img, edge, low_v, high_v);
        imshow("img", edge);
        waitKey(33);      
    }
    destroyAllWindows();
    return 0;
}