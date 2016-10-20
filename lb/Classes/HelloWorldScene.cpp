#include "HelloWorldScene.h"

#include "network/HttpClient.h"


#include "ui/CocosGUI.h"
#include"cocostudio/CocoStudio.h"
#include "Common.h"  
#include "SimpleAudioEngine.h"  

#include <stdio.h>
#include "ODSocket.h"


using namespace CocosDenshion;
using namespace cocos2d;
using namespace cocostudio::timeline;
USING_NS_CC;
using namespace ui;

using namespace cocos2d::network;
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);

    // add "HelloWorld" splash screen"
    auto sprite = Sprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(sprite, 0);
    
	 //aaLb = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
	 //aaLb->setPosition(Vec2(500,500));
	 //this->addChild(aaLb, 0);
    return true;
}


void HelloWorld::connectTest()
{
	ODSocket cSocket;
	cSocket.Init();
	cSocket.Create(AF_INET,SOCK_STREAM,0);
	cSocket.Connect("192.168.0.132",8567);
	char recvBuf[64] = "\0";
	cSocket.Send("bbb",strlen("bbb")+1,0);
	cSocket.Recv(recvBuf,64,0);
	printf("%s was recived from server!\n",recvBuf);
	cSocket.Close();
	cSocket.Clean();	
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
//	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
//    return;
//#endif
//
//    Director::getInstance()->end();
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif


//	Node* node;
//	ActionTimeline* action;
//	node = CSLoader::createNode("effect_xin_anima_nvc2.csb");
//	//action = CSLoader::createTimeline("effect_xin_anima_nvc2.csb");
//	//action->gotoFrameAndPlay(0, FrameNumCard3DAction, true);
//	node->setPosition(Vec2(200,500));
////	node->runAction(action);
//	this->addChild(node);

		Node* colouredLight =  CSLoader::createNode(FrameColouredLightAction);
		colouredLight->setPosition(Vec2(DISPLAY_CX,DISPLAY_CY));
		this->addChild(colouredLight);
		ActionTimeline* actionLight = CSLoader::createTimeline(FrameColouredLightAction);
		actionLight->gotoFrameAndPlay(0, FrameColouredLightNumAction, true);
		colouredLight->runAction(actionLight);

//	connectTest();

}



void HelloWorld::showVideo(){
	Size size = Director::getInstance()->getVisibleSize();
	#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
		auto videoPlayer = cocos2d::experimental::ui::VideoPlayer::create();
		videoPlayer->setPosition(Point(size.width / 2, size.height / 2));
		videoPlayer->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		videoPlayer->setContentSize(Size(size.width , size.height));
		this->addChild(videoPlayer);
		if (videoPlayer)
		{
			videoPlayer->setFileName("datas/xhn.mp4");
			videoPlayer->play();
		}
		videoPlayer->addEventListener(CC_CALLBACK_2(HelloWorld::videoEventCallback, this));
	#endif
}

/**
44.
* 视频播放完成的回调函数
45.
*/
void HelloWorld::videoPlayOverCallback()
{

}
/**
51.
*  视频播放的状态
52.
*  注意这里的代码，此处代码只有在android平台和Ios平台有效
53.
*/
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID || CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	void HelloWorld::videoEventCallback(Ref* sender, cocos2d::experimental::ui::VideoPlayer::EventType eventType){
		switch (eventType) {
				case cocos2d::experimental::ui::VideoPlayer::EventType::PLAYING:
			break;
				case cocos2d::experimental::ui::VideoPlayer::EventType::PAUSED:
			break;
				case cocos2d::experimental::ui::VideoPlayer::EventType::STOPPED:
			break;
				case cocos2d::experimental::ui::VideoPlayer::EventType::COMPLETED:
				videoPlayOverCallback();
			break;
			default:
		break;
	}
}
#endif