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
    Mat img = imread(folderPath + "lenna.bmp", IMREAD_GRAYSCALE);
    vector<Mat> images;

    Mat dx, dy;
    Sobel(img, dx, CV_32FC1, 1, 0); // x 방향 미분 // 사람 이름이 함수로 들어갈 때는 예외적으로 대문자 사용
    Sobel(img, dy, CV_32FC1, 0, 1); // y 방향 미분
    // Scharr 필터 사용해보기

    // Sobel 함수는 x, y 방향의 미분을 계산하여 dx, dy에 저장
    Mat magni, angle;
    magnitude(dx, dy, magni);   // magnitude 함수는 dx, dy의 크기를 계산하여 magni에 저장
    phase(dx, dy, angle, true); // phase 함수는 dx, dy의 방향을 계산하여 angle에 저장
    
    dx.convertTo(dx, CV_8UC1);  // dx를 8비트 단일 채널로 변환
    dy.convertTo(dy, CV_8UC1);  // dy를 8비트 단일 채널로 변환
    images.push_back(dx);       // x 방향 미분 이미지
    images.push_back(dy);       // y 방향 미분 이미지
    
    magni.convertTo(magni, CV_8UC1);    // magni를 8비트 단일 채널로 변환
    angle.convertTo(angle, CV_8UC1);    // angle을 8비트 단일 채널로 변환
    images.push_back(magni);            // 크기 이미지
    images.push_back(angle);            // 방향 이미지

    Mat edge = magni > 150;         // 크기가 150보다 큰 부분을 에지로 간주
    edge.convertTo(edge, CV_8UC1);  // 에지 이미지를 8비트 단일 채널로 변환
    images.push_back(edge);         // 에지 이미지 추가

    // vector img show 코드
    int i = 1;
    for (auto img : images)
    {
        imshow("img" + to_string(i), img);
        ++i;
    }

    waitKey();
    destroyAllWindows();
    return 0;
}