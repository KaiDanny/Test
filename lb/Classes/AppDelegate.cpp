#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "MainScene.h"
#include "GameManager.h"
//#include "LoadGameCfg.h"
#include "LoadScene.h"
#include "Protocal.h"
#include "SimpleAudioEngine.h" 

#include <stdio.h>
#include "ODSocket.h"
#include <thread>
#include <iostream>
#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/android/jni/JniHelper.h"
#include <jni.h>
#endif
using namespace CocosDenshion;
using namespace cocos2d;
USING_NS_CC;
struct PcMac{ 
	char strId[32]; 
	int win_percent;
}; 

//struct UsrData{ 
//
//	char name[16]; 
//	char password[16]; 
//
//}; 
//char buffer[1024]; 

PcMac pcMac; 
//void runHttpThread();
int msgType;
std::string str_pcMacStr;
//bool isSendMsgPcMacStr;
ODSocket cSocket;

//CRITICAL_SECTION cs;//可以理解为锁定一个资源

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::create("My Game");
        director->setOpenGLView(glview);
		glview->setFrameSize(1280.0f, 720.0f);
    }
	glview->setDesignResolutionSize(1920.0f, 1080.0f, ResolutionPolicy::SHOW_ALL);

    // turn on display FPS
//    director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);
	//------------------

	//InitializeCriticalSection(&cs);

	//LoadGameCfg *loadGameCfg = LoadGameCfg::createLoadGameCfg("datas/gamecfg.plist");
 //   loadGameCfg->readLevelInfo();
	GameManager::getInstance()->readData();
//	GameManager::getInstance()->isFinishBetOn = false;
	GameManager::getInstance()->isOpenBigAward = false;
	//-----------------
	cSocket.Init();
	cSocket.Create(AF_INET,SOCK_STREAM,0);
	cSocket.Connect(LOGIN_SERVER_IP,LOGIN_SERVER_PORT);
	getThePcMacStrFromServer();	
	//------------------
	std::thread t1(&AppDelegate::runHttpThread,this);
	t1.detach();

	//GameManager::getInstance()->initVecCardLine();
    // create a scene. it's an autorelease object
    //auto scene = MainScene::create();
	auto scene = LoadScene::create();
	//auto scene = HelloWorld::createScene();
    // run
    director->runWithScene(scene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();
    SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
    SimpleAudioEngine::getInstance()->pauseAllEffects();
    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();
    SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
    SimpleAudioEngine::getInstance()->resumeAllEffects();
    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}
void AppDelegate::runHttpThread()
{

    while(1)  
    {  
		checkRecvMsgFromServer();
		//if(isSendMsgPcMacStr)
		//{
		//	isSendMsgPcMacStr = false;
		//	 //发送数据  
		//	
		//   // int iSend = send(sockConn, buf, sizeof(buf) , 0);  
		//	memcpy( &sendBuf, &msgGetPcMacAdress, sizeof(msgGetPcMacAdress) );
		//	memcpy( &sendBuf[sizeof(msgGetPcMacAdress) + 1], &pcMac, sizeof(pcMac) );
		//	cSocket.Send(sendBuf,sizeof(sendBuf),0);  
		//}
    }  
}

void AppDelegate::readPcMacStr()
{
	//if(GameManager::getInstance()->pcMacStr.compare(defaultPcMacStr)==0)
	//if(0 == strcmp(GameManager::getInstance()->pcMacStr.c_str(), defaultPcMacStr.c_str()))
	//{
		getThePcMacStr();
		pcMac.win_percent = GameManager::getInstance()->win_percent;
		//GameManager::getInstance()->pcMacStr = str_pcMacStr;
		//GameManager::getInstance()->saveData();
		//isSendMsgPcMacStr = true;
	//	return true;
	//}
	//isSendMsgPcMacStr = false;
//	return false;
}

void AppDelegate::getThePcMacStr()
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) //判断当前是否为Android平台 
    JniMethodInfo minfo;//定义Jni函数信息结构体 
    //getStaticMethodInfo 次函数返回一个bool值表示是否找到此函数 
    bool isHave = JniHelper::getStaticMethodInfo(minfo,"org.cocos2dx.cpp/AppActivity","getMacStr","(I)Ljava/lang/String;");  
    if (!isHave) { 
        CCLog("jni:此函数不存在"); 
		 
    }else{ 
        CCLog("jni:此函数存在"); 
        //调用此函数 
        //minfo.env->CallStaticVoidMethod(minfo.classID, minfo.methodID,823); 
		jstring js_pkn = (jstring)minfo.env->CallStaticObjectMethod(minfo.classID, minfo.methodID,823); 
		str_pcMacStr = JniHelper::jstring2string(js_pkn); 
		//CCLog("android send msg::%s",str_pkn);
		strncpy(pcMac.strId,str_pcMacStr.c_str(),str_pcMacStr.length());  
		pcMac.win_percent = 90;
    } 
#endif 

}


void AppDelegate::getThePcMacStrFromServer()
{
	char buf[1024];
	readPcMacStr();
		//------------
		//strncpy(pcMac.strId,"12345",sizeof("12345")); 
		//pcMac.win_percent = 90;
		//----------------
	//strncpy(pcMac.strId,"12345", sizeof("12345")); 
	memcpy( &buf, &msgGetPcMacAdress, sizeof(msgGetPcMacAdress) );
	memcpy( &buf[sizeof(msgGetPcMacAdress) + 1], &pcMac, sizeof(pcMac) );
	cSocket.Send(buf,sizeof(buf),0); 
}

void AppDelegate::checkRecvMsgFromServer()
{
	char buf[1024];
	cSocket.Recv(buf,sizeof(buf),0);
	memcpy( &msgType, buf, sizeof(msgType));
	switch(msgType)
	{
	case msgGetPcMacAdress:
		memcpy( &pcMac, &buf[sizeof(msgType) + 1], sizeof(pcMac) ); 
		GameManager::getInstance()->win_percent = pcMac.win_percent;
		GameManager::getInstance()->saveData();
		break;
	case msgOpenBigAward:
		GameManager::getInstance()->isOpenBigAward = true;
		break;
	}
}

