#include "KMacros.h"
#include "KPlatform.h"

using namespace std;

#define  LOG_TAG    "main"


KPlatform::KPlatform() {

	iResourceHeight=800;
	iResourceWidth=480; //resolution by default
}

KPlatform::~KPlatform() 
{
}

bool KPlatform::applicationDidFinishLaunching() {

    return true;
}


int KPlatform::getHeightScreen(){
	return 1;
}

void KPlatform::setSizeResourceBackgruound(int fHeight,int fWidth){
	iResourceHeight=fHeight;
	iResourceWidth=fWidth;
}

int getWidthScreen(){
	return 1;
}

float KPlatform::getHeightScale(){
	return 1;
}

float KPlatform::getWidthScale(){
	return 1;

}


// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void KPlatform::applicationDidEnterBackground() {
  //  SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}


void KPlatform::applicationWillEnterForeground() {
    //SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
