#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

String folderPath = "/home/woo/kuBig2025/opencv/data/";

void showHistAndResult(const Mat& input, const string& title) {
    Mat hist, result;

    // 평활화 수행
    equalizeHist(input, result);

    // 히스토그램 계산
    int histSize = 256;
    float range[] = {0, 256};
    const float* histRange = {range};
    calcHist(&input, 1, 0, Mat(), hist, 1, &histSize, &histRange);

    // 히스토그램 시각화
    int hist_w = 512, hist_h = 400;
    int bin_w = cvRound((double) hist_w/histSize);
    Mat histImage(hist_h, hist_w, CV_8UC1, Scalar(0));

    normalize(hist, hist, 0, histImage.rows, NORM_MINMAX);

    for (int i = 1; i < histSize; i++) {
        line(histImage,
             Point(bin_w*(i-1), hist_h - cvRound(hist.at<float>(i-1))),
             Point(bin_w*(i),   hist_h - cvRound(hist.at<float>(i))),
             Scalar(255), 2);
    }

    imshow(title + " - Original", input);
    imshow(title + " - Equalized", result);
    imshow(title + " - Histogram", histImage);
}

int main() {
    // 1. 완전 검은 이미지
    Mat blackImg(300, 300, CV_8UC1, Scalar(0));
    showHistAndResult(blackImg, "Black Image");

    // 2. 어두운 인물 사진
    Mat darkImg = imread(folderPath + "dark_face.jpg", IMREAD_GRAYSCALE);
    if (darkImg.empty()) {
        cerr << "dark_face.jpg 불러오기 실패!" << endl;
    } else {
        showHistAndResult(darkImg, "Dark Face");
    }

    // 3. 너무 밝은 이미지
    Mat brightImg = imread(folderPath + "overexposed.jpg", IMREAD_GRAYSCALE);
    if (brightImg.empty()) {
        cerr << "overexposed.jpg 불러오기 실패!" << endl;
    } else {
        showHistAndResult(brightImg, "Bright Image");
    }

    waitKey(0);
    return 0;
}
