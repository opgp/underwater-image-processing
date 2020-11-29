#ifndef imageAlgo
#define imageAlgo

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
// #include "imageio.h"
#include <opencv2/xphoto/white_balance.hpp>



using namespace std;
using namespace cv;

void enhance(Mat src)
{
  // split the image into separate color planes (R G B)
  // Use vector to store multiple Mat objects
  vector<Mat> BGR;
  split(src, BGR);

  // Equalizes the histogram of a one channel image  (8UC1)
  // using Contrast Limited Adaptive Histogram Equalization.
  cv::Ptr<cv::CLAHE> clahe = cv::createCLAHE();
  clahe->setClipLimit(1);

  clahe->apply(BGR[0], BGR[0]);
  clahe->apply(BGR[1], BGR[1]);
  clahe->apply(BGR[2], BGR[2]);

  merge(BGR, src);

  // conversion to YCbCr
  cvtColor(src, src, CV_BGR2YCrCb);;

  //Splitting of YCbCr
  vector<Mat> ycbcr;
  split(src, ycbcr);


  clahe->setClipLimit(1);

  //Applying Clahe on Y channel
  clahe->apply(ycbcr[0], ycbcr[0]);


  merge(ycbcr, src);

  // Median Blur
  // medianBlur ( src, src, 1);

  // Conversion back to BGR
  cvtColor(src, src, CV_YCrCb2BGR);
}

void whiteBalancing(Mat src)
{
  Ptr<xphoto::WhiteBalancer> wb;
  wb = xphoto::createSimpleWB();
  wb->balanceWhite (src, src);
}

/* Put this in your main function
   enhance(src);
 */
#endif
