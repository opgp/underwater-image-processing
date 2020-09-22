#include <opencv2/highgui.hpp>
#include <bits/stdc++.h>
#include "imageio.cpp"

using namespace std;
using namespace cv;

int main( int argc, char** argv ) {

  Mat image = getImage(argv[1], argv[2]);

  namedWindow( "OpenCV main", WINDOW_AUTOSIZE );
  imshow( "OpenCV main", image );
  waitKey(0);

  return 0;
}
