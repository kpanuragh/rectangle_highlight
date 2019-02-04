#include<iostream>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include<opencv2/opencv.hpp>
using namespace std;

namespace fix_rotate
{
    void rotate(cv::Mat& src, double angle, cv::Mat& dst);
    cv::Mat fix_rotate(char* inputfile);
}