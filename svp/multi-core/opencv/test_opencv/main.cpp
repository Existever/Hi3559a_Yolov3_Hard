
#include<iostream>
#include<opencv2/opencv.hpp>   

using namespace std;
using namespace cv;


//海思编译不能使用GTK，导致无法使用imshow这个函数，使用宏定义作为一个开关功能
//#define WITH_GTK

#ifdef WITH_GTK
#define IMG_SHOW(des,img) imshow(des,img)
#define WAIT_KEY(t) waitKey(t)
#else
#define IMG_SHOW(des,img) printf("[imshow] without GTK only print window name:%s\n",des)
#define WAIT_KEY(t)  printf("[waitKey] without GTK only print time:%d\n",t)
#endif


//边缘检测
int main()
{
    Mat img = imread("cat.jpg");
    //imshow("原始图", img);   //没有gtk不能imshow
    Mat DstPic, edge, grayImage;

    //创建与src同类型和同大小的矩阵
    DstPic.create(img.size(), img.type());

    //将原始图转化为灰度图
    cvtColor(img, grayImage, COLOR_BGR2GRAY);

    //先使用3*3内核来降噪
    blur(grayImage, edge, Size(3, 3));

    //运行canny算子
    Canny(edge, edge, 3, 9, 3);

    imwrite("canny.jpg",edge);

    IMG_SHOW("边缘提取效果", edge);
    WAIT_KEY(0);

    return 0;

}
