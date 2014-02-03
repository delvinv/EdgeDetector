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

//    while(1)
//    {
//        if (waitKey()==32){    // 32 is the code for 'space bar'
//            //pause();     // the function for pausing the video
//            cout << "pause" <<endl;
//        }
//        else {
//            return -1; // exits on anything that isnt pausing
//        }
//    }

    Mat frame;

    while(1)
    {
        bool bSuccess = cap.read(frame); // read a new frame from video

        if (!bSuccess) //if not success, break loop
        {
            cout << "Cannot read the frame from video file" << endl;
            break;
        }

        imshow("MyVideo", frame); //show the frame in "MyVideo" window

        if(waitKey(30) == 27) //wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
        {
            cout << "esc key is pressed by user" << endl;
            break;
        }
    }
}
