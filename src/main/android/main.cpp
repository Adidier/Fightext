#include "KGameManager.h"
#include "IntroState.h"
#include "platform/android/jni/JniHelper.h"
#include <jni.h>
#include <android/log.h>

#include "cocos2d.h"
#include "KGameManager.h"
#include "IntroState.h"

#define  LOG_TAG    "main"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
// LOGD("cocos_android_app_init");
using namespace cocos2d;

void cocos_android_app_init (JNIEnv* env, jobject thiz) {

__android_log_print(ANDROID_LOG_ERROR, "MyTag", "The value is %d", 1);
    LOGD("cocos_android_app_init");
    
	KGameManager * kGameManager = KGameManager::getSingletonPtr();
	try
	{
		kGameManager->StartGame( IntroState::getSingletonPtr() );
	}
	catch (...)
	{
		LOGD("ERROR MAIN KALIUM");
		return ;
	}
}
