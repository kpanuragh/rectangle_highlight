#include "draw.h"
#include<stdio.h>
#include "../skew_fix/skew_fix.h"
#include "../fix_rotate/fix_rotate.h"
using namespace cv;
bool draw::draw(std::string path,std::string outpath,double x,double y,double x2,double y2,Napi::Env env)
{

// try{

	// char y[100];
	char *path_char = new char[path.length() + 1]; 
	std::strcpy(path_char, path.c_str());
	
	Mat im = fix_rotate::fix_rotate(path_char);
	cvtColor(im,im,COLOR_GRAY2RGB);
	fastNlMeansDenoisingColored(im,im);
	Mat gray;
	cvtColor(im, gray, COLOR_BGR2GRAY);
	Mat preprocessed = skew_fix::preprocess2(gray);
	double skew;
	skew_fix::hough_transform(preprocessed, im, &skew);
	Mat rotated = skew_fix::rot(im, skew* CV_PI / 180);	
	im.release();
	Mat img_new;
	try{
	cvtColor(rotated,img_new,COLOR_BGR2RGBA);
	}
	catch(cv::Exception& e)
	{
		std::cout << "here you need to validate: " << std::endl;
	}

	Rect RectangleToDraw(x, y,x2-x, y2-y);
	rectangle(img_new, RectangleToDraw.tl(), RectangleToDraw.br(), Scalar(0, 0, 255), 2, 8, 0);
	//cvtColor(rotated,rotated,COLOR_GRAY2RGB);

	imwrite(outpath,img_new);
	rotated.release();
	gray.release();
	return 1;
	// 	}
	// 	catch(cv::Exception& e){
	// 	  const char* err_msg = e.what();
    // 	std::cout << "exception caught: " << err_msg << std::endl;
	// 	Napi::Error::New(env,e.what()).ThrowAsJavaScriptException();
	// 	return 0;
	// }
}
Napi::Boolean draw::HocrWrapper(const Napi::CallbackInfo &info)
{
	try
	{
    Napi::Env env=info.Env();
    if(info.Length() < 1)
    {
        Napi::TypeError::New(env, "Path Expected").ThrowAsJavaScriptException();
    }
    Napi::String path=info[0].As<Napi::String>();
	Napi::String outpath=info[1].As<Napi::String>();
	Napi::Number x=info[2].As<Napi::Number>();
	Napi::Number y=info[3].As<Napi::Number>();
	Napi::Number x2=info[4].As<Napi::Number>();
	Napi::Number y2=info[5].As<Napi::Number>();
    return Napi::Boolean::New(env,draw::draw(path.ToString(),outpath.ToString(),x.DoubleValue(),y.DoubleValue(),x2.DoubleValue(),y2.DoubleValue(),env));
		}
		catch(cv::Exception& e){
		  const char* err_msg = e.what();
    	std::cout << "exception caught: " << err_msg << std::endl;
		Napi::Error::New(info.Env(),e.what()).ThrowAsJavaScriptException();
		
	}
}
Napi::Object draw::Init(Napi::Env env,Napi::Object exports)
{
     exports.Set("draw",Napi::Function::New(env,draw::HocrWrapper));
     return exports;
}