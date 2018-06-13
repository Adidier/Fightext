#ifndef  _PLATFORM_H_
#define  _PLATFORM_H_


class KPlatform 
{
public:
	KPlatform();
	virtual ~KPlatform();
    virtual bool applicationDidFinishLaunching();
    /**
    @brief  The function be called when the application enter background
    @param  the pointer of the application
    */
    virtual void applicationDidEnterBackground();

    /**
    @brief  The function be called when the application enter foreground
    @param  the pointer of the application
    */
    virtual void applicationWillEnterForeground();

  

    int getHeightScreen();
    int getWidthScreen();


    float getHeightScale();
    float getWidthScale();

    void setSizeResourceBackgruound(int fHeight,int fWidth);
private:
	bool bFullScreen;
	int iHeightScreen;
	int iWidthScreen;

	int iResourceHeight;
	int iResourceWidth;
}; 
#endif 
