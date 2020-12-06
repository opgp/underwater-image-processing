#ifndef imageio
#define imageio

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <bits/stdc++.h>
#include <debug.h>

using namespace std;
using namespace cv;

Mat getImage (char* imgNum, char* type, bool color = 1)
{
  string imagePath = "./dataset/" + string(type) + "/" + string(imgNum) + ".png";
  Mat image = imread (imagePath);

  if(image.empty()) {
    cout << "Image not found or unable to open at " << imagePath << endl;
    exit(-1);
  }
  
  // resize (image, image, Size(640, 480), 0, 0, INTER_CUBIC);

  return image;
}


void showImage (string name, Mat image)
{
  namedWindow( name, WINDOW_AUTOSIZE );
  imshow(name, image );
}
#endif
