# Fast Underwater Image Enhancement
Underwater image enhancement written in C++ for real time and online applications.

## Dependencies
OpenCV 3.2.0
### Python Dependencies
```
pip install sewar
```
## Setup
Run the following command on your terminal
```
git clone git@github.com:opgp/underwater-image-processing.git
echo "alias oc=\"g++ main.cpp -std=c++11 \`pkg-config --cflags --libs opencv\` && time ./a.out\"" >> ~/.bashrc
mkdir src/dataset/raw src/dataset/reference src/dataset/challenging src/dataset/results

```

### Dataset 
UIEB Dataset based on [this paper](http://https://ieeexplore.ieee.org/document/8917818 "this paper")  is used for benchmarking.
Download Raw Images from [here](http://https://drive.google.com/open?id=12W_kkblc2Vryb9zHQ6BfGQ_NKUfXYk13 "here").
Download Challenging Images from [here](https://drive.google.com/open?id=1Ew_r83nXzVk0hlkfuomWqsAIxuq6kaN4http:// "here").
Download Reference Images from [here](http://https://drive.google.com/open?id=1cA-8CzajnVEL4feBRKdBxjEe6hwql6Z7 "here").

Extract the zip files into their respective folders in src/dataset.
## Executing
### Enhancing an Image
```
oc <path to image> 
```
### Example
After downloading the datasets.
```
oc dataset/raw/2_img_.png
```
### Evaluation
Coming soon
