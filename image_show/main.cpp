#include <cv.h>
#include <highgui.h>

int main(int argc, char *argv[])
{
    IplImage* pImg;
    pImg=cvLoadImage("E:/opencv/project/edge_detection/hand.jpg",1);//iscolor是一个辅助参数项，可选正数、零和负数三种值，正数表示作为三通道图像载入，零表示该图像作为单通道图像，负数表示载入图像的通道数由图像文件自身决定。
    //pImg=cvLoadImage("C:/Users/Public/Pictures/Sample Pictures/4.jpg",CV_LOAD_IMAGE_ANYCOLOR | CV_LOAD_IMAGE_ANYDEPTH);//图像原始状态显示
    cvNamedWindow("Image",1);
    //cvNamedWindow("Image",0);
    //cvResizeWindow("Image",250,250);
    cvShowImage("Image",pImg);
    cvWaitKey(0);//没有的话，程序直接执行下一步，看不到图像显示；e.g.cvWaitKey(50)：图像显示50ms。
    cvDestroyWindow("Image");
    cvReleaseImage(&pImg);
    return 0;
}
