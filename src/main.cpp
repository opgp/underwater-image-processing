#include <opencv2/highgui.hpp>
#include <bits/stdc++.h>
#include "imageio.cpp"
#include "imageAlgo.cpp"

using namespace std;
using namespace cv;

int main( int argc, char** argv ) {

  Mat image = getImage(argv[1], argv[2]);



  showImage("first image", image);
  showImage("second image", image);
  waitKey(0);
  return 0;
}
