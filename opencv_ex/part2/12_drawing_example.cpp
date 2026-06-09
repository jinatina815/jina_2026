#include <opencv2/opencv.hpp>
#include <cmath>

using namespace cv;
using namespace std;

int main()
{
    Mat background(500, 800, CV_8UC3, Scalar(245, 245, 245));

    int t = 0;

    while (true)
    {
        Mat img = background.clone();

        // 바닥
        line(img,
             Point(0, 400),
             Point(800, 400),
             Scalar(100, 100, 100),
             3,
             LINE_AA);

        //--------------------------------
        // 점프 사이클
        //--------------------------------
        int cycle = 120;
        int phase = t % cycle;

        double progress = phase / (double)cycle;

        double jumpHeight = 0;

        if (progress < 0.5)
        {
            double p = progress / 0.5;
            jumpHeight = 180 * (1 - pow(2 * p - 1, 2));
        }

        //--------------------------------
        // 캐릭터 위치
        //--------------------------------
        int x = 400;
        int groundY = 360;

        int y = groundY - (int)jumpHeight;

        //--------------------------------
        // Stretch & Squash
        //--------------------------------
        double scaleX = 1.0;
        double scaleY = 1.0;

        if (jumpHeight > 120)
        {
            scaleX = 0.9;
            scaleY = 1.15;
        }

        if (phase > 58 && phase < 70)
        {
            scaleX = 1.2;
            scaleY = 0.8;
        }

        //--------------------------------
        // 그림자
        //--------------------------------
        int shadowW =
            (int)(60 - jumpHeight / 4);

        ellipse(img,
                Point(x, 400),
                Size(max(shadowW, 15), 12),
                0,
                0,
                360,
                Scalar(80, 80, 80),
                FILLED,
                LINE_AA);

        //--------------------------------
        // 몸
        //--------------------------------
        int headR = (int)(35 * scaleY);

        circle(img,
               Point(x, y),
               headR,
               Scalar(180, 220, 255),
               FILLED,
               LINE_AA);

        //--------------------------------
        // 표정
        //--------------------------------
        if (jumpHeight > 140)
        {
            // 신난 표정

            line(img,
                 Point(x - 15, y - 5),
                 Point(x - 5, y + 5),
                 Scalar(0,0,0),
                 2);

            line(img,
                 Point(x - 15, y + 5),
                 Point(x - 5, y - 5),
                 Scalar(0,0,0),
                 2);

            line(img,
                 Point(x + 5, y - 5),
                 Point(x + 15, y + 5),
                 Scalar(0,0,0),
                 2);

            line(img,
                 Point(x + 5, y + 5),
                 Point(x + 15, y - 5),
                 Scalar(0,0,0),
                 2);

            ellipse(img,
                    Point(x, y + 15),
                    Size(15, 10),
                    0,
                    0,
                    180,
                    Scalar(0,0,255),
                    3);
        }
        else
        {
            circle(img,
                   Point(x - 12, y - 5),
                   4,
                   Scalar(0,0,0),
                   FILLED);

            circle(img,
                   Point(x + 12, y - 5),
                   4,
                   Scalar(0,0,0),
                   FILLED);

            ellipse(img,
                    Point(x, y + 10),
                    Size(12,6),
                    0,
                    0,
                    180,
                    Scalar(0,0,0),
                    2);
        }

        //--------------------------------
        // 몸통
        //--------------------------------
        int bodyH = (int)(60 * scaleY);
        int bodyW = (int)(45 * scaleX);

        rectangle(img,
                  Rect(
                      x - bodyW / 2,
                      y + headR,
                      bodyW,
                      bodyH),
                  Scalar(255,180,100),
                  FILLED,
                  LINE_AA);

        //--------------------------------
        // 팔 흔들기
        //--------------------------------
        double arm =
            sin(t * 0.15) * 25;

        line(img,
             Point(x - bodyW/2, y + 55),
             Point(x - 40,
                   y + 55 - arm),
             Scalar(0,0,0),
             4,
             LINE_AA);

        line(img,
             Point(x + bodyW/2, y + 55),
             Point(x + 40,
                   y + 55 + arm),
             Scalar(0,0,0),
             4,
             LINE_AA);

        //--------------------------------
        // 다리
        //--------------------------------
        line(img,
             Point(x - 10,
                   y + headR + bodyH),
             Point(x - 20,
                   y + headR + bodyH + 40),
             Scalar(0,0,0),
             4);

        line(img,
             Point(x + 10,
                   y + headR + bodyH),
             Point(x + 20,
                   y + headR + bodyH + 40),
             Scalar(0,0,0),
             4);

        //--------------------------------
        // 최고점 효과
        //--------------------------------
        if (jumpHeight > 140)
        {
            putText(img,
                    "WOW!",
                    Point(x - 40,
                          y - 70),
                    FONT_HERSHEY_DUPLEX,
                    1,
                    Scalar(255,0,255),
                    2);

            for (int i = 0; i < 8; i++)
            {
                double a = i * CV_PI / 4;

                Point p(
                    x + cos(a) * 60,
                    y + sin(a) * 60);

                line(img,
                     Point(x,y),
                     p,
                     Scalar(0,255,255),
                     2);
            }
        }

        //--------------------------------
        // 착지 먼지 효과
        //--------------------------------
        if (phase > 58 && phase < 66)
        {
            for (int i = 0; i < 12; i++)
            {
                int dx = (i - 6) * 12;

                circle(img,
                       Point(x + dx,
                             395 - abs(dx)/8),
                       5,
                       Scalar(180,180,180),
                       FILLED,
                       LINE_AA);
            }
        }

        //--------------------------------
        // 제목
        //--------------------------------
        putText(img,
                "JUMP CHARACTER",
                Point(220,50),
                FONT_HERSHEY_DUPLEX,
                1.2,
                Scalar(50,50,50),
                2);

        imshow("Jump Animation", img);

        if (waitKey(16) == 27)
            break;

        t++;
    }

    destroyAllWindows();
    return 0;
}