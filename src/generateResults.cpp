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

double writeImage (string imagePath, string name)
{
  Mat image = getImage(imagePath + name);

  // Start calculating time
  auto start = high_resolution_clock::now();

  // Algorithm
  enhance (image);
  whiteBalancing(image);

  // End calculating time
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);

  // Show and write Final image
  imwrite (output + name, image);

  return duration.count()/1e6;
}

vector <string> getFileNames (char* imgPath)
{
  DIR *dir; struct dirent *diread;
  vector<string> files;

  if ((dir = opendir(imgPath)) != NULL) {
    while ((diread = readdir(dir)) != NULL) {
      files.push_back(diread->d_name);
    }
    closedir (dir);
  } else {
    perror ("Directory not found!!");
    exit(1);
  }
  return files;
}

int main( int argc, char** argv ) {
  // Take input of image
  string imagePath = argv[1];
  vector <string> files = getFileNames (argv[1]);

  double totalTimeTaken = 0;
  double countImages = 0;

  for (auto img: files)
  {
    try{
      totalTimeTaken += writeImage(imagePath, img);
    }
    catch (...) {
      continue;
    }
    countImages++;
    cout << "\r Processing: " << img << " | " << "Completed Images (" << countImages << "/" << files.size() << ")";
  }

  cout << "\n Average Runtime: " << totalTimeTaken/countImages << endl;

  return 0;
}
