#include <iostream>
#include <string>
#include <opencv/cv.h>
#include <opencv/highgui.h>

using namespace std;
using namespace cv;

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
    char* elem = 0;
    if (argc >1){
        elem = argv[1];
    } else {
        elem = "0";
    }

    VideoCapture cap(elem); // open the video file for reading
    if ( !cap.isOpened() )  // if not success, exit program
    {
        VideoCapture cap(0);
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
    Mat frame;

    while(1)
    {
        bool bSuccess = cap.read(frame); // read a new frame from video

        if (!bSuccess) //if not success, break loop
        {
            cout << "Cannot read the frame from video file" << endl;
            break;
        }

        imshow("Window", frame); //show the frame in "MyVideo" window

        int k = waitKey(30);
        if(k == 32) { //wait for 'space' key press for 30 ms. Then pauses
            while(1) {
                k = waitKey();
                if (k == 32) {
                    break;
                }
                else if(k != -1) { // exits on any other key
                    return -1;
                }
            }
        }
        else if(k != -1) { // exits on any other key
            return -1;
        }
    }
    waitKey(0);
}
