#include "draw.h"
#include<stdio.h>
bool draw::draw(std::string path,std::string outpath,double x,double y,double x2,double y2)
{
  Mat img;
	img = imread(path);
	Rect RectangleToDraw(x, y,x2-x, y2-y);
	rectangle(img, RectangleToDraw.tl(), RectangleToDraw.br(), Scalar(0, 0, 255), 2, 8, 0);
	imwrite(outpath,img);
	return 1;
}
Napi::Boolean draw::HocrWrapper(const Napi::CallbackInfo &info)
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
    return Napi::Boolean::New(env,draw::draw(path.ToString(),outpath.ToString(),x.DoubleValue(),y.DoubleValue(),x2.DoubleValue(),y2.DoubleValue()));
}
Napi::Object draw::Init(Napi::Env env,Napi::Object exports)
{
     exports.Set("draw",Napi::Function::New(env,draw::HocrWrapper));
     return exports;
}