#include <cv.h>
#include <highgui.h>


IplImage* doCanny(IplImage* in, double lowThresh, double highThresh, double aperture)
{
    if(in->nChannels != 1)
            return (0);
    IplImage* out=cvCreateImage(cvGetSize(in),IPL_DEPTH_8U,1);
    cvCanny(in,out,lowThresh,highThresh,aperture);
    return(out);
}

int main(int argc, char** argv)
{
    IplImage* img_rgb=cvLoadImage("E:/opencv/project/edge_detection/hand.jpg");
    IplImage* img_gry=cvCreateImage(cvSize(img_rgb->width, img_rgb->height),img_rgb->depth, 1);
    cvCvtColor(img_rgb, img_gry, CV_RGB2GRAY);
    cvNamedWindow("Window_gray",0);
    cvNamedWindow("Window_canny",0);
    cvShowImage("Window_gray",img_gry);
    IplImage* img_canny=doCanny(img_gry,60,120,3);
    cvShowImage("Window_canny",img_canny);
    cvWaitKey(0);
    cvReleaseImage(&img_rgb);
    cvReleaseImage(&img_gry);
    cvReleaseImage(&img_canny);
    cvDestroyWindow("Window_gry");
    cvDestroyWindow("Window_canny");
}
