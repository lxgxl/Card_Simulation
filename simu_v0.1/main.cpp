#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <time.h>

using namespace std;
using namespace cv;

int main()
{
    srand(unsigned(time(NULL)));
    char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    int deck[4][13] = {0};
    int scale = 100;
    Mat draw(Size((13 + 1) * scale, 5 * scale), CV_8UC3, Scalar::all(0));

    for(int i = 1; i <= 4; i++)
    {
        putText(draw, suit[i - 1],
         Point(0, scale / 2 * (2 * i + 1)),
         FONT_HERSHEY_COMPLEX_SMALL,
         0.78,
         Scalar::all(255));
    }

    putText(draw, "A",
     Point(scale * 1 + scale / 3, scale),
     FONT_HERSHEY_PLAIN,
     3,
     Scalar(255, 255, 255),
     1, 8, false);

    for(int i = 2; i <= 9; i++)
    {
        char s[] = " ";
        s[0] = '0' + i;
        putText(draw, s,
         Point(scale * i + scale / 3, scale),
         FONT_HERSHEY_PLAIN,
         3,
         Scalar(255, 255, 255),
         1, 8, false);
    }

    putText(draw, "10",
     Point(scale * 10 + scale / 3, scale),
     FONT_HERSHEY_PLAIN,
     3,
     Scalar(255, 255, 255),
     1, 8, false);

    putText(draw, "J",
     Point(scale * 11 + scale / 3, scale),
     FONT_HERSHEY_PLAIN,
     3,
     Scalar(255, 255, 255),
     1, 8, false);
    
    putText(draw, "Q",
     Point(scale * 12 + scale / 3, scale),
     FONT_HERSHEY_PLAIN,
     3,
     Scalar(255, 255, 255),
     1, 8, false);

    putText(draw, "K",
     Point(scale * 13 + scale / 3, scale),
     FONT_HERSHEY_PLAIN,
     3,
     Scalar(255, 255, 255),
     1, 8, false);

    for(int i = 1; i <= 5; i++)
    {
        line(draw, Point(scale, scale * i - 1),
         Point(1399, scale * i - 1),
         Scalar::all(255));
    }

    for(int i = 1; i <= 14; i++)
    {
        line(draw, Point(scale * i - 1, scale),
         Point(scale * i - 1, 500),
         Scalar::all(255));
    }

    int count = 0;
    while(count <= 51)
    {
        int rows = rand() % 4;
        int cols = rand() % 13;
        if(deck[rows][cols] == 0)
        {
            deck[rows][cols] = ++count;
            char s[3] = { 0 };
            s[0] = (count / 10) ? (count / 10) + '0' : ' ';
            s[1] = count % 10 + '0';
            //rectangle(draw, Rect(Point((cols + 1) * scale, (rows + 1) *scale), Size(scale, scale)),
            // Scalar::all(127), -1);
            putText(draw, s,
             Point(scale * cols + scale * 6 / 5, scale * rows + scale * 8 / 5),
             FONT_HERSHEY_PLAIN,
             3,
             Scalar(255, 0, 0),
             3, 8, false);
            imshow("帮助理解", draw);
            waitKey(100);
        }
    }

    imshow("帮助理解", draw);

    waitKey();
    return 0;
}