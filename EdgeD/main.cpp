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

int main(int argc, char** argv)
{
    if (argc <2){
        cout << argc <<endl;
        cout << "ERROR: Video argument missing." <<endl;
        return -1;
    }
    VideoCapture cap(argv[1]); // open the video file for reading
    if ( !cap.isOpened() )  // if not success, exit program
    {
        cout << "Cannot open the video file" << endl;
        return -1;
    }
    namedWindow("Window",CV_WINDOW_AUTOSIZE);

    createTrackbar( "Detect_thresh" ,"controller" ,&thresh  ,100 ,on_Detect_thresh_change   ,&image);
    createTrackbar( "Canny_low"     ,"controller" ,&low     ,255 ,on_Canny_low_change       ,&image);
    createTrackbar( "Canny_high"    ,"controller" ,&high    ,255 ,on_Canny_high_change      ,&image);

    while(1)
    {
        k = waitKey();
        if (k==32){    // 32 is the code for 'space bar'
            pause;     // the function for pausing the video
        }
        else {
            return -1; // exits on anything that isnt pausing
        }
    }
        //nothing
}
