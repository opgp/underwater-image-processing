//#include <stdio.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include <iostream>

using namespace cv;
using std::string;

int main(int argc, char** argv)
{
    string filename = argv[1];
    VideoCapture capture(filename);
    Mat frame;

    if( !capture.isOpened() )
        throw "Error when reading steam";

    namedWindow( "w", 1);
    for( ; ; )
    {
        capture >> frame;
        if(frame.empty())
            break;
        imshow("w", frame);
        waitKey(20); // waits to display frame
    }
    waitKey(0); // key press to close window
    // releases and window destroy are automatic in C++ interface
}
