#include <napi.h>
#include "draw/draw.h"
using namespace cv;
Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
	return draw::Init(env,exports);
}

NODE_API_MODULE(tessractnative, InitAll)