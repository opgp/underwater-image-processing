#ifndef imageEvaluate
#define imageEvaluate
#include <bits/stdc++.h>
#include "imageio.h"


using namespace std;

string execute(string str)
{
  FILE *fpipe;
  // Convert string to char*
  char *command = const_cast <char*> (str.c_str());
  char c = 0;

  // Opening a pipe with given command
  if (0 == (fpipe = (FILE*)popen(command, "r")))
  {
      perror("popen() failed.");
      exit(EXIT_FAILURE);
  }

  // Reading std output and storing in a string
  string output;
  while (fread(&c, sizeof c, 1, fpipe))
      output += c;

  pclose(fpipe);
  return output;
}

void ReferenceMetrics()
{
  // Create paths for orignial and reference images
  string original = "./dataset/results/original.png";
  string reference = "./dataset/results/reference.png";

  // Metrics avalailable in sewar library
  // refer https://github.com/andrewekhalel/sewar
  vector <string> metrics = {
    "mse",
    // "rmse",
    "psnr",
    // "rmse",
    // "sw",
    // "uqi",
    "ssim",
    // "ergas",
    // "scc",
    // "rase",
    // "sam",
    // "msssim",
    // "vifp",
    // "psnrb"
  };

  for (auto metric: metrics)
    cout << execute ("sewar " + metric + " " + reference + " " + original) << endl;
}

string uiqm (string output)
{
  return execute ("./UIQM " + output);
}

/*
 Calculate UCIQE (Underwater Colour Image Quality Evaluation).

 Usage
      UCIQE_value = UCIQE(RGB_Image)
   The implemented algorithm is based on the paper of M. Yang et al.:
   An Underwater Color Image Quality Evaluation Metric.

  Implemented by Z. J. Wang, UAV Lab, National University of Singapore
  Sept. 2018
  Modified at Dec. 2019
*/
double getUCIQE (string imgPath)
{
  Mat img = getImage(imgPath);

  const double c1 = 0.4680;
  const double c2 = 0.2745;
  const double c3 = 0.2576;


}

#endif
