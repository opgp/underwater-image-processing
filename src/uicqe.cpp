#include <opencv2/highgui.hpp>
#include <bits/stdc++.h>
#include "imageio.h"
#include "imageAlgo.h"
#include "imageEvaluate.h"
#include <dirent.h>

using namespace std::chrono;
using namespace std;
using namespace cv;

const string output = "./dataset/results/";

int main( int argc, char** argv ) {
  // Take input of image
  string imagePath = argv[1];
  vector <string> files = getFileNames (argv[1]);

  double uciqeSum = 0;
  double countImages = 0;

  for (auto img: files)
  {
    uciqeSum += getUCIQE (output + img);
    countImages++;
    cout << "\r Processing: " << img << " | " << "Completed Images (" << countImages << "/" << files.size() << ")";
  }

  cout << "Average UCIQE Value: " << uciqeSum/countImages;
 .
 
  return 0;
}
