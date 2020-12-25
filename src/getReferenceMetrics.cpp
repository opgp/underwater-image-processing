#include <opencv2/highgui.hpp>
#include <bits/stdc++.h>
#include "imageio.h"
#include "imageAlgo.h"
#include "imageEvaluate.h"
#include <dirent.h>

using namespace std::chrono;
using namespace std;
using namespace cv;

const string referenceImages = "./dataset/reference/";
const string rawImages = "./dataset/results/";


int main( int argc, char** argv ) {
  // Take input of image
  string imagePath = argv[1];
  vector <string> files = getFileNames (argv[1]);

  double mse = 0.0, psnr = 0.0, ssim = 0.0;
  int totalImages = 0;
  for (auto img: files)
  {
    int flag1 = 0,flag2 = 0;
    totalImages++;
    vector<string> cur = ReferenceMetrics(referenceImages+img,rawImages+img);
    // cout<<referenceImages+img<<" "<<rawImages+img<<endl;
    for(auto str:cur) {
      replace(str.begin(),str.end(),'(',' ');
      replace(str.begin(),str.end(),',',' ');
      replace(str.begin(),str.end(),')',' ');
      stringstream ss(str);
      string type, waste;
      double value;
      ss>>type>>waste>>value;
      if(flag1 == 0 && flag2 == 0) {
        mse += value;
        flag1 = 1;
      } else if(flag1 == 1 && flag2 == 0) {
        psnr += value;
        flag2 = 1;
      } else {
        ssim += value;
        flag1 = 0;
        flag2 = 0;
      }
      cout<<str<<" "<<type<<" "<<value<<endl;
    }
    cout<<"completed "<<totalImages<<" out of "<<files.size()<<endl;
  }
  cout<<"mse"<<" : "<<mse/totalImages<<endl;
  cout<<"psnr"<<" : "<<psnr/totalImages<<endl;
  cout<<"ssim"<<" : "<<ssim/totalImages<<endl;
  return 0;
}
