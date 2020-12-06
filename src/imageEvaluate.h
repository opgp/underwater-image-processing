#ifndef imageEvaluate
#define imageEvaluate
#include <bits/stdc++.h>

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
  {
      output += c;
  }

  pclose(fpipe);
  return output;
}

void rEval(char* imgName, char* type)
{
  // Create paths for orignial and reference images
  string original = "./dataset/" + string(type) + "/" + string(imgName) + ".png";
  string reference = "./dataset/reference/" + string(imgName) + ".png";

  // Metrics avalailable in sewar library
  // refer https://github.com/andrewekhalel/sewar
  vector <string> metrics = {
    "mse",
    // "rmse",
    "psnr",
    // "rmse",
    // "sw",
    // "uqi",
    // "ssim",
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

void uiqm (string path)
{
  cout << execute ("./UIQM " + path);
}

#endif
