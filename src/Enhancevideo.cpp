#include "opencv2/opencv.hpp"
#include "imageAlgo.h"
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char** argv){

  // Create a VideoCapture object and open the input file
  // If the input is the web camera, pass 0 instead of the video file name
  VideoCapture cap(argv[1]);

  // Check if camera opened successfully
  if(!cap.isOpened()) {
    cout << "Error opening video stream or file" << endl;
    return -1;
  }

  while(1) {

    Mat frame;
    // Capture frame-by-frame
    cap >> frame;

    // If the frame is empty, break immediately
    if (frame.empty())
      break;

    resize (frame, frame, Size(640, 480), 0, 0, INTER_CUBIC);
    // Display the resulting frame
    imshow( "Original", frame );

    // Algorithm
    enhance (frame);
    whiteBalancing(frame);

    imshow( "Enhanced", frame );

    // Press  ESC on keyboard to exit
    char c = (char) waitKey(25);
    if(c == 27)
      break;
  }

  // When everything done, release the video capture object
  cap.release();

  // Closes all the frames
  destroyAllWindows();

  return 0;
}
