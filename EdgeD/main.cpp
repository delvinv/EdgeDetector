#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>

using namespace std;
using namespace cv;

void on_Detect_thresh_change(int x,void *p)
{
    x; // trackbar value
    p; // pointer to a resorce
}
void on_Canny_low_change(int x,void *p)
{
    x; // trackbar value
    p; // pointer to a resorce
}
void on_Canny_high_change(int x,void *p)
{
    x; // trackbar value
    p; // pointer to a resorce
}

int main(int argc, char** argv)
{
    if (argc <2){
        cout << argc <<endl;
        cout << "ERROR: Video argument missing." <<endl;
    }
    VideoCapture cap(argv[1]); // open the video file for reading
    if ( !cap.isOpened() )  // if not success, exit program
    {
        cout << "Cannot open the video file" << endl;
        return -1;
    }

    namedWindow("Window",CV_WINDOW_AUTOSIZE);

    int thresh = 0;
    int low = 0;
    int high = 0;

    createTrackbar( "Detect_thresh" ,"Window" ,&thresh  ,100 ,on_Detect_thresh_change   );
    createTrackbar( "Canny_low"     ,"Window" ,&low     ,255 ,on_Canny_low_change       );
    createTrackbar( "Canny_high"    ,"Window" ,&high    ,255 ,on_Canny_high_change      );

    while(1)
    {
        int k = waitKey();
        if (k==32){    // 32 is the code for 'space bar'
            //pause();     // the function for pausing the video
            cout << "pause" <<endl;
        }
        else {
            return -1; // exits on anything that isnt pausing
        }
    }
}
