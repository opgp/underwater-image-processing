#include <opencv2/highgui.hpp>
#include <bits/stdc++.h>
#include "imageio.h"
#include "imageAlgo.h"
#include "imageEvaluate.h"

using namespace std::chrono;
using namespace std;
using namespace cv;

const string output = "./dataset/results/";
string imagePath;

int main( int argc, char** argv ) {

  // Take input of image
  imagePath = argv[1];
  Mat image = getImage(imagePath);

  // Show and write original image
  showImage("normal", image);

  // Start calculating time
  auto start = high_resolution_clock::now();

  // Algorithm
  enhance (image);
  whiteBalancing(image);

  // End calculating time
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
  cout << "Time taken by function: "
       << duration.count()/1e6 << " seconds" << endl;

  // Show and write Final image
 showImage("enhanced", image);
 
  // EVALUATIONS
  // uiqm(output);
  // rEval();
  // ReferenceMetrics();
  waitKey(0);
  return 0;
}
