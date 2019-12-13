#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/ioctl.h>

#include "sample_nnie_main.h"


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




static char **s_ppChCmdArgv = NULL;

/******************************************************************************
* function : show usage
******************************************************************************/
void SAMPLE_SVP_Usage(char* pchPrgName)
{
    printf("Usage : %s <index> \n", pchPrgName);
    printf("index:\n");
    printf("\t 0) RFCN(VI->VPSS->NNIE->VGS->VO).\n");
    printf("\t 1) Segnet(Read File).\n");
    printf("\t 2) FasterRcnnAlexnet(Read File).\n");
    printf("\t 3) FasterRcnnDoubleRoiPooling(Read File).\n");
    printf("\t 4) Cnn(Read File).\n");
    printf("\t 5) SSD(Read File).\n");
    printf("\t 6) Yolov1(Read File).\n");
    printf("\t 7) Yolov2(Read File).\n");
    printf("\t 8) Yolov3(Read File).\n");
    printf("\t 9) LSTM(Read File).\n");
    printf("\t a) Pvanet(Read File).\n");
}



int test_opencv()
{
    Mat img = imread("./data/imgs/cat.jpg");
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

    imwrite("./out/canny.jpg",edge);

    IMG_SHOW("canny", edge);
    WAIT_KEY(0);

    return 0;

}



int main(int argc, char *argv[])
{
    int s32Ret = HI_SUCCESS;

    cout<< "entering main\n";
    if (argc < 2)
    {
        SAMPLE_SVP_Usage(argv[0]);
        return HI_FAILURE;
    }
    s_ppChCmdArgv = argv;
 
    cout << "opencv testing...\n";
    test_opencv();		//测试opencv
    cout << "nnie testing ...\n";
    switch (*argv[1])
    {
        case '0':
            {
                SAMPLE_SVP_NNIE_Rfcn();
            }
            break;
        case '1':
            {
                SAMPLE_SVP_NNIE_Segnet();
            }
            break;
        case '2':
            {
                SAMPLE_SVP_NNIE_FasterRcnn();
            }
            break;
        case '3':
            {
                SAMPLE_SVP_NNIE_FasterRcnn_DoubleRoiPooling();
            }
            break;
        case '4':
            {
                SAMPLE_SVP_NNIE_Cnn();
            }
            break;
        case '5':
            {
                SAMPLE_SVP_NNIE_Ssd();
            }
            break;
        case '6':
            {
                SAMPLE_SVP_NNIE_Yolov1();
            }
            break;
        case '7':
            {
                SAMPLE_SVP_NNIE_Yolov2();
            }
            break;
        case '8':
            {
                SAMPLE_SVP_NNIE_Yolov3();
            }
            break;
        case '9':
            {
                SAMPLE_SVP_NNIE_Lstm();
            }
            break;
        case 'a':
	       {
		       SAMPLE_SVP_NNIE_Pvanet();
	       }
	       break;
        default :
            {
                SAMPLE_SVP_Usage(argv[0]);
            }
            break;
    }

    return s32Ret;
}



