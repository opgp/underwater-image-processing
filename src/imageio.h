#ifndef imageio
#define imageio

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <bits/stdc++.h>

using namespace std;
using namespace cv;

string extractImageName (string path)
{
  int n = path.size();
  string name;
  for (int i = n-1; i >= 0 && path[i] != '/'; i--)
    name.push_back(path[i]);
  reverse (name.begin(), name.end());
  return name;
}

Mat getImage (string imagePath, bool color = 1)
{
  Mat image = imread (imagePath);

  if(image.empty()) {
    cout << "Image not found or unable to open at " << imagePath << endl;
    exit(-1);
  }

  resize (image, image, Size(640, 480), 0, 0, INTER_CUBIC);

  return image;
}

void showImage (string path, Mat image)
{
  string name = extractImageName (string(path));
  namedWindow( name, WINDOW_AUTOSIZE );
  imshow(name, image );
}
#endif
