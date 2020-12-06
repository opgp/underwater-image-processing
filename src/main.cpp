#include <opencv2/highgui.hpp>
#include <bits/stdc++.h>
#include "imageio.h"
#include "imageAlgo.h"
#include "imageEvaluate.h"

using namespace std::chrono;
using namespace std;
using namespace cv;

const string output = "./dataset/results/";

int main( int argc, char** argv ) {

  // Take input of image
  Mat image = getImage(argv[2], argv[1]);

  // Show the original image
  showImage("normal", image);
  imwrite (output + "original.png", image);

  // Start calculating time
  auto start = high_resolution_clock::now();
  ///////////////////////////////////////////////////////////////////////

  enhance (image);
  whiteBalancing(image);

  //////////////////////////////////////////////////////////////////////
  // End calculating time

  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  cout << "Time taken by function: "
       << duration.count()/1e6 << " seconds" << endl;

  showImage("enhanced", image);
  imwrite (output + "enhanced.png", image);

  uiqm(output, argv[2]);

  waitKey(0);
  return 0;
}
