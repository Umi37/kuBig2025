#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/aa/kuBig2025/opencv/data/";
void printMat(InputArray _mat, OutputArray _output);

int main()
{
    Mat img = Mat(10, 20, CV_8UC1, Scalar(125));

    Mat mat2;
    printMat(img, mat2);
    cout << mat2 << endl;
    return 0;
} 

// Mat 객체를 InputArray로 전달하는 함수
// InputArray는 Mat, UMat, GpuMat 등 다양한 형태의 행렬을 받아들일 수 있는 범용적인 입력 형식
void printMat(InputArray _mat, OutputArray _output)
{
    Mat img = _mat.getMat();
    cout << img << endl;
    Mat img2 = img + 3;
    img2.copyTo(_output);
}