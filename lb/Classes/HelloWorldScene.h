#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

//务必引入以下2个.h文件
#include "ui/UIVideoPlayer.h"
#include "ui/CocosGUI.h"

#include "network/HttpClient.h"
using namespace cocos2d::network;

class HelloWorld : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	void onHttpRequest(std::string type);
	//void onHttpResponse(HttpClient* sender, HttpResponse* response);
	//void onHttpRequestCompleted(HttpClient *sender, HttpResponse *response);
	void videoPlayOverCallback();
	void showVideo();
	/**
	22.
	* 视频播放状态，只有在android和ios平台有效
	23.
	*/
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	void videoEventCallback(Ref* sender, cocos2d::experimental::ui::VideoPlayer::EventType eventType);
	#endif

	void connectTest();
};

#endif // __HELLOWORLD_SCENE_H__
