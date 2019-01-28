#include<napi.h>
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
namespace draw{
    bool draw(std::string path,std::string outpath,double x,double y,double x2,double y2);
    Napi::Boolean HocrWrapper(const Napi::CallbackInfo &info);
    Napi::Object Init(Napi::Env env,Napi::Object exports);
    void hough_transform(cv::Mat& im, cv::Mat& orig, double* skew);
}