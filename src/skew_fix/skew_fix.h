#include<iostream>
#include <opencv2/opencv.hpp>

namespace skew_fix{
void hough_transform(cv::Mat& im, cv::Mat& orig, double* skew);
cv::Mat preprocess1(cv::Mat& im);
cv::Mat preprocess2(cv::Mat& im);
cv::Mat rot(cv::Mat& im, double thetaRad);

}
