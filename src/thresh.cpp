#include <opencv2/highgui.hpp>
#include <bits/stdc++.h>
#include "imageio.h"
#include "imageAlgo.h"

using namespace std;
using namespace cv;
string imagepath;
int main(int argc, char** argv){
    imagepath  = argv[1];
    Mat image = getImage(imagepath);
    Mat drawbefore, drawafter;
    
  Mat before, after;
    drawbefore = image;
    medianBlur(image, before, 3);
    cvtColor( before, before, COLOR_BGR2GRAY );
     
  enhance (image);
  whiteBalancing(image);
    drawafter = image;
    medianBlur(image, after, 3);
       cvtColor( after, after, COLOR_BGR2GRAY );
      
           threshold( before, before, 1,255, THRESH_OTSU  );
           //adaptiveThreshold(before, before, 255, BORDER_CONSTANT, THRESH_BINARY, 3, 0);
    imshow( "before", before );

threshold( after, after, 1,255, THRESH_OTSU  );

//adaptiveThreshold(after, after, 255, BORDER_CONSTANT, THRESH_BINARY, 3, 0);
    imshow( "after", after );
    vector<vector<Point> > cntbef, cntaf;

    findContours(before, cntbef, RETR_TREE, CHAIN_APPROX_NONE);
    findContours(after, cntaf, RETR_TREE, CHAIN_APPROX_NONE);
    drawContours(drawbefore, cntbef, -1, (255,0,0), 3);
    drawContours(drawafter, cntbef, -1, (255,0,0), 3);
    imshow( "AfterThresh", drawafter );    
    imshow( "beforeThresh", drawbefore );
  waitKey(0);
  return 0;

}