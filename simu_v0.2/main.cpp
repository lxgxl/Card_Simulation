#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <time.h>

using namespace std;
using namespace cv;

//定义一些图形属性
const int card_width = 80;
const int card_height = 160;
const int left_border = 160;
const int up_border = 80;

const int rows = 4;
const int cols = 13;

//画方格函数
void drawPlaid(Mat &plaid)
{
    for(int i = 0; i <= cols; i++)
    {
        line(plaid, 
            Point(card_width * i, 0),
            Point(card_width * i, card_height * rows),
            Scalar::all(150),
            1);
    }

    for(int i = 0; i <= rows; i++)
    {
        line(plaid,
            Point(0, card_height * i),
            Point(card_width * cols, card_height * i),
            Scalar::all(150),
            1);
    }
}

int main()
{
    //产生随机数
    srand(unsigned(time(NULL)));
    //采用二维数组存放花色名称
    char suit[rows][10] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    //用于标记出现顺序
    int deck[rows][cols] = {0};
    
    //创建图像
    Mat draw(Size(card_width * cols + left_border, card_height * rows + up_border),
        CV_8UC3,
        Scalar::all(0));

    //创建方格区域
    Mat plaid(draw, Rect(Point(left_border, up_border), Size(card_width * cols, card_height * rows)));
    //画方格
    drawPlaid(plaid);

    imshow("扑克牌", draw);

    waitKey();
    return 0;
}