
#include <cv.h>
#include <highgui.h>

int main()
{
    cvNamedWindow("Video", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Gray", CV_WINDOW_AUTOSIZE);
    cvNamedWindow("Canny", CV_WINDOW_AUTOSIZE);

    CvCapture *capture = cvCreateFileCapture("E:/opencv/project/video_hand_edge_detection/2.avi");

    IplImage *frame;
    IplImage *desc;
    CvSize sz;
    double scale=0.5;

    IplImage *frame_gray;
    IplImage *frame_canny;
    IplImage *frame_gray_desc;
    IplImage *frame_canny_desc;


    frame = cvQueryFrame(capture);
    frame_gray = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 1);
    frame_canny = cvCreateImage(cvGetSize(frame), IPL_DEPTH_8U, 1);

    while(1)
    {
        if(!frame)
        {
            break;
        }

        sz.width = frame->width*scale;
        sz.height = frame->height*scale;
        desc = cvCreateImage(sz,frame->depth,frame->nChannels);
        cvResize(frame,desc,CV_INTER_CUBIC);

        cvConvertImage(frame, frame_gray, 1);
        cvCanny(frame_gray, frame_canny, 10, 100, 3);

        frame_gray_desc = cvCreateImage(sz,frame_gray->depth,frame_gray->nChannels);
        frame_canny_desc= cvCreateImage(sz,frame_canny->depth,frame_canny->nChannels);

        cvResize(frame_gray,frame_gray_desc,CV_INTER_CUBIC);
        cvResize(frame_canny,frame_canny_desc,CV_INTER_CUBIC);

        cvShowImage("Video", desc);
        cvShowImage("Gray", frame_gray_desc);
        cvShowImage("Canny", frame_canny_desc);

        char c = cvWaitKey(33);
        if (c == 27)
        {
            break;
        }
        frame = cvQueryFrame(capture);
    }

    cvReleaseCapture(&capture);

    cvDestroyAllWindows();

    return 0;
}
