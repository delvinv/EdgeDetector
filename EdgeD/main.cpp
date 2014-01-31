#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>

using namespace std;

void on_Detect_thresh_change(int x,void *p)
{

}
void on_Canny_low_change(int x,void *p)
{

}
void on_Canny_high_change(int x,void *p)
{

}

int main()
{
    namedWindow("Window",CV_WINDOW_AUTOSIZE);

    createTrackbar( "Detect_thresh"    ,"controller" ,&thresh   ,100 ,on_Detect_thresh_change   ,&image);
    createTrackbar( "Canny_low"      ,"controller" ,&low ,255 ,on_Canny_low_change  ,&image);
    createTrackbar( "Canny_high"  ,"controller" ,&high ,255 ,on_Canny_high_change    ,&image);
}
