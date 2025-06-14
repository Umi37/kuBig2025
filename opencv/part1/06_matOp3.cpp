#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

string folderPath = "/home/woo/kuBig2025/opencv/data/";

int main()
{
    // 이미지 불러오기
    // lenna.bmp 이미지를 읽어서 img 변수에 저장
    // lenna.bmp 파일이 존재하는 경로를 지정

    Mat img = imread(folderPath + "lenna.bmp");

    // 행렬 생성 및 수학 연산 실습
    // 2x2 행렬 생성
    // 행렬의 데이터 타입은 CV_32FC1 (32-bit floating point, single channel)
    float data[] = {1, 1, 2, 3};

    Mat mat1(2, 2, CV_32FC1, data);
    cout << "mat1:\n"
         << mat1 << endl;
    Mat mat2 = mat1.inv();
    cout << "mat2:\n"
         << mat2 << endl;
    cout << "mat1 dot mat2 : \n"
         << mat1.dot(mat2) << endl;
    cout << "mat1.t():\n"
         << mat1.t() << endl;
    cout << "mat1 * mat2 : \n"
         << mat1 * mat2 << endl;
    cout << "reshape 4,1 : \n"
         << mat1.reshape(4) << endl;
    Mat mat3;
    mat1.convertTo(mat3, CV_8UC1);
    // img.resize(100); // crop size
    Mat img2;
    
    if (img.empty())
     {
     cerr << "이미지 불러오기 실패!!" << endl;
     return -1;
     }

     resize(img, img2, Size(2000, 2000));

    imshow("img", img);
    imshow("img2", img2);
    imshow("mat3", mat3);
    waitKey();

    return 0;
}