#include <opencv2/highgui.hpp>
#include <bits/stdc++.h>
#include "imageio.h"
#include "imageAlgo.h"

using namespace std;
using namespace cv;

int main( int argc, char** argv ) {

  Mat image = getImage(argv[2], argv[1]);

  showImage("normal", image);

  enhance (image);

  showImage("enhanced", image);
  waitKey(0);
  return 0;
}
