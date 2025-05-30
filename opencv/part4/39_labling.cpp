#include </home/woo/kuBig2025/opencv/part2/color.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

using namespace std;
using namespace cv;

String folderPath = "/home/woo/kuBig2025/opencv/data/";

int main()
{
    Mat img = imread(folderPath + "milkdrop.bmp", IMREAD_GRAYSCALE);
    vector<Mat> images;
    images.push_back(img);
    for(int i = 0; i < 5; ++i)
    {
        images.emplace_back(Mat());
    }
    threshold(img, images[1], 0, 255, THRESH_BINARY | THRESH_OTSU);
    erode(images[1], images[2], Mat());
    dilate(images[1], images[3], Mat());
    morphologyEx(images[1], images[4], MORPH_OPEN, Mat(), Point(-1, -1), 4);
    /*
    MORPH_CLOSE는 닫힘 연산으로, 객체의 경계가 부드러워지고 작은 구멍이 메워집니다.
    이 연산은 객체의 경계를 부드럽게 하고, 작은 구멍을 메우는 데 유용합니다.
    예를 들어, 이미지에서 객체의 경계가 불규칙하거나 작은 구멍이 있는 경우, MORPH_CLOSE를 사용하여
    객체의 경계를 부드럽게 하고 작은 구멍을 메울 수 있습니다.
    */
    morphologyEx(images[1], images[5], MORPH_CLOSE, Mat(), Point(-1, -1), 3);

    Mat labels; // 라벨링을 위한 Mat 객체 생성
    int cnt = connectedComponents(images[3], labels);

    cout << "labels: \n" << labels << endl;
    cout << "Number of labels: " << cnt << endl; // 라벨링된 이미지 시각화를 위해 색상 맵 생성

    Mat stats, centroids;
    cnt = connectedComponentsWithStats(images[3], labels, stats, centroids);

    for (int i = 0; i < cnt; ++i)
    {
        int* p = stats.ptr<int>(i);
        if (p[4] < 20)
            continue; // 면적이 20 미만인 객체는 무시
        rectangle(images[3], Rect(p[0], p[1], p[2], p[3]), Scalar(255));
        circle(images[3], Point(centroids.ptr<int>(i)[0], centroids.ptr<int>(i)[1]), 5, Scalar(128), -1);
    }

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
