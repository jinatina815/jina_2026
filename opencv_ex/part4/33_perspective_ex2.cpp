#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

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

    Point2f srcPts[4] =
    {
        Point2f(0, 0),
        Point2f(w - 1, 0),
        Point2f(w - 1, h - 1),
        Point2f(0, h - 1)
    };

    double t = 0.0;

    while (true)
    {
        float amp = 50.0f; // 왜곡 강도

        Point2f dstPts[4] =
        {
            Point2f(
                amp * sin(t),
                amp * cos(t)
            ),

            Point2f(
                w - 1 + amp * sin(t + 1.0),
                amp * cos(t + 1.0)
            ),

            Point2f(
                w - 1 + amp * sin(t + 2.0),
                h - 1 + amp * cos(t + 2.0)
            ),

            Point2f(
                amp * sin(t + 3.0),
                h - 1 + amp * cos(t + 3.0)
            )
        };

        Mat M = getPerspectiveTransform(srcPts, dstPts);

        Mat dst;
        warpPerspective(
            img,
            dst,
            M,
            img.size(),
            INTER_LINEAR,
            BORDER_REFLECT
        );

        imshow("Original", img);
        imshow("Jelly Distortion", dst);

        t += 0.03; // 속도 조절

        int key = waitKey(16); // 약 60FPS

        if (key == 27) // ESC
            break;
    }

    destroyAllWindows();
    return 0;
}