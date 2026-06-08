#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/aa/jina_2026/opencv_ex/data/";

int main()
{
    cout << "hello, world" << endl;
    // Mat img = imread(folderPath + "aa.png");
    // Mat img = Mat::zeros(480, 640, CV_8UC3);
    Mat img = Mat(480, 640, CV_8UC3, Scalar(255, 255, 255));
    Size size(640, 480);
    resize(img, img, size);
    imshow("lenna", img);
    waitKey();

    return 0;
}