#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    const String folderPath = "/home/aa/jina_2026/opencv_ex/data/";

    Mat img = imread(folderPath + "lenna.bmp");

    if (img.empty())
    {
        cout << "Image Load Error!" << endl;
        return -1;
    }

    int w = img.cols;
    int h = img.rows;

    // 원본 이미지의 네 꼭짓점
    Point2f srcPts[4] = {
        Point2f(0, 0),
        Point2f(w - 1, 0),
        Point2f(w - 1, h - 1),
        Point2f(0, h - 1)
    };

    // 왜곡 후 좌표
    Point2f dstPts[4] = {
        Point2f(100, 50),      // 좌상
        Point2f(w - 100, 0),  // 우상
        Point2f(w - 50, h),   // 우하
        Point2f(50, h - 50)   // 좌하
    };

    Mat M = getPerspectiveTransform(srcPts, dstPts);

    Mat dst;
    warpPerspective(img, dst, M, img.size());

    imshow("Original", img);
    imshow("Distorted", dst);

    waitKey(0);
    destroyAllWindows();

    return 0;
}