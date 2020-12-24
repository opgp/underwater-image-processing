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

void rEval()
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

void updateReferenceImage(string path, string output)
{
  string imgName = extractImageName(path);
  string referenceImage = "./dataset/reference/" + imgName;
  execute ("cp " + referenceImage + " " + output + "reference.png");
}


void uiqm (string output)
{
  cout << execute ("./UIQM " + output);
}

#endif
