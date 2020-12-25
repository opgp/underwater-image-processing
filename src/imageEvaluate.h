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

vector<string> ReferenceMetrics(string original, string reference)
{
  // Create paths for orignial and reference images

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
  vector<string> results;

  for (auto metric: metrics)
    results.push_back(execute ("sewar " + metric + " " + reference + " " + original));

  return results;
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
void getUCIQE (string imgPath)
{
  Mat img = getImage(imgPath);

  const double c1 = 0.4680;
  const double c2 = 0.2745;
  const double c3 = 0.2576;

  Mat imgLab;
  cvtColor(img, imgLab, CV_BGR2Lab);

  double chromaSum = 0;
  double chromaVairanceSum = 0;
  double saturationSum = 0;
  double pixels = 0;
  double minL = INT_MAX, maxL = 0;

  vector <vector <vector <int>>> values(imgLab.rows, vector <vector <int>> (imgLab.cols));

  for (int i = 0; i < imgLab.rows; i++)
    for (int j = 0; j < imgLab.cols; j++)
    {
      vector <int> lab = imgLab.at<vector <int>>(i,j);
      chromaSum += sqrt (lab[1]*lab[1] + lab[2]*lab[2]);

      values[i][j].emplace_back (lab);
      pixels++;

      minL = min (minL, double (lab[0]));
      maxL = max (maxL, double (lab[0]));

    }

  // Average of Chroma
  double u_c = chromaSum/pixels;

  for (int i = 0; i < imgLab.rows; i++)
    for (int j = 0; j < imgLab.cols; j++)
    {
      vector <int> lab = values[i][j];
      double chroma = sqrt (lab[1]*lab[1] + lab[2]*lab[2]);

      saturationSum += chroma/double(lab[0]);

      chromaVairanceSum += chroma * chroma - u_c*u_c;
    }

  // Variance of Chroma
  double sigma_c = sqrt (chromaVairanceSum/pixels);

  // Contrast of L channel
  double contrast_l = maxL - minL;

  // Average of Saturation
  double u_s = saturationSum/pixels;

  double UCIQE = c1 * sigma_c + c2 * contrast_l + c3 * u_s;
  return UCIQE;
}

#endif
