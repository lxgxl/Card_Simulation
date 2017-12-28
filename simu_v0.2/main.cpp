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

void addText(Mat &draw)
{
    //采用二维数组存放花色名称
    char suit[rows][10] = {"Hearts", "Diamonds", "Clubs", "Spades"};

    for(int i = 0; i < 4; i++)
    {
        putText(draw, suit[i],
            Point(10, up_border + card_height * (i * 5 + 4) / 5),
            FONT_HERSHEY_SCRIPT_COMPLEX,
            1,
            Scalar(rand()%256, rand()%256, rand()%256),
            1);
    }

    //初始化上端字符串
    char s[13][3] = { 0 };
    s[0][0] = 'A';
    for(int i = 1; i <= 8; i++)
    {
        s[i][0] = i + '1';
    }
    strcpy(s[9], "10");
    s[10][0] = 'J';
    s[11][0] = 'Q';
    s[12][0] = 'K';

    for(int i = 0; i < 13; i++)
    {
        putText(draw, s[i],
            Point(left_border + card_width * (i * 3 + 1) / 3, up_border * 2 / 3),
            FONT_HERSHEY_SCRIPT_COMPLEX,
            1,
            Scalar(rand()%256, rand()%256, rand()%256),
            2);
    }
}

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
    //加入字体
    addText(draw);

    imshow("扑克牌", draw);

    waitKey();
    return 0;
}