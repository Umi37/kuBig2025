#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// String folderPath = "/home/woo/kuBig2025/opencv/data/";
// string folderPath = "/home/woo/kuBig2025/opencv/data/";

int main()
{
    cout << "Hello, Lenna" << endl;

    // Mat : OpenCV에서 이미지 또는 행렬 데이터를 표현하기 위한 핵심 클래스 (Matrix의 약자)
    // Mat 클래스는 이미지, 비디오 프레임, 또는 일반적인 행렬 연산을 수행할 때 사용된다.
    
    Mat img = imread("/home/woo/kuBig2025/opencv/data/lenna.bmp"); 
    /*
    
    imread 함수는 imgcodecs.hpp에 정의되어 있음
    imread 함수는 전역 함수로 정의된 자유 함수
    반환 타입이 Mat인 함수
    이미지 파일을 읽어서 Mat 객체로 반환
    첫 번째 인자는 이미지 파일의 경로 (문자열)
    두 번째 인자는 이미지 읽기 플래그 (기본값은 IMREAD_COLOR, 즉 컬러 이미지로 읽음)
    두 번째 인자는 생략 가능
    만약 이미지 파일이 존재하지 않거나 읽기 실패 시, 반환되는 Mat 객체는 비어있는 상태가 된다.
    즉, img.empty()가 true가 된다.
    따라서, 이미지 파일을 읽은 후에는 항상 img.empty()를 확인하여 이미지가 제대로 읽혔는지 확인하는 것이 좋다.
    
    */ 
    if (img.empty())
    {
        cerr << "이미지 불러오기 실패!! ";
        return -1;
    }

    // cout << img << endl;
    namedWindow("lenna", WINDOW_NORMAL);
    setWindowProperty("lenna", WND_PROP_FULLSCREEN, WINDOW_FULLSCREEN);
    // Size size(640, 480);
    // resizeWindow("lenna", size);

    imshow("lenna", img);
    waitKey();
    vector<int> jpg_params;
    jpg_params.push_back(IMWRITE_JPEG_QUALITY);
    jpg_params.push_back(20);

    imwrite("/home/woo/kuBig2025/opencv/data/lenna_save_20.jpg", img, jpg_params);

    return 0;
}