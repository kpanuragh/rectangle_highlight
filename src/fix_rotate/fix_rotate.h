#include<iostream>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include<opencv2/opencv.hpp>
using namespace std;

namespace fix_rotate
{
    cv::Mat fix_rotate(char* inputfile);
}