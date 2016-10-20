//
//  MainMenuScene.cpp
//  mxr
//
//  Created by imac on 15/11/14.
//
//

#include "LoadScene.h"
#include "MainScene.h"
#include "GameManager.h"
#include "CardConfigUtil.h"
#include "Common.h"
#include "HelloWorldScene.h"

#include "network/WebSocket.h"

#include "ui/CocosGUI.h"
#include"cocostudio/CocoStudio.h"
#include "SimpleAudioEngine.h"  
using namespace CocosDenshion;
using namespace cocos2d;
using namespace cocostudio::timeline;
USING_NS_CC;
using namespace ui;

LoadScene::LoadScene()
:numberOfLoadedRes(0)
,totalOfLoadedRes(230)
,m_numSp(230)
,progressBar(NULL)
{

}

static const char *file_plist_png[99] = {
    "plist/Plist_effect_er.png",
    "plist/Plist_effect_jie.png",
    "plist/Plist_effect_lian.png",
    "plist/Plist_effect_logo.png",
    "plist/Plist_effect_nva.png",
    "plist/Plist_effect_nvb.png",
    "plist/Plist_effect_nvc.png",
    "plist/Plist_effect_nvd.png",
	"plist/Plist_effect_xie.png",
    "plist/Plist_light.png",
    "plist/Plist_qiu1.png",
    "plist/Plist_qiu2.png",
    "plist/Plist_qiu3.png",
    "plist/Plist_qiu4.png",
    "plist/Plist_qiu5.png",
    "plist/Plist_qiu6.png",
    "plist/Plist_qiu7.png",
	"plist/Plist_qiu8.png",
	"plist/Plist_xineffect_er2.png",
	"plist/Plist_xineffect_jie2.png",
	"plist/Plist_xineffect_lian2.png",
	"plist/Plist_xineffect_logo2.png",
	"plist/Plist_xineffect_nva2.png",
	"plist/Plist_xineffect_nvb2.png",
	"plist/Plist_xineffect_nvc2.png",
	"plist/Plist_xineffect_nvd2.png",
	"plist/Plist_xineffect_xie2.png",
	"plist/Plist_gd.png",
	"plist/Plist_gd_shuzi.png",
	"plist/Plist_huitan_01.png",
	"plist/Plist_huitan_02.png",
	"plist/Plist_huitan_03.png",
	"plist/Plist_huitan_04.png",
	"plist/Plist_huitan_05.png",
	"plist/Plist_huitan_shuzi_01.png",
	"plist/Plist_huitan_shuzi_02.png",
	"plist/Plist_huitan_shuzi_03.png",
	"plist/Plist_huojiang01.png",
	"plist/Plist_huojiang02.png",
	"plist/Plist_logo_light.png",
	"plist/Plist_men_01.png",
	"plist/Plist_men_02.png",
	"plist/Plist_men_03.png",
	"plist/Plist_men_04.png",
	"plist/Plist_men_05.png",
	"plist/Plist_men_06.png",
	"plist/Plist_men_07.png",
	"plist/Plist_men02_01.png",
	"plist/Plist_men02_02.png",
	"plist/Plist_men02_03.png",
	"plist/Plist_men02_04.png",
	"plist/Plist_men02_05.png",
	"plist/Plist_men02_06.png",
	"plist/Plist_men02_07.png",
	"plist/Plist_pao1.png",
	"plist/Plist_pao2.png",
	"plist/Plist_pao3.png",
	"plist/Plist_pao4.png",
	"plist/Plist_pao5.png",
	"plist/Plist_pao6.png",
	"plist/Plist_pao7.png",
	"plist/Plist_pao8.png",
	"plist/Plist_pao9.png",
	"plist/Plist_pao10.png",
	"plist/Plist_xian01.png",
	"plist/Plist_xian02.png",
	"plist/Plist_xian03.png",
	"plist/Plist_yanhua01.png",
	"plist/Plist_yanhua02.png",
	"plist/Plist_yanhua03.png",
	"plist/Plist_yanhua04.png",
	"plist/Plist_yanhua05.png",
	"plist/Plist_yanhua06.png",
	"plist/Plist_yanhua07.png",
	"plist/Plist_yanhua08.png",
	"plist/Plist_yanhua09.png",
	"plist/Plist_yanhua10.png",
	"plist/Plist_logo_deng.png",
	"plist/Plist_jinchang_01.png",
	"plist/Plist_jinchang_02.png",
	"plist/Plist_jinchang_03.png",
	"plist/Plist_jinchang_04.png",
	"plist/Plist_jinchang_05.png",
	"plist/Plist_jinchang_06.png",
	"plist/Plist_jinchang_07.png",
	"plist/Plist_jinchang_08.png",
	"plist/Plist_jinchang_09.png",
	"plist/Plist_jinchang_10.png",
	"plist/Plist_jinchang_11.png",
	"plist/Plist_tuichang_01.png",
	"plist/Plist_tuichang_02.png",
	"plist/Plist_tuichang_03.png",
	"plist/Plist_tuichang_04.png",
	"plist/Plist_tuichang_05.png",
	"plist/Plist_tuichang_06.png",
	"plist/Plist_tuichang_07.png",
	"plist/Plist_tuichang_08.png",
	"plist/Plist_tuichang_09.png",
	"plist/Plist_tuichang_10.png",
};
static const char *file_plist_plist[99] = {
    "plist/Plist_effect_er.plist",
    "plist/Plist_effect_jie.plist",
    "plist/Plist_effect_lian.plist",
    "plist/Plist_effect_logo.plist",
    "plist/Plist_effect_nva.plist",
    "plist/Plist_effect_nvb.plist",
    "plist/Plist_effect_nvc.plist",
    "plist/Plist_effect_nvd.plist",
	"plist/Plist_effect_xie.plist",
    "plist/Plist_light.plist",
    "plist/Plist_qiu1.plist",
    "plist/Plist_qiu2.plist",
    "plist/Plist_qiu3.plist",
    "plist/Plist_qiu4.plist",
    "plist/Plist_qiu5.plist",
    "plist/Plist_qiu6.plist",
    "plist/Plist_qiu7.plist",
	"plist/Plist_qiu8.plist",
	"plist/Plist_xineffect_er2.plist",
	"plist/Plist_xineffect_jie2.plist",
	"plist/Plist_xineffect_lian2.plist",
	"plist/Plist_xineffect_logo2.plist",
	"plist/Plist_xineffect_nva2.plist",
	"plist/Plist_xineffect_nvb2.plist",
	"plist/Plist_xineffect_nvc2.plist",
	"plist/Plist_xineffect_nvd2.plist",
	"plist/Plist_xineffect_xie2.plist",
	"plist/Plist_gd.plist",
	"plist/Plist_gd_shuzi.plist",
	"plist/Plist_huitan_01.plist",
	"plist/Plist_huitan_02.plist",
	"plist/Plist_huitan_03.plist",
	"plist/Plist_huitan_04.plist",
	"plist/Plist_huitan_05.plist",
	"plist/Plist_huitan_shuzi_01.plist",
	"plist/Plist_huitan_shuzi_02.plist",
	"plist/Plist_huitan_shuzi_03.plist",
	"plist/Plist_huojiang01.plist",
	"plist/Plist_huojiang02.plist",
	"plist/Plist_logo_light.plist",
	"plist/Plist_men_01.plist",
	"plist/Plist_men_02.plist",
	"plist/Plist_men_03.plist",
	"plist/Plist_men_04.plist",
	"plist/Plist_men_05.plist",
	"plist/Plist_men_06.plist",
	"plist/Plist_men_07.plist",
	"plist/Plist_men02_01.plist",
	"plist/Plist_men02_02.plist",
	"plist/Plist_men02_03.plist",
	"plist/Plist_men02_04.plist",
	"plist/Plist_men02_05.plist",
	"plist/Plist_men02_06.plist",
	"plist/Plist_men02_07.plist",
	"plist/Plist_pao1.plist",
	"plist/Plist_pao2.plist",
	"plist/Plist_pao3.plist",
	"plist/Plist_pao4.plist",
	"plist/Plist_pao5.plist",
	"plist/Plist_pao6.plist",
	"plist/Plist_pao7.plist",
	"plist/Plist_pao8.plist",
	"plist/Plist_pao9.plist",
	"plist/Plist_pao10.plist",
	"plist/Plist_xian01.plist",
	"plist/Plist_xian02.plist",
	"plist/Plist_xian03.plist",
	"plist/Plist_yanhua01.plist",
	"plist/Plist_yanhua02.plist",
	"plist/Plist_yanhua03.plist",
	"plist/Plist_yanhua04.plist",
	"plist/Plist_yanhua05.plist",
	"plist/Plist_yanhua06.plist",
	"plist/Plist_yanhua07.plist",
	"plist/Plist_yanhua08.plist",
	"plist/Plist_yanhua09.plist",
	"plist/Plist_yanhua10.plist",
	"plist/Plist_logo_deng.plist",
	"plist/Plist_jinchang_01.plist",
	"plist/Plist_jinchang_02.plist",
	"plist/Plist_jinchang_03.plist",
	"plist/Plist_jinchang_04.plist",
	"plist/Plist_jinchang_05.plist",
	"plist/Plist_jinchang_06.plist",
	"plist/Plist_jinchang_07.plist",
	"plist/Plist_jinchang_08.plist",
	"plist/Plist_jinchang_09.plist",
	"plist/Plist_jinchang_10.plist",
	"plist/Plist_jinchang_11.plist",
	"plist/Plist_tuichang_01.plist",
	"plist/Plist_tuichang_02.plist",
	"plist/Plist_tuichang_03.plist",
	"plist/Plist_tuichang_04.plist",
	"plist/Plist_tuichang_05.plist",
	"plist/Plist_tuichang_06.plist",
	"plist/Plist_tuichang_07.plist",
	"plist/Plist_tuichang_08.plist",
	"plist/Plist_tuichang_09.plist",
	"plist/Plist_tuichang_10.plist",
};


bool LoadScene::init()
{
    if (this->Scene::init() == false) {
        return false;
    }
	m_loadedSp = 0;
//	progressBar = addProgress();
	Size visibleSize = Director::getInstance()->getVisibleSize();  
	Point origin = Director::getInstance()->getVisibleOrigin();

	loadLabel = LabelTTF::create("Loading:","Arial",20);//创建显示Loading: 的label  
	loadLabel->setPosition(Point(visibleSize.width/2-30,visibleSize.height/2+30));  
	this->addChild(loadLabel,1);  
  
	percentLabel = LabelTTF::create("0%","Arial",20);//创建显示百分比的label  
	percentLabel->setPosition(Point(visibleSize.width/2+35,visibleSize.height/2+30));  
	this->addChild(percentLabel,2);  
  
	auto loadBg = Sprite::create("load/picture/loading_01.png");//进程条的底图  
	loadBg->setPosition(Point(visibleSize.width/2,visibleSize.height/2));  
	this->addChild(loadBg,1);  
  
	loadProgress = ProgressTimer::create(Sprite::create("load/picture/loading_02.png"));//创建一个进程条  
	loadProgress->setBarChangeRate(Point(1,0));//设置进程条的变化速率  
	loadProgress->setType(ProgressTimer::Type::BAR);//设置进程条的类型  
	loadProgress->setMidpoint(Point(0,1));//设置进度的运动方向  
	loadProgress->setPosition(Point(visibleSize.width/2,visibleSize.height/2));  
	loadProgress->setPercentage(0.0f);//设置初始值为0  
	this->addChild(loadProgress,2);  
	loadResources();
	schedule(schedule_selector(LoadScene::logic));
	return true;
}

ProgressTimer * LoadScene::addProgress()
{

	auto rootNode = CSLoader::createNode("load/LoadScene.csb");
	this->addChild(rootNode);//

	auto WindmillNode = (Node*)rootNode->getChildByName("windmillNode");
	auto actionWindmill = CSLoader::createTimeline("load/WindmillNode.csb");
	actionWindmill->gotoFrameAndPlay(0, 30, true);
	WindmillNode->runAction(actionWindmill);


	Sprite* loadingBg = (Sprite*)rootNode->getChildByName("loadingBg");
	//Sprite* loadingBg = Sprite::create("load/picture/loading_01.png");
	//loadingBg->setPosition(Vec2(DISPLAY_CX,DISPLAY_CY));
	//this->addChild(loadingBg);
	auto progressBar = ProgressTimer::create(Sprite::create("load/picture/loading_02.png"));
	progressBar->setType(ProgressTimer::Type::BAR);
	progressBar->setMidpoint(Point(0, 0.5f));
	progressBar->setBarChangeRate(Point(1, 0));
	progressBar->setPercentage(0);
	progressBar->setAnchorPoint(Point(0.5f, 0.5f));
	progressBar->setPosition(Point(loadingBg->getContentSize().width / 2, loadingBg->getContentSize().height / 2));
	loadingBg->addChild(progressBar);
	return progressBar;


}
void LoadScene::loadResources()
{
	GameManager::getInstance()->vecCardElmen.clear();
	//-----------
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic(FileUtils::getInstance()->fullPathForFilename("sound/bgmusic.ogg").c_str());//1
	numberOfLoadedRes++;
	m_loadedSp++;
	for(int i = 0;i < 99; i++)
	{
		Director::getInstance()->getTextureCache()->addImageAsync(file_plist_png[i],
		CC_CALLBACK_1(LoadScene::callBackAddPlistAsync, this, file_plist_plist[i]));
	}
	for(int i = 0;i < 128; i++)
	{
		std::string str;
		char chSt[50]="video/mv_01";
		str = StringUtils::format("%s%03d.jpg", chSt, i + 1);
		Director::getInstance()->getTextureCache()->addImageAsync(str,//15
		CC_CALLBACK_1(LoadScene::callBackAddImageAsync, this));
	}	
	//LoadGameCfg *loadGameCfg = LoadGameCfg::createLoadGameCfg("datas/gamecfg.plist");
 //   loadGameCfg->readLevelInfo();
	//numberOfLoadedRes++;
	//m_loadedSp++;
	CardConfigUtil::getInstance()->readCardElmenXmlData(GameManager::getInstance()->vecCardElmen);
	numberOfLoadedRes++;
	m_loadedSp++;
	CardConfigUtil::getInstance()->writeXmlStatistics();
	numberOfLoadedRes++;
	m_loadedSp++;
}
void LoadScene::callBackAddImageAsync(Texture2D *texture)
{
	numberOfLoadedRes++;
	++m_loadedSp;//每进到这个函数一次，让m_loadedSp + 1  
  
}
void LoadScene::callBackAddPlistAsync(Object* obj, const std::string& plistpath)
{
	Texture2D *texture = (Texture2D*)obj;//传入的obj即是异步生成的纹理
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile(plistpath, texture);
	numberOfLoadedRes++;
	++m_loadedSp;//每进到这个函数一次，让m_loadedSp + 1  

}
void LoadScene::transitionScene()
{
	//	Director::getInstance()->replaceScene(TransitionFade::create(0.0f, MainMenuScene::createScene()));
	Director::getInstance()->replaceScene(MainScene::create());
//	Director::getInstance()->replaceScene(HelloWorld::createScene());
}
void LoadScene::logic(float dt)
{
    char buf_str[16];  
    sprintf(buf_str,"%d%%",(int)(((float)m_loadedSp / m_numSp) * 100),m_numSp);  
    percentLabel->setString(buf_str);//更新percentLabel的值  
  
    float newPercent = 100 - ((float)m_numSp - (float)m_loadedSp)/((float)m_numSp/100);//计算进度条当前的百分比  
    //因为加载图片速度很快，所以就没有使用ProgressTo，  
    //或者ProgressFromTo这种动作来更新进度条  
    loadProgress->setPercentage(newPercent);//更新进度条  
  
    //图片加载完成后  
    if(m_loadedSp >= m_numSp)  
    {  
        this->removeChild(loadProgress);//将添加的几个对象删除掉  
        this->removeChild(percentLabel);  
        this->removeChild(loadLabel);  
  
        //加载完既要跳转到gotoNewLayer,在这里可以  
        //创建新的Scene，新的Layer，或者其他什么乱七八糟的  
        transitionScene();  
		SimpleAudioEngine::getInstance()->playBackgroundMusic(FileUtils::getInstance()->fullPathForFilename("sound/bgmusic.ogg").c_str(), true);
		SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(GameManager::getInstance()->startVolume);
		SimpleAudioEngine::getInstance()->setEffectsVolume(GameManager::getInstance()->startVolume);
    }  



//	float percent = (float)numberOfLoadedRes / (float)totalOfLoadedRes * 100;
//	//log("numberOfLoadedRes----------------####,%d", numberOfLoadedRes);
//	//log("totalOfLoadedRes*********************,%d", totalOfLoadedRes);
//	//log("percent##############################,%f", percent);
//	progressBar->setPercentage(percent);
//	if (numberOfLoadedRes == totalOfLoadedRes)
//	{
//		//numberOfLoadedRes++;
//		//if (numberOfLoadedRes >= 3 * totalOfLoadedRes)
//		//{
//		//	transitionScene();
//		//}
////		GameManager::getInstance()->setIsSound(true);
////		GameManager::getInstance()->isCanPlaySound = true;
//		transitionScene();
//		//SimpleAudioEngine::getInstance()->playBackgroundMusic(FileUtils::getInstance()->fullPathForFilename("sound/bgmusic.ogg").c_str(), true);
//		//SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.2f);
//		//SimpleAudioEngine::getInstance()->setEffectsVolume(0.2f);
//		//SimpleAudioEngine::sharedEngine()->stopAllEffects();
//	}
}



