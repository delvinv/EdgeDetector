#include <iostream>
#include <string>
#include <opencv/cv.h>
#include <opencv/highgui.h>

using namespace std;
using namespace cv;

int Threshold = 0;
double ThresholdD = 0.0;
int LowThreshold = 60;
int HighThreshold = 200;

void on_Detect_thresh_change(int x,void *p)
{
    Threshold = x;
    ThresholdD = (double) x/100;
}
void on_Canny_low_change(int x,void *p)
{
    LowThreshold = x;
}
void on_Canny_high_change(int x,void *p)
{
    HighThreshold = x;
}

int main(int argc, char** argv)
{
    char* elem = 0;
    if (argc >1){
        elem = argv[1];
    } else {
        elem = "0";
    }

    //"C:\Users\User\Documents\GitHub\EdgeDetector\EdgeD\test_sphere_1.mp4"

    VideoCapture cap(elem); // open the video file for reading
    if ( !cap.isOpened() )  // if not success
    {
        cout << "runnning from web cam" << endl;
        VideoCapture cap(1);
    }

    namedWindow("Window",CV_WINDOW_AUTOSIZE);
    createTrackbar( "Detect_thresh" ,"Window" ,&Threshold        ,100 ,on_Detect_thresh_change   );
    createTrackbar( "Canny_low"     ,"Window" ,&LowThreshold     ,255 ,on_Canny_low_change       );
    createTrackbar( "Canny_high"    ,"Window" ,&HighThreshold    ,255 ,on_Canny_high_change      );

    Mat frame;
    Mat gray;

    while(1) {
        bool bSuccess = cap.read(frame); // read a new frame from video

        if (!bSuccess) { //if not success, break loop
            cout << "Cannot read the frame from video file" << endl;
            break;
        }

                // === First the circle detection ===

        cvtColor(frame, gray, CV_BGR2GRAY);
        // smooth it, otherwise a lot of false circles may be detected
        blur( gray, gray, Size(3,3) );
        vector<Vec3f> circles;
        HoughCircles(gray, circles, CV_HOUGH_GRADIENT,
                     2, 100, HighThreshold, LowThreshold, 30, 3000 );

                // === Then the canny edge ditection ===

        // Reduce noise with a kernel 3x3
        blur( frame, frame, Size(3,3) );
        // Canny detector
        Canny( frame, frame, LowThreshold, HighThreshold, 3 );

                // === Plotting the circles on the canny ===

        for( int i = 0; i < circles.size(); i++ ) {
            Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
            int radius = cvRound(circles[i][2]);
            // draw the circle outline
            circle( frame, center, radius, Scalar(255,255,255), 3, 8, 0 );
        }

        // dysplay the frame
        imshow("Window", frame );

                // === Key commands ===

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
