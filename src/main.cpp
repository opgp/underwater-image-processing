#include <opencv2/highgui.hpp>
#include <bits/stdc++.h>
#include "imageio.h"
#include "imageAlgo.h"
#include "imageEvaluate.h"

using namespace std::chrono;
using namespace std;
using namespace cv;

int main( int argc, char** argv ) {

  Mat image = getImage(argv[2], argv[1]);

  auto start = high_resolution_clock::now();

  showImage("normal", image);
  imwrite ("original.png", image);

  enhance (image);
  showImage("not White balanced", image);

  whiteBalancing(image);

  imwrite ("whiteBalanced.png", image);

  auto stop = high_resolution_clock::now();

  auto duration = duration_cast<microseconds>(stop - start);

  cout << "Time taken by function: "
       << duration.count() << " microseconds" << endl;
  showImage("enhanced", image);

  waitKey(0);
  return 0;
}
