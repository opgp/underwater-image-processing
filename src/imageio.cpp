#include <opencv2/highgui.hpp>
#include <bits/stdc++.h>
#include <debug.h>

using namespace std;
using namespace cv;

Mat getImage (char* imgNum, char* type, bool color = 1)
{
  string imagePath = "./dataset/" + string(type) + "/" + string(imgNum) + ".png";
  Mat image = imread (imagePath, IMREAD_COLOR);

  if(image.empty()) {
    cout << "Image not found or unable to open at " << imagePath << endl;
    exit(-1);
  }

  return image;
}

void showImage (string name, Mat image)
{
  namedWindow( name, WINDOW_AUTOSIZE );
  imshow(name, image );
}
