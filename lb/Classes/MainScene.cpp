//
//  MainMenuScene.cpp
//  mxr
//
//  Created by imac on 15/11/14.
//
//

#include "MainScene.h"
#include "GameManager.h"
#include "SystemLayer.h"
#include "ODSocket.h"
#include "Protocal.h"

#include "CardConfigUtil.h"

#include "AnimationUtil.h"

#include "network/WebSocket.h"

#include "ui/CocosGUI.h"
#include"cocostudio/CocoStudio.h"
#include "Common.h"  
#include "SimpleAudioEngine.h"  
using namespace CocosDenshion;
using namespace cocos2d;
using namespace cocostudio::timeline;
USING_NS_CC;
using namespace ui;

#define OMNIPOTENT_CARD (8)

#define CARD_MAX (15)
#define LINE_MAX (9)
#define CARD_ARR_ROW (3)
#define CARD_ARR_COL (5)
#define CARD_SPRITE_TAG (1000)
#define CARD_ACTION_TAG (200)
#define BOX_ACTION_TAG (300)
#define LIGHT_ACTION_TAG (400)
#define CARD_3D_ACTION_TAG (500)
#define GRAY_CARD_TAG (1500)
#define CARD_3D_BG_TAG (2000)
#define MARIE_LIGHT_TAG (2100)
#define NODE_STICK_TAG (2110)
#define NODE_BUTTOM_LOGO_TAG (2120)
#define NODE_UP_LOGO_TAG (2121)

#define SP_LAMB_COMON (2131)
#define SP_LAMB_WIN (2132)

#define CARD_SP_LOCAL_ZOrder (98)
#define GRAY_CARD_LOCAL_ZOrder (99)
#define LINE_LOCAL_ZOrder (100)
#define CARD_3D_BG_CARD_LOCAL_ZOrder (101)
#define CARD_3D_LOCAL_ZOrder (102)
#define LIGHT_LOCAL_ZOrder (103)
#define BOX_LOCAL_ZOrder (104)
#define MARIE_LIGHT_ZOrder (110)
#define LOGO_PIC_ZOrder (115)
#define NODE_STICK_ZOrder (2)
#define NODE_BUTTOM_LOGO_ZOrder (120)
#define NODE_UP_LOGO_ZOrder (120)

#define MAX_CHARGE_POINT (2)

#define COIN_UPDATE_TIME (30)
#define TOTOLE_COIN_UPDATE_TIME (10)



static const int CardLineIndex_01[5] = {1,4,7,10,13};
static const int CardLineIndex_02[5] = {0,3,6,9,12};
static const int CardLineIndex_03[5] = {2,5,8,11,14};
static const int CardLineIndex_04[5] = {0,4,8,10,12};
static const int CardLineIndex_05[5] = {2,4,6,10,14};
static const int CardLineIndex_06[5] = {0,3,7,9,12};
static const int CardLineIndex_07[5] = {2,5,7,11,14};
static const int CardLineIndex_08[5] = {1,5,8,11,13};
static const int CardLineIndex_09[5] = {1,3,6,9,13};



static const char *CardSpriteFrameName[9] = {
    "huitan/er_042.png",
    "huitan/jie_042.png",
    "huitan/lian_042.png",
    "huitan/nva_042.png",
    "huitan/nvb_042.png",
    "huitan/nvc_042.png",
    "huitan/nvd_042.png",
    "huitan/xie_042.png",
	"huitan/logo_042.png",
};
static const char *CardRollActionName[9] = {
    "effect_gd_er.csb",
    "effect_gd_jie.csb",
    "effect_gd_lian.csb",
    "effect_gd_nva.csb",
    "effect_gd_nvb.csb",
    "effect_gd_nvc.csb",
    "effect_gd_nvd.csb",
    "effect_gd_xie.csb",
	"effect_gd_logo.csb",
};
static const char *CardSpringbackActionName[9] = {
    "effect_huitan_er.csb",
    "effect_huitan_jie.csb",
    "effect_huitan_lian.csb",
    "effect_huitan_nva.csb",
    "effect_huitan_nvb.csb",
    "effect_huitan_nvc.csb",
    "effect_huitan_nvd.csb",
    "effect_huitan_xie.csb",
	"effect_huitan_logo.csb",
};
static const char *EffectLineActionName[9] = {
    "effect_xian_one.csb",
    "effect_xian_two.csb",
    "effect_xian_there.csb",
    "effect_xian_four.csb",
    "effect_xian_five.csb",
    "effect_xian_six.csb",
    "effect_xian_seven.csb",
    "effect_xian_eight.csb",
    "effect_xian_nine.csb",
};
static const char *Card3DActionName[9] = {
    "effect_anima_er.csb",
    "effect_anima_jie.csb",
    "effect_anima_lian.csb",
    "effect_anima_nva.csb",
    "effect_anima_nvb.csb",
    "effect_anima_nvc.csb",
    "effect_anima_nvd.csb",
    "effect_anima_xie.csb",
	"effect_anima_logo.csb",
};

static const char *Card3DActionName2[9] = {
    "effect_xin_anima_er2.csb",
    "effect_xin_anima_jie2.csb",
    "effect_xin_anima_lian2.csb",
    "effect_xin_anima_nva2.csb",
    "effect_xin_anima_nvb2.csb",
    "effect_xin_anima_nvc2.csb",
    "effect_xin_anima_nvd2.csb",
    "effect_xin_anima_xie2.csb",
	"effect_xin_anima_logo2.csb",
};
static const char *GrayCardPicName[9] = {
    "graycard/er_hui.jpg",
    "graycard/jie_hui.jpg",
    "graycard/lian_hui.jpg",
    "graycard/nva_hui.jpg",
    "graycard/nvb_hui.jpg",
    "graycard/nvc_hui.jpg",
    "graycard/nvd_hui.jpg",
    "graycard/xie_hui.jpg",
	"graycard/logo_hui.jpg",
};
static const char *Card3DBgPicName[9] = {
    "effect/er_00096.jpg",
    "effect/jie_071.jpg",
    "effect/lian_096.jpg",
    "effect/nva_00096.jpg",
    "effect/nvb_00088.jpg",
    "effect/nvc_00085.jpg",
    "effect/nvd_00096.jpg",
    "effect/xie_00096.jpg",
	"effect/logo_00050.jpg",
};
static const char *MarieNumPicName[10] = {
    "shuzihuitan/shuzi0_019.png",
    "shuzihuitan/shuzi1_019.png",
    "shuzihuitan/shuzi2_019.png",
    "shuzihuitan/shuzi3_019.png",
    "shuzihuitan/shuzi4_019.png",
    "shuzihuitan/shuzi5_019.png",
    "shuzihuitan/shuzi6_019.png",
    "shuzihuitan/shuzi7_019.png",
	"shuzihuitan/shuzi8_019.png",
	"shuzihuitan/shuzi9_019.png",
};
static const char *MarieNumSpringbackActionName[10] = {
    "effect_huitan_shuzi0.csb",
    "effect_huitan_shuzi1.csb",
    "effect_huitan_shuzi2.csb",
    "effect_huitan_shuzi3.csb",
    "effect_huitan_shuzi4.csb",
    "effect_huitan_shuzi5.csb",
    "effect_huitan_shuzi6.csb",
    "effect_huitan_shuzi7.csb",
	"effect_huitan_shuzi8.csb",
	"effect_huitan_shuzi9.csb"
};


int lineMultiple[9][3]={ 
	{2,5,20},//铁斧的3,4,5连线的倍数
	{3,10,40},//银枪的3,4,5连线的倍数
	{5,15,60},//金刀的3,4,5连线的倍数
	{7,20,100},//鲁智深的3,4,5连线的倍数
	{10,30,160},//林冲的3,4,5连线的倍数
	{15,40,200},//宋江的3,4,5连线的倍数
	{20,80,400},//替天行道的3,4,5连线的倍数
	{50,200,1000},//忠义堂的3,4,5连线的倍数
	{0,0,2000}//水浒传的3,4,5连线的倍数
};	

int winRand[10][15]={ 
	{0,7,8,1,7,7,4,7,2,1,5,5,7,6,8},//1连线
	{2,5,8,2,6,7,2,7,4,2,2,5,2,7,8},//2连线
	{0,4,2,5,8,2,1,4,2,6,7,2,4,5,2},//3连线
	{2,4,8,0,2,7,6,7,2,1,2,5,2,6,8},//4连线
	{4,5,2,0,2,7,2,6,6,1,2,5,8,0,2},//5连线
	{2,5,1,2,4,7,1,2,6,2,5,5,2,0,4},//6连线
	{0,5,2,4,4,2,1,2,6,6,5,2,7,0,2},//7连线
	{0,2,1,4,4,2,1,5,2,6,5,2,7,2,7},//8连线
	{8,8,2,3,8,5,6,8,8,0,4,2,3,8,5},//9连线
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}//满屏幕
};	

int chargePoinMultiple[2][2]={ 
	{5,45},
	{10,90}
};

int overallWinReward[9]={50,100,150,250,400,500,1000,2500,5000};

//INICache* iniCache; 
ui::CheckBox* chkStart;
ui::CheckBox* chkAutoStart;
ui::Button* btnChargePoint;
ui::Button* btnChargePointMax;
//ui::Button* btnTest;
Sprite* spBtnStartGrayPic;
Sprite* spChargePointGrayPic;
Sprite* spbtnChargePointMaxGrayPic;

extern ODSocket cSocket;

MenuItemImage* btnTest;
MenuItemImage* btnSystem;
bool MainScene::init()
{
    if (this->Scene::init() == false) {
        return false;
    }
	//GameManager::getInstance()->readData();
	rootNode = CSLoader::createNode("MainScene.csb");
	//rootNode->setVisible(false);
	this->addChild(rootNode);//
	auto bg = (Sprite*)rootNode->getChildByName("bg");
	nodeBigBox = (Node*)rootNode->getChildByName("shuiguojikuang1");
	spLogoPic = (Sprite*)rootNode->getChildByName("jie_logo");
	spLogoPic->setLocalZOrder(LOGO_PIC_ZOrder);
	initData();
	initCard();
	newMain = (Node*)rootNode->getChildByName("XinMain");
	newMain->setVisible(false);

		Node* colouredLight =  CSLoader::createNode(FrameColouredLightAction);
		colouredLight->setPosition(Vec2(DISPLAY_CX,DISPLAY_CY));
		newMain->addChild(colouredLight);
		ActionTimeline* actionLight = CSLoader::createTimeline(FrameColouredLightAction);
		actionLight->gotoFrameAndPlay(0, FrameColouredLightNumAction, true);
		colouredLight->runAction(actionLight);
	spButtomLogo = (Sprite*)rootNode->getChildByName("jie_logo");
	spUpLogo = (Sprite*)newMain->getChildByName("xin_logo");
	spUpLogo->setLocalZOrder(LOGO_PIC_ZOrder);
	initlogoLihtAction();
	tmpClickType = -1;
	initBtnAndGrayBgPic();
	initNumber();
	initBallAction();
	spVideo = Sprite::create("video/mv_01001.jpg");
	spVideo->setPosition(Vec2(DISPLAY_CX,DISPLAY_CY));
	spVideo->setLocalZOrder(200);
	rootNode->addChild(spVideo);
	spVideo->setVisible(false);

	initRollLamp();

	GameManager::getInstance()->backLayerColor = LayerColor::create(Color4B(25, 25, 25, GameManager::getInstance()->gLubyte_alpha));
	GameManager::getInstance()->backLayerColor->setLocalZOrder(1000);
	this->addChild(GameManager::getInstance()->backLayerColor);

	this->scheduleUpdate();
	return true;
}
void MainScene::initBallAction()
{
	auto ballLeft = (Sprite*)rootNode->getChildByName("qiuz");
	auto nodeBallLeft = CSLoader::createNode(FrameBall);
	nodeBallLeft->setPosition(Vec2(ballLeft->getPosition()));
	rootNode->addChild(nodeBallLeft);
	ActionTimeline* actionBallLeft = CSLoader::createTimeline(FrameBall);
	actionBallLeft->gotoFrameAndPlay(0, FrameNumBall, true);
	nodeBallLeft->runAction(actionBallLeft);
	//--------------------------
	auto ballRight = (Sprite*)rootNode->getChildByName("qiuy");
	auto nodeBallRight  = CSLoader::createNode(FrameBall);
	nodeBallRight->setPosition(Vec2(ballRight->getPosition()));
	rootNode->addChild(nodeBallRight);
	ActionTimeline* actionBallRight  = CSLoader::createTimeline(FrameBall);
	actionBallRight ->gotoFrameAndPlay(0, FrameNumBall, true);
	nodeBallRight ->runAction(actionBallRight );
	//--------------------
 //   btnTest = MenuItemImage::create("anniu_ceshi.png","anniu_ceshi_xiao.png", CC_CALLBACK_1(MainScene::btnTestCallback, this));
	//btnTest->setPosition(Vec2(DISPLAY_LEFT + 120 ,DISPLAY_BOTTOM + 300));
	//auto menu = Menu::create(btnTest, NULL);
 //   menu->setPosition(Vec2::ZERO);
 //   rootNode->addChild(menu, 1);
	////-------------------

 //   btnSystem = MenuItemImage::create("anniu_houtai_xiao.png","anniu_houtai.png", CC_CALLBACK_1(MainScene::btnSystemCallback, this));
	//btnSystem->setPosition(Vec2(DISPLAY_LEFT + 120 ,DISPLAY_BOTTOM + 200));
	//auto menu2 = Menu::create(btnSystem, NULL);
 //   menu2->setPosition(Vec2::ZERO);
 //   rootNode->addChild(menu2, 1);

}
void MainScene::initlogoLihtAction()
{
	nodeButtomLogoLight =  CSLoader::createNode(FrameButtomLogoLight);
	nodeButtomLogoLight->setPosition(Vec2(spButtomLogo->getPosition()));
	nodeButtomLogoLight->setLocalZOrder(NODE_BUTTOM_LOGO_ZOrder);
	nodeButtomLogoLight->setTag(NODE_BUTTOM_LOGO_TAG);
	rootNode->addChild(nodeButtomLogoLight);
	auto actionButtom = CSLoader::createTimeline(FrameButtomLogoLight);
	actionButtom->gotoFrameAndPlay(0, FrameNumButtomLogoLight, true);
	nodeButtomLogoLight->runAction(actionButtom);
	//-------------------------------
	nodeUpLogoLight =  CSLoader::createNode(FrameUpLogoLight);
	nodeUpLogoLight->setPosition(Vec2(spUpLogo->getPosition()));
	nodeUpLogoLight->setLocalZOrder(NODE_UP_LOGO_ZOrder);
	nodeUpLogoLight->setTag(NODE_UP_LOGO_TAG);
	newMain->addChild(nodeUpLogoLight);
	nodeUpLogoLight->setVisible(false);
	auto actionUp = CSLoader::createTimeline(FrameUpLogoLight);
	actionUp->gotoFrameAndPlay(0, FrameNumUpLogoLight, true);
	nodeUpLogoLight->runAction(actionUp);
}
void MainScene::initNumber()
{
	char str[256];
	auto node_1 = (Node*)rootNode->getChildByName("Node_1");
	lbLineSingle = (TextAtlas*)node_1->getChildByName("shuzhi_danxian");
	sprintf(str, "%d", chargePoinMultiple[chargePointCnt][0]);
	lbLineSingle->setString(str);
	lbLineNine = (TextAtlas*)node_1->getChildByName("shuzhi_jiuxian");
	sprintf(str, "%d", chargePoinMultiple[chargePointCnt][1]);
	lbLineNine->setString(str);
	lbLineCoin = (TextAtlas*)node_1->getChildByName("shuzhi_yinbi");
	sprintf(str, "%d", coin);
	lbLineCoin->setString(str);
	//-------------------
	lbMarieGameNum = 0;
	lbMarieGameNum = (TextAtlas*)newMain->getChildByName("shuzhi_mianfei");
	sprintf(str, "%d", marieGameNum);
	lbMarieGameNum->setString(str);
	//------------------------
	//GameManager::getInstance()->totleCoin = 0;
	totleCoin = GameManager::getInstance()->totleCoin ;
	lbTotleCoin = (TextAtlas*)node_1->getChildByName("shuzhi_qianbi");
	sprintf(str, "%d", GameManager::getInstance()->totleCoin);
	lbTotleCoin->setString(str);
}
void MainScene::initBtnAndGrayBgPic()
{
	Point pt;
	auto node_01 = (Node*)rootNode->getChildByName("Node_1");
    chkStart = (ui::CheckBox*)node_01->getChildByName("CheckBox_stop");
	chkStart->addEventListenerCheckBox(this,checkboxselectedeventselector(MainScene::chkStartCallback));
	//--------------------------------
    chkAutoStart = (ui::CheckBox*)node_01->getChildByName("CheckBox_zidong");
	chkAutoStart->addEventListenerCheckBox(this,checkboxselectedeventselector(MainScene::chkAutoStartCallback));
	//-----------------------------------
    btnChargePoint = (ui::Button*)node_01->getChildByName("Button_yafeng");
	btnChargePoint->addTouchEventListener(CC_CALLBACK_2(MainScene::btnChargePointCallback,this));  
    btnChargePointMax = (ui::Button*)node_01->getChildByName("Button_zuida");
	btnChargePointMax->addTouchEventListener(CC_CALLBACK_2(MainScene::btnChargePointMaxCallback,this));  
	//-----------------------------
 //   btnTest = (ui::Button*)rootNode->getChildByName("Button_ceshi");
	//btnTest->addTouchEventListener(CC_CALLBACK_2(MainScene::btnTestCallback,this));  
	//------------------------------
	pt = chkStart->getPosition();
	spBtnStartGrayPic = Sprite::create( "main/anniu_star_hui.png");
	spBtnStartGrayPic->setPosition(Vec2(pt));
	spBtnStartGrayPic->setVisible(false);
	node_01->addChild(spBtnStartGrayPic, 1);
	//----------------------------------
	pt = btnChargePoint->getPosition();
	spChargePointGrayPic = Sprite::create( "main/anniu_yafeng_hui.png");
	spChargePointGrayPic->setPosition(Vec2(pt));
	spChargePointGrayPic->setVisible(false);
	node_01->addChild(spChargePointGrayPic, 1);
	//----------------------------------
	pt = btnChargePointMax->getPosition();
	spbtnChargePointMaxGrayPic = Sprite::create( "main/anniu_zuida_hui.png");
	spbtnChargePointMaxGrayPic->setPosition(Vec2(pt));
	spbtnChargePointMaxGrayPic->setVisible(false);
	node_01->addChild(spbtnChargePointMaxGrayPic, 1);
	//----------------------------------
}

void MainScene::initData()
{
	int i;
	gameState = GameState::Game_Common;
	GameManager::getInstance()->isOpenBigAward = false;
	GameManager::getInstance()->isPlayingVideo = false;
	GameManager::getInstance()->isPlayVideoOver = false;
	gapCardSpX = 225;
	gapCardSpY = 226;
	coin = 0;
	marieGameNum = 0;
	chargePointCnt = 0;
	_center_x = nodeBigBox->getPositionX();
	_center_y = nodeBigBox->getPositionY();
	cardSpInitStX = _center_x - 2*gapCardSpX;
	cardSpInitStY = _center_y + 1*gapCardSpY;
	bGameOver = false;
	isGameEnd = false;
	isGameRuning = false;
	isCardRuning = false;
	isAutoStart = false;
	bRewardMarie = false;
	isBeginUpdateCoin = false;
	isCanPlayMarieGame = false;
	isEnterMarieGameing = false;
//	isMarieGame = false;
//	isPlayLineAction = false;

	nodeRollLampCommon = NULL;//跑马灯
	nodeRollLampWin = NULL;//跑马灯

	vecCardLine_01.clear();
	vecCardLine_02.clear();
	vecCardLine_03.clear();
	vecCardLine_04.clear();
	vecCardLine_05.clear();
	vecCardLine_06.clear();
	vecCardLine_07.clear();
	vecCardLine_08.clear();
	vecCardLine_09.clear();
	for(i = 0; i < LINE_MAX;i++)
	{
		bWinLine[i] = false;
	}
	//for(i = 0; i < CARD_MAX;i++)
	//{
	//	bCardBoxNode[i] = false;
	//}
	for(i = 0; i < CARD_MAX;i++)
	{
		//bCardRollEnd[i] = false;
		bCardActionNode[i] = false;
		cardType[i] = 0;
	}
	randWinLine = -1;
	//获取系统时间
	struct timeval now;
	gettimeofday(&now, NULL);
    
	//初始化随机种子
	//timeval是个结构体，里边有俩个变量，一个是以秒为单位的，一个是以微妙为单位的 
	unsigned rand_seed = (unsigned)(now.tv_sec*1000 + now.tv_usec/1000);    //都转化为毫秒 
	srand(rand_seed);

}


void MainScene::update(float dt)
{
	char str[256];
	sprintf(str, "%d", chargePoinMultiple[chargePointCnt][0]);
	lbLineSingle->setString(str);
	sprintf(str, "%d", chargePoinMultiple[chargePointCnt][1]);
	lbLineNine->setString(str);
	CCString* ns=CCString::createWithFormat("%d",coin);
	lbLineCoin->setString(ns->getCString());
	//---------------------
	sprintf(str, "%d", marieGameNum);
	lbMarieGameNum->setString(str);
	//------------------------
	sprintf(str, "%d", GameManager::getInstance()->totleCoin);
	lbTotleCoin->setString(str);

	upDateCoinNum();
}
void MainScene::btnChargePointCallback(Ref *pSender, Widget::TouchEventType type)
{
	if(gameState == GameState::Game_Reward)
	{
		return;
	}
	if(type == Widget::TouchEventType::ENDED && !isGameRuning)
	{
		
		chargePointCnt++;
		if(chargePointCnt >= MAX_CHARGE_POINT)
		{
			chargePointCnt = 0;
		}
	}
}
void MainScene::btnChargePointMaxCallback(Ref *pSender, Widget::TouchEventType type)
{
	if(gameState == GameState::Game_Reward)
	{
		return;
	}
	if(type == Widget::TouchEventType::ENDED && !isGameRuning)
	{
		chargePointCnt = MAX_CHARGE_POINT - 1;
	}
}
void MainScene::btnTestCallback(Ref* pSender)
{
//	this->addChild(SystemLayer::create());
	if(isCardRuning)
	{
		spBtnStartGrayPic->setVisible(true);
		chkStart->setEnabled(false);
		stopAllCardRoll();
	}else if(!isGameRuning)
	{	
		for(int i = 0; i < 15; i++)
		{
			cardType[i] = winRand[8][i];
		}
		coin = 0;
		isGameRuning = true;
		resetGraySpGrayPic();
		cardActionStartRun();
		playRollLampAction(RollLamp_Common);
		if(isCanPlayMarieGame)
		{
			marieGameNum--;
			if(marieGameNum < 0)
			{
				marieGameNum = 0;
			}
		}
	}
}
void MainScene::btnSystemCallback(Ref* pSender)
{
	this->addChild(SystemLayer::create());
}
void MainScene::chkStartCallback(Ref* sender,CheckBoxEventType type)
{
	if(!isGameEnd && !isAutoStart)
	{
		if(isCardRuning)
		{
			spBtnStartGrayPic->setVisible(true);
			chkStart->setEnabled(false);
			stopAllCardRoll();
		}else if(!isGameRuning)
		{	

			int _rand = rand()%3;
			if(_rand < 1)
			{
//--------------------
				//showVideo();
				//videoLayer->setVisible(true);
				//videoLayer->showVideo();
				playVideoAction();
//----------------------
			}else{
				startRunGame();
			}
		}
	}
}
void MainScene::playVideoAction()
{
	chkAutoStart->setEnabled(false);
	chkStart->setEnabled(false);
	btnChargePoint->setEnabled(false);
	btnChargePointMax->setEnabled(false);
//	btnTest->setEnabled(false);
	spVideo->setVisible(true);
	CCAnimation *animation=CCAnimation::create();
	for(int i = 0;i < 128; i++)
	{
		std::string str;
		char chSt[50]="video/mv_01";
		str = StringUtils::format("%s%03d.jpg", chSt, i + 1);
		Rect rect = Rect(0,0,1280,720);
		CCSpriteFrame *frame=CCSpriteFrame::create(str,rect);
		animation->addSpriteFrame(frame);
	}
	animation->setDelayPerUnit(0.05);
	animation->setLoops(1);
	FiniteTimeAction *actionanim = Animate::create(animation);
	auto action = Sequence::create(
		actionanim,
		CallFuncN::create(CC_CALLBACK_0(MainScene::playVideoActionCallBack, this)),
		NULL);
	spVideo->runAction(action);
	//animationVideo = AnimationUtil::createWithFrameNameAndNum("xulie/nv_00%d.jpg", 750,250, 0.1f, 1);
	//actionVideo = Animate::create(animationVideo);
	//auto action = Sequence::create(
	//	actionVideo,
	//	CallFuncN::create(CC_CALLBACK_0(MainScene::playVideoActionCallBack, this)),
	//	NULL);
	//spVideo->runAction(action);
}
void MainScene::playVideoActionCallBack()
{
	chkAutoStart->setEnabled(true);
	chkStart->setEnabled(true);
	btnChargePoint->setEnabled(true);
	btnChargePointMax->setEnabled(true);
//	btnTest->setEnabled(true);
	spVideo->stopAllActions();
	spVideo->setVisible(false);
	startRunGame();
}
void MainScene::startRunGame()
{
	if(bGameOver)
	{
		return;
	}
	subTotleCoin();
	coin = 0;
	isGameRuning = true;
	isBeginUpdateCoin = false;
	resetGraySpGrayPic();
	createCardByRandom();
	cardActionStartRun();
	playRollLampAction(RollLamp_Common);
	if(isCanPlayMarieGame)
	{
		marieGameNum--;
		if(marieGameNum < 0)
		{
			marieGameNum = 0;
		}
	}
}
void MainScene::createCardByRandom()
{
	int max_index = 0;
	int maxMultipleWinCoin = 0;
	bool isHaveMax = false;
	bool bGetMinMultiple = false;
	bool bGetMidMultiple = false;
	int indexMinMultiple = 0;
	int indexMidMultiple = 0;
	int minMultipleCoin = 0;
	int midMultipleCoin = 0;
	float win_percent = GameManager::getInstance()->win_percent/(float)100;
	int curWinCoin = GameManager::getInstance()->winCoin;
	//float coinWinPercent = 1 - win_percent;
	int shouldWinCoin = GameManager::getInstance()->coinOperated*win_percent;
	int leaveWinCoin = shouldWinCoin - curWinCoin;
	if(leaveWinCoin < 0)
	{
		leaveWinCoin = 0;
	}
	maxMultipleWinCoin = leaveWinCoin / chargePoinMultiple[chargePointCnt][1];

	minMultipleCoin = maxMultipleWinCoin/3;
	midMultipleCoin = maxMultipleWinCoin*2/3;

	int sizeCardElmen =  GameManager::getInstance()->vecCardElmen.size();
	for(int i = 0; i < sizeCardElmen; i++)
	{
		CardElmen cardElmen = GameManager::getInstance()->vecCardElmen.at(i);
		int vecMultipleWinScore = cardElmen.multipleScore;
		if(vecMultipleWinScore >= minMultipleCoin && !bGetMinMultiple)
		{
			bGetMinMultiple = true;
			indexMinMultiple = i;
		}
		if(vecMultipleWinScore >= midMultipleCoin && !bGetMidMultiple)
		{
			bGetMidMultiple = true;
			indexMidMultiple = i;
		}
		if(vecMultipleWinScore >= maxMultipleWinCoin)
		{
			isHaveMax = true;
			max_index = i;
			break;
		}
	}
	if(!isHaveMax)
	{
		max_index = sizeCardElmen - 1;
	}
	if(max_index < 0)
	{
		max_index = 1;
		for(int i = 0; i < 15; i++)
		{
			cardType[i] = winRand[2][i];
		}
	}else
	{
		int rand_1,rand_2;
		int max_multiple_index = max_index + 1;
		if(leaveWinCoin >= max_multiple_coin)
		{
			rand_1 = rand()%(max_multiple_index -indexMidMultiple)  + indexMidMultiple;     
		}else if(leaveWinCoin >= mid_multiple_coin)
		{
			rand_1 = rand()%(max_multiple_index - indexMinMultiple) + indexMinMultiple; 
		}else
		{
			rand_1 = rand()%max_multiple_index; 
		}
		int sizeCardData = GameManager::getInstance()->vecCardElmen.at(rand_1).vecCardData.size();
		rand_2 = rand()%sizeCardData;     //产生0~8的随机数
		for(int i = 0; i < 15; i++)
		{
			cardType[i] = GameManager::getInstance()->vecCardElmen.at(rand_1).vecCardData.at(rand_2).arrCard[i];
			if(GameManager::getInstance()->isOpenBigAward)
			{
				cardType[i] = OMNIPOTENT_CARD;
			}
			//cardType[i] = 5;
		}
	}

	GameManager::getInstance()->isOpenBigAward = false;
//	CCLOG ("%d", 1); 
}

void MainScene::subTotleCoin()
{
	if(gameState == GameState::Game_Reward)
	{
		return;
	}
	totleCoin = GameManager::getInstance()->totleCoin;
	totleCoin = totleCoin - chargePoinMultiple[chargePointCnt][1];
	GameManager::getInstance()->curGameBetOn = chargePoinMultiple[chargePointCnt][1];
	sendMesBetOnToServer();
	if(totleCoin <= 0)
	{
		totleCoin = 0;
		bGameOver = true;
	}
	GameManager::getInstance()->totleCoin = totleCoin;
	GameManager::getInstance()->coinOperated = GameManager::getInstance()->coinOperated + chargePoinMultiple[chargePointCnt][1];
	GameManager::getInstance()->saveData();
}
void MainScene::sendMesBetOnToServer()
{
	char buf[1024];
	int money = GameManager::getInstance()->curGameBetOn;
	memcpy( &buf, &msgBetOnMoney, sizeof(msgBetOnMoney));
	memcpy( &buf[sizeof(msgBetOnMoney) + 1], &money, sizeof(money) );
	cSocket.Send(buf,sizeof(buf),0); 
}

void MainScene::chkAutoStartCallback(Ref* sender,CheckBoxEventType type)
{
	switch (type) {
        case cocos2d::ui::CHECKBOX_STATE_EVENT_SELECTED:
            isAutoStart = true;
			if(!isGameRuning)
			{

				spBtnStartGrayPic->setVisible(true);
				chkStart->setEnabled(false);
				startRunGame();
			}
            break;
        case cocos2d::ui::CHECKBOX_STATE_EVENT_UNSELECTED:
            isAutoStart = false;
			if(isGameRuning && isCardRuning)
			{
				spBtnStartGrayPic->setVisible(false);
				chkStart->setEnabled(true);
				chkStart->setSelected(true);
			}
            break;
        default:
            break;
    }
}
void MainScene::resetGraySpGrayPic()
{
	if(gameState == GameState::Game_Reward && marieGameNum > 0)
	{
		return;
	}
	if(isGameRuning)
	{
		btnChargePoint->setEnabled(false);
		btnChargePointMax->setEnabled(false);
		spChargePointGrayPic->setVisible(true);
		spbtnChargePointMaxGrayPic->setVisible(true);
	}else{
		btnChargePoint->setEnabled(true);
		btnChargePointMax->setEnabled(true);
		spChargePointGrayPic->setVisible(false);
		spbtnChargePointMaxGrayPic->setVisible(false);
	}
}
void MainScene::initCard()
{
	int index = 0;
	for(int i = 0;i < CARD_ARR_COL;i++)
	{
		for(int j = 0; j < CARD_ARR_ROW; j++,index++)
		{
			Point pt;
			pt.x = cardSpInitStX + i*gapCardSpX;
			pt.y = cardSpInitStY - j*gapCardSpY;
			int _rand = rand()%8;  //产生一个随机数
			initCardSprite(_rand,pt,CARD_SPRITE_TAG + index);
		}
	}
}

void MainScene::initCardSprite(int rand,Point pt,int tag)
{
//	Sprite* sprite = Sprite::create(CardSpriteFrameName[rand]);
	Sprite* sprite = Sprite::createWithSpriteFrameName(CardSpriteFrameName[rand]);
	sprite->setPosition(pt);
	sprite->setTag(tag);
	sprite->setLocalZOrder(CARD_SP_LOCAL_ZOrder);
	sprite->setVisible(true);
	rootNode->addChild(sprite);
}

void MainScene::cardActionStartRun()
{
	int i;
	ActionTimeline* action;
	isCardRuning = true;
	for(i = 0;i < CARD_MAX;i++)
	{
		auto sp = (Node*)rootNode->getChildByTag(CARD_SPRITE_TAG + i);
		sp->setVisible(false);
		actionCardIndex = 0;
		actionCardIndex = 0;
		action = createRandRollActionByIndex(i);
		auto node = rootNode->getChildByTag(CARD_ACTION_TAG + i);
		if(i == 0)
		{
			action->gotoFrameAndPlay(0, FrameNumCardRoll, false);
			action->setLastFrameCallFunc(std::bind(&MainScene::actionCardRollCallBack, this));
		}else{
			action->gotoFrameAndPlay(0, FrameNumCardRoll, true);
		}
		node->runAction(action);
	}
}
void MainScene::initRollLamp()
{
	ActionTimeline* actionCommon;
	ActionTimeline* action;
	//--------------------
	nodeRollLampCommon = CSLoader::createNode(CommonRollLampFrameName);
	nodeRollLampCommon->setLocalZOrder(LOGO_PIC_ZOrder - 1);
	actionCommon = CSLoader::createTimeline(CommonRollLampFrameName);
	actionCommon->gotoFrameAndPlay(0, FrameNumRollLampCommon, true);
	nodeRollLampCommon->setPosition(Vec2(_center_x,_center_y + 10));
	rootNode->addChild(nodeRollLampCommon);
	nodeRollLampCommon->runAction(actionCommon);
	nodeRollLampCommon->setTag(SP_LAMB_COMON);
	//-----------------
	nodeRollLampWin = CSLoader::createNode(WinRollLampFrameName);
	nodeRollLampWin->setLocalZOrder(LOGO_PIC_ZOrder - 1);
	action = CSLoader::createTimeline(WinRollLampFrameName);
	action->gotoFrameAndPlay(0, FrameNumRollLampWin, true);
	nodeRollLampWin->setPosition(Vec2(_center_x,_center_y + 10));
	rootNode->addChild(nodeRollLampWin);
	nodeRollLampWin->runAction(action);
	nodeRollLampWin->setTag(SP_LAMB_WIN);
	//--------------------
	finishRollLampAction();
}

void MainScene::playRollLampAction(RollLampType rollLampType)
{
	//ActionTimeline* actionCommon;
	//ActionTimeline* action;
	finishRollLampAction();
	switch(rollLampType)
	{
	case RollLamp_Common:
		//nodeRollLampCommon = CSLoader::createNode(CommonRollLampFrameName);
		//nodeRollLampCommon->setLocalZOrder(LOGO_PIC_ZOrder - 1);
		//actionCommon = CSLoader::createTimeline(CommonRollLampFrameName);
		//actionCommon->gotoFrameAndPlay(0, FrameNumRollLampCommon, true);
		//nodeRollLampCommon->setPosition(Vec2(_center_x,_center_y + 10));
		//if(gameState == GameState::Game_Common)
		//{
		//	rootNode->addChild(nodeRollLampCommon);
		//}else if(gameState == GameState::Game_Reward)
		//{
		//	newMain->addChild(nodeRollLampCommon);
		//}
		//nodeRollLampCommon->runAction(actionCommon);
		nodeRollLampCommon->setVisible(true);
		break;
	case RollLamp_Win:
		//nodeRollLampWin = CSLoader::createNode(WinRollLampFrameName);
		//nodeRollLampWin->setLocalZOrder(LOGO_PIC_ZOrder - 1);
		//action = CSLoader::createTimeline(WinRollLampFrameName);
		//action->gotoFrameAndPlay(0, FrameNumRollLampWin, true);
		//nodeRollLampWin->setPosition(Vec2(_center_x,_center_y + 10));
		//if(gameState == GameState::Game_Common)
		//{
		//	rootNode->addChild(nodeRollLampWin);
		//}else if(gameState == GameState::Game_Reward)
		//{
		//	newMain->addChild(nodeRollLampWin);
		//}
		//nodeRollLampWin->runAction(action);
		nodeRollLampWin->setVisible(true);
		break;
	}
}

void MainScene::finishRollLampAction()
{
	if(nodeRollLampCommon)
	{
		nodeRollLampCommon->setVisible(false);
		//nodeRollLampCommon->stopAllActions();
		//nodeRollLampCommon->removeFromParent();
		//nodeRollLampCommon = NULL;
	}
	if(nodeRollLampWin)
	{
		nodeRollLampWin->setVisible(false);
		//nodeRollLampWin->stopAllActions();
		//nodeRollLampWin->removeFromParent();
		//nodeRollLampWin = NULL;
	}
}

ActionTimeline* MainScene::createRandRollActionByIndex(int index)
{
	Node* node;
	auto sp = (Sprite*)rootNode->getChildByTag(CARD_SPRITE_TAG + index);
	ActionTimeline* action;
	int _rand = rand()%8;  //产生一个随机数
	node = CSLoader::createNode(CardRollActionName[_rand]);
	action = CSLoader::createTimeline(CardRollActionName[_rand]);
	node->setPosition(Vec2(sp->getPosition()));
	rootNode->addChild(node);
	node->setTag(CARD_ACTION_TAG + index);
	return action;
}

void MainScene::actionCardRollCallBack()
{
	//int a[15]={3,2,8,3,2,7,6,2,4,3,2,5,7,2,8};//1连线
	auto node = rootNode->getChildByTag(CARD_ACTION_TAG + actionCardIndex);
	Point pt = node->getPosition();
	int tag = node->getTag();
	node->removeFromParent();
	auto nodeSp = CSLoader::createNode(CardSpringbackActionName[cardType[actionCardIndex]]);
	nodeSp->setPosition(Vec2(pt));
	rootNode->addChild(nodeSp);
	nodeSp->setTag(tag);
	auto action = CSLoader::createTimeline(CardSpringbackActionName[cardType[actionCardIndex]]);
	action->gotoFrameAndPlay(0, FrameNumCardSpring, false);
	action->setLastFrameCallFunc(std::bind(&MainScene::actionCardSpringback, this,nodeSp));
	nodeSp->runAction(action);
}



void MainScene::actionCardSpringback(Node* node)
{
	//bCardRollEnd[actionCardIndex]=true;
	node->removeFromParent();
	auto sp = (Sprite*)rootNode->getChildByTag(CARD_SPRITE_TAG + actionCardIndex);
	Point pt = sp->getPosition();
	sp->removeFromParent();
	initCardSprite(cardType[actionCardIndex],pt,CARD_SPRITE_TAG + actionCardIndex);
	actionCardIndex++;
	if(actionCardIndex < CARD_MAX)
	{
		actionCardRollCallBack();
	}else
	{
		checkWinOnLine();
		isCardRuning = false;
		finishRollLampAction();
		return;
	}
}

void MainScene::stopAllCardRoll()
{
	int i;
	actionCardIndex = 0;
	for(i = 0;i < CARD_MAX;i++)
	{
		auto node = rootNode->getChildByTag(CARD_ACTION_TAG + i);
		if(node)
		{
			node->stopAllActions();
			Point pt = node->getPosition();
			int tag = node->getTag();
			node->removeFromParent();
			//--------------------------
			//cardType[i] = winRand[9][i];
			//---------------------------
			auto nodeSp = CSLoader::createNode(CardSpringbackActionName[cardType[i]]);
			nodeSp->setPosition(Vec2(pt));
			rootNode->addChild(nodeSp);
			nodeSp->setTag(tag);
			auto action = CSLoader::createTimeline(CardSpringbackActionName[cardType[i]]);
			action->gotoFrameAndPlay(0, FrameNumCardSpring, false);
			action->setLastFrameCallFunc(std::bind(&MainScene::stopAllCardRollCallBack, this,nodeSp,i));
			nodeSp->runAction(action);
		}

		//if(!bCardRollEnd[i])
		//{
		//	bCardRollEnd[i]=true;
		//}

	}
	finishRollLampAction();
}

void MainScene::stopAllCardRollCallBack(Node* node,int index)
{
	node->stopAllActions();
	node->removeFromParent();
	auto sp = (Sprite*)rootNode->getChildByTag(CARD_SPRITE_TAG + index);
	Point pt = sp->getPosition();
	sp->removeFromParent();
	initCardSprite(cardType[index],pt,CARD_SPRITE_TAG + index);
	if(index == CARD_MAX - 1)
	{
		isCardRuning = false;
		checkWinOnLine();
	}
}
void MainScene::initGrayCardSprite()
{
	for(int i = 0; i < CARD_MAX;i++)
	{
		auto spCard = rootNode->getChildByTag(CARD_SPRITE_TAG + i);
		auto spGrayCard = Sprite::create(GrayCardPicName[cardType[i]]);
		spGrayCard->setPosition(Vec2(spCard->getPosition()));
		spGrayCard->setLocalZOrder(GRAY_CARD_LOCAL_ZOrder);
		spGrayCard->setTag(GRAY_CARD_TAG + i);
		spGrayCard->setVisible(false);
		rootNode->addChild(spGrayCard);

//		Sprite* spCard3DBg = Sprite::create(Card3DBgPicName[cardType[i]]);
		Sprite* spCard3DBg = Sprite::createWithSpriteFrameName(Card3DBgPicName[cardType[i]]);
		spCard3DBg->setPosition(Vec2(spCard->getPosition()));
		spCard3DBg->setLocalZOrder(CARD_3D_BG_CARD_LOCAL_ZOrder);
		spCard3DBg->setTag(CARD_3D_BG_TAG + i);
		spCard3DBg->setVisible(false);
		rootNode->addChild(spCard3DBg);

	}
}

void MainScene::checkWinOnLine()
{
	int i,beginLineIndex;
	bool b;
	coin = 0;
	bRewardMarie = false;
	beginLineIndex = -1;
	isOverallWin = false;
	b = isOverallWinCard();
	if(b)
	{
		beginLineIndex = 0;
		isOverallWin = true;
	}else
	{
		for(i = 0; i < LINE_MAX; i++)
		{
			switch (i)
			{
			case 0:
				b = isGameWinOnTheLine(0,vecCardLine_01,CardLineIndex_01);
				if(b && beginLineIndex < 0)
				{
					beginLineIndex = i;
				}
				break;
			case 1:
				b = isGameWinOnTheLine(1,vecCardLine_02,CardLineIndex_02);
				if(b && beginLineIndex < 0)
				{
					beginLineIndex = i;
				}
				break;
			case 2:
				b = isGameWinOnTheLine(2,vecCardLine_03,CardLineIndex_03);
				if(b && beginLineIndex < 0)
				{
					beginLineIndex = i;
				}
				break;
			case 3:
				b = isGameWinOnTheLine(3,vecCardLine_04,CardLineIndex_04);
				if(b && beginLineIndex < 0)
				{
					beginLineIndex = i;
				}
				break;
			case 4:
				b = isGameWinOnTheLine(4,vecCardLine_05,CardLineIndex_05);
				if(b && beginLineIndex < 0)
				{
					beginLineIndex = i;
				}
				break;
			case 5:
				b = isGameWinOnTheLine(5,vecCardLine_06,CardLineIndex_06);
				if(b && beginLineIndex < 0)
				{
					beginLineIndex = i;
				}
				break;
			case 6:
				b = isGameWinOnTheLine(6,vecCardLine_07,CardLineIndex_07);
				if(b && beginLineIndex < 0)
				{
					beginLineIndex = i;
				}
				break;
			case 7:
				b = isGameWinOnTheLine(7,vecCardLine_08,CardLineIndex_08);
				if(b && beginLineIndex < 0)
				{
					beginLineIndex = i;
				}
				break;
			case 8:
				b = isGameWinOnTheLine(8,vecCardLine_09,CardLineIndex_09);
				if(b && beginLineIndex < 0)
				{
					beginLineIndex = i;
				}
				break;
			default:
				break;
			}
		}
	}
	if(beginLineIndex >= 0)
	{
		initGrayCardSprite();
		spBtnStartGrayPic->setVisible(true);
		chkStart->setEnabled(false);
		playLineAction(beginLineIndex);
		playRollLampAction(RollLamp_Win);
	}else{
		//spBtnStartGrayPic->setVisible(false);
		//chkStart->setEnabled(true);
		//chkStart->setSelected(false);
		if(gameState == GameState::Game_Reward)
		{
			marieCard3DActionEndCheck();
//			if(marieGameNum <= 0)
//			{
//				marieGameNum = 0;
//				bRewardMarie = false;
//				gameState = GameState::Game_Common;
//				newMain->setVisible(false);
//				nodeUpLogoLight->setVisible(false);
////				nodeStickBottom->setVisible(true);
//				nodeButtomLogoLight->setVisible(true);
//				spLogoPic->setVisible(true);
//				marieLight->stopAllActions();
//				marieLight->removeFromParent();
//			}
		}else
		{
			resetGameDateByCardActionEnd();
		}
	}
}

bool MainScene::isOverallWinCard()
{
	int i;
	int index01_card = cardType[0];
	for(i = 1; i < CARD_MAX; i++)
	{
		if(cardType[i] != index01_card)
		{
			return false;
		}
	}
	for(i = 0; i < 9; i++)
	{
		bWinLine[i] = true;
	}
	vecCardLine_01.clear();
	vecCardLine_02.clear();
	vecCardLine_03.clear();
	vecCardLine_04.clear();
	vecCardLine_05.clear();
	vecCardLine_06.clear();
	vecCardLine_07.clear();
	vecCardLine_08.clear();
	vecCardLine_09.clear();
	for(i = 0; i < 5; i++)
	{
		vecCardLine_01.push_back(CardLineIndex_01[i]);
		vecCardLine_02.push_back(CardLineIndex_02[i]);
		vecCardLine_03.push_back(CardLineIndex_03[i]);
		vecCardLine_04.push_back(CardLineIndex_04[i]);
		vecCardLine_05.push_back(CardLineIndex_05[i]);
		vecCardLine_06.push_back(CardLineIndex_06[i]);
		vecCardLine_07.push_back(CardLineIndex_07[i]);
		vecCardLine_08.push_back(CardLineIndex_08[i]);
		vecCardLine_09.push_back(CardLineIndex_09[i]);
	}
	if(index01_card == OMNIPOTENT_CARD)
	{
		bRewardMarie = true;
		chkStart->setEnabled(false);
		marieGameNum = marieGameNum + 27;

	//	marieGameNum = 1;
	}
	statisticsCardWinLine(index01_card,6);
	return true;
}

bool MainScene::isGameWinOnTheLine(int indexLine ,std::vector<int> &vecCardLine,const int *CardLineIndex)
{
	int i,size,commonCradLine;
	std::vector<int> vec;
	vec.clear();
	vecCardLine.clear();
	for(i = 0;i < CARD_ARR_COL;i++)
	{
		vec.push_back(cardType[CardLineIndex[i]]);
	}
	commonCradLine = commonCardInTheCardLine(vec);
	for(i = 0;i < CARD_ARR_COL;i++)
	{
		if (cardType[CardLineIndex[i]] == commonCradLine || 
			cardType[CardLineIndex[i]] ==OMNIPOTENT_CARD)
		{
			vecCardLine.push_back(CardLineIndex[i]);
		}else
		{
			break;
		}
	}
	size = vecCardLine.size();
	if(size >= 3)
	{
		checkRewardPetiteMarie(indexLine,vecCardLine);
		statisticsCardWinLine(commonCradLine,size);
		//countThisGameScore(commonCradLine,size);
		bWinLine[indexLine] = true;
		return true;
	}
	vec.clear();
	vecCardLine.clear();
	for(i = CARD_ARR_COL - 1;i >= 0;i--)
	{
		vec.push_back(cardType[CardLineIndex[i]]);
	}
	commonCradLine = commonCardInTheCardLine(vec);
	for(i = CARD_ARR_COL - 1;i >= 0;i--)
	{
		if (cardType[CardLineIndex[i]] == commonCradLine || 
			cardType[CardLineIndex[i]] ==OMNIPOTENT_CARD)
		{
			vecCardLine.push_back(CardLineIndex[i]);
		}else
		{
			break;
		}
	}
	size = vecCardLine.size();
	if(size >= 3)
	{
		checkRewardPetiteMarie(indexLine,vecCardLine);
		statisticsCardWinLine(commonCradLine,size);
		//countThisGameScore(commonCradLine,size);
		bWinLine[indexLine] = true;
		return true;
	}
	vec.clear();
	vecCardLine.clear();

	return false;
}
void MainScene::statisticsCardWinLine(int card, int lineSize)
{
	int indexKey = card*4 + lineSize - 3;
	GameManager::getInstance()->statistics[indexKey]++;
	GameManager::getInstance()->saveData();
}
void MainScene::playLineAction(int lineIndex)
{
	if(bWinLine[lineIndex])
	{
		isGameEnd = true;
		auto nodeSp = CSLoader::createNode(EffectLineActionName[lineIndex]);
		nodeSp->setPosition(Vec2(_center_x,_center_y));
		nodeSp->setLocalZOrder(LINE_LOCAL_ZOrder);
		rootNode->addChild(nodeSp);
		auto action = CSLoader::createTimeline(EffectLineActionName[lineIndex]);
		action->gotoFrameAndPlay(0, FrameNumCardLine, false);
		action->setLastFrameCallFunc(std::bind(&MainScene::playLineActionCallBack, this, nodeSp, lineIndex));
		nodeSp->runAction(action);
		addBoxNodeByLineIndex(lineIndex);
		return;
	}else{
		Node* node = NULL;
		playLineActionCallBack(node,lineIndex);
	}
}
void MainScene::playLineActionCallBack(Node* node,int index)
{
	if(node)
	{
		node->removeFromParent();
	}
	if(index < LINE_MAX - 1)
	{
		int nextIndex = index + 1;
		playLineAction(nextIndex);
	}else{
		//clearAllCardAboveSprite();
		addCard3D();
	}
}
void MainScene::clearAllCardAboveSprite()
{
	int i;
	for(i = 0; i < CARD_MAX*LINE_MAX;i++)
	{
		auto spBox = rootNode->getChildByTag(BOX_ACTION_TAG + i);
		if(spBox)
		{
			spBox->stopAllActions();
			spBox->removeFromParent();
		}
	}
	for(i = 0; i < CARD_MAX;i++)
	{
		auto spGrayCard = rootNode->getChildByTag(GRAY_CARD_TAG + i);
		auto spCard3DBg = rootNode->getChildByTag(CARD_3D_BG_TAG + i);
		//auto spLight = rootNode->getChildByTag(LIGHT_ACTION_TAG + i);
		if(spCard3DBg)
		{
			spCard3DBg->stopAllActions();
			spCard3DBg->removeFromParent();
		}
		if(spGrayCard)
		{
			spGrayCard->removeFromParent();
		}
		//if(spLight)
		//{
		//	spLight->removeFromParent();
		//}
	}
}

void MainScene::addBoxNodeByLineIndex(int index)
{
	for(int i = 0; i < CARD_MAX*LINE_MAX;i++)
	{
		auto spBox = rootNode->getChildByTag(BOX_ACTION_TAG + i);
		if(spBox)
		{
			spBox->stopAllActions();
			spBox->removeFromParent();
		}
	}
	switch(index)
	{
	case 0:
		initBoxNodeByVecLine(vecCardLine_01,0);
		addGrayCardByCardLine(vecCardLine_01);
		initLightNodeByVecLine(vecCardLine_01);
		countThisGameScore(vecCardLine_01);
		break;
	case 1:
		initBoxNodeByVecLine(vecCardLine_02,1);
		addGrayCardByCardLine(vecCardLine_02);
		initLightNodeByVecLine(vecCardLine_02);
		countThisGameScore(vecCardLine_02);
		break;
	case 2:
		initBoxNodeByVecLine(vecCardLine_03,2);
		addGrayCardByCardLine(vecCardLine_03);
		initLightNodeByVecLine(vecCardLine_03);
		countThisGameScore(vecCardLine_03);
		break;
	case 3:
		initBoxNodeByVecLine(vecCardLine_04,3);
		addGrayCardByCardLine(vecCardLine_04);
		initLightNodeByVecLine(vecCardLine_04);
		countThisGameScore(vecCardLine_04);
		break;
	case 4:
		initBoxNodeByVecLine(vecCardLine_05,4);
		addGrayCardByCardLine(vecCardLine_05);
		initLightNodeByVecLine(vecCardLine_05);
		countThisGameScore(vecCardLine_05);
		break;
	case 5:
		initBoxNodeByVecLine(vecCardLine_06,5);
		addGrayCardByCardLine(vecCardLine_06);
		initLightNodeByVecLine(vecCardLine_06);
		countThisGameScore(vecCardLine_06);
		break;
	case 6:
		initBoxNodeByVecLine(vecCardLine_07,6);
		addGrayCardByCardLine(vecCardLine_07);
		initLightNodeByVecLine(vecCardLine_07);
		countThisGameScore(vecCardLine_07);
		break;
	case 7:
		initBoxNodeByVecLine(vecCardLine_08,7);
		addGrayCardByCardLine(vecCardLine_08);
		initLightNodeByVecLine(vecCardLine_08);
		countThisGameScore(vecCardLine_08);
		break;
	case 8:
		initBoxNodeByVecLine(vecCardLine_09,8);
		addGrayCardByCardLine(vecCardLine_09);
		initLightNodeByVecLine(vecCardLine_09);
		countThisGameScore(vecCardLine_09);
		break;
	}
}
void MainScene:: initLightNodeByVecLine(std::vector<int> &vec)
{
	int i,id,size;
	Node* nodeLight;
	Point pt;
	Sprite* sp;
	ActionTimeline* actionLight;
	size = vec.size();
	for(i = 0; i < size; i++)
	{
		id = vec.at(i);
		auto sp = (Sprite*)rootNode->getChildByTag(CARD_SPRITE_TAG + id);
		pt = sp->getPosition();
		nodeLight = CSLoader::createNode(FrameNameLight);
		nodeLight->setPosition(Vec2(pt));
		nodeLight->setLocalZOrder(LIGHT_LOCAL_ZOrder);
	//	nodeLight->setTag(LIGHT_ACTION_TAG + cardIndex);
		rootNode->addChild(nodeLight);
		actionLight = CSLoader::createTimeline(FrameNameLight);
		actionLight->gotoFrameAndPlay(0, FrameNumLight, false);
		actionLight->setLastFrameCallFunc(std::bind(&MainScene::playLightActionCallBack, this, nodeLight,id));
		nodeLight->runAction(actionLight);
	}
}
void MainScene::initBoxNodeByVecLine(std::vector<int> &vec,int indexLine)
{
	int i,size,id;
	Node* nodeBox;
	ActionTimeline* actionBox;
	size = vec.size();
	for(i = 0; i < size; i++)
	{
		id = vec.at(i);
		switch(size)
		{
		case 3:
			nodeBox = CSLoader::createNode(FrameNameBoxNodeType_01);
			actionBox = CSLoader::createTimeline(FrameNameBoxNodeType_01);
			initBoxNodeAndPlayAction(nodeBox,actionBox,id,indexLine);
			break;
		case 4:
			nodeBox = CSLoader::createNode(FrameNameBoxNodeType_02);
			actionBox = CSLoader::createTimeline(FrameNameBoxNodeType_02);
			initBoxNodeAndPlayAction(nodeBox,actionBox,id,indexLine);
			break;
		case 5:
			nodeBox = CSLoader::createNode(FrameNameBoxNodeType_03);
			actionBox = CSLoader::createTimeline(FrameNameBoxNodeType_03);
			initBoxNodeAndPlayAction(nodeBox,actionBox,id,indexLine);
			break;
		}
	}
}
void MainScene::initBoxNodeAndPlayAction(Node* nodeBox,ActionTimeline* actionBox,int cardIndex,int indexLine)
{
	Point pt;
	Sprite* sp;
	sp = (Sprite*)rootNode->getChildByTag(CARD_SPRITE_TAG + cardIndex);
	pt = sp->getPosition();
	nodeBox->setPosition(Vec2(pt));
	nodeBox->setLocalZOrder(BOX_LOCAL_ZOrder);
	nodeBox->setTag(BOX_ACTION_TAG + cardIndex + indexLine*CARD_MAX);
	rootNode->addChild(nodeBox);
	actionBox->gotoFrameAndPlay(0, FrameNumCardBox, true);
	nodeBox->runAction(actionBox);
	//-----------------
}
void MainScene::playLightActionCallBack(Node* node,int index)
{
	node->stopAllActions();
	node->removeFromParent();
}
void MainScene::addGrayCardByCardLine(std::vector<int> &vec)
{
	int i,j;
	bool bContinue = false;;
	for(i = 0; i < CARD_MAX;i++)
	{
		auto spGrayCard = rootNode->getChildByTag(GRAY_CARD_TAG + i);
		auto spCard3DBg = rootNode->getChildByTag(CARD_3D_BG_TAG + i);
		if(spGrayCard)
		{
			spGrayCard->setVisible(true);
		}
		if(spCard3DBg)
		{
			spCard3DBg->stopAllActions();
			spCard3DBg->setVisible(false);
		}
	}
	for(i = 0; i < CARD_MAX;i++)
	{
		for(j = 0; j < vec.size(); j++)
		{
			int id = vec.at(j);
			if(i == id)
			{
				auto spGrayCard = rootNode->getChildByTag(GRAY_CARD_TAG + i);
				auto spCard3DBg = rootNode->getChildByTag(CARD_3D_BG_TAG + i);
				if(spCard3DBg)
				{
					spCard3DBg->stopAllActions();
					spCard3DBg->setVisible(true);
				}
				if(spGrayCard)
				{
					spGrayCard->setVisible(false);
					break;
				}
			}
		}
	}
}

void MainScene::addCard3D()
{
	int i;
	for(i = 0; i < CARD_MAX*LINE_MAX;i++)
	{
		auto spBox = rootNode->getChildByTag(BOX_ACTION_TAG + i);
		if(spBox)
		{
			spBox->removeFromParent();
		}
	}
	//clearAllCardAboveSprite();
	for(i = 0; i < LINE_MAX; i++)
	{
		if(bWinLine[i])
		{
			switch(i)
			{
			case 0:
				initCard3DNodeByVecLine(vecCardLine_01);
				initBoxNodeByVecLine(vecCardLine_01,0);
				break;
			case 1:
				initCard3DNodeByVecLine(vecCardLine_02);
				initBoxNodeByVecLine(vecCardLine_02,1);
				break;
			case 2:
				initCard3DNodeByVecLine(vecCardLine_03);
				initBoxNodeByVecLine(vecCardLine_03,2);
				break;
			case 3:
				initCard3DNodeByVecLine(vecCardLine_04);
				initBoxNodeByVecLine(vecCardLine_04,3);
				break;
			case 4:
				initCard3DNodeByVecLine(vecCardLine_05);
				initBoxNodeByVecLine(vecCardLine_05,4);
				break;
			case 5:
				initCard3DNodeByVecLine(vecCardLine_06);
				initBoxNodeByVecLine(vecCardLine_06,5);
				break;
			case 6:
				initCard3DNodeByVecLine(vecCardLine_07);
				initBoxNodeByVecLine(vecCardLine_07,6);
				break;
			case 7:
				initCard3DNodeByVecLine(vecCardLine_08);
				initBoxNodeByVecLine(vecCardLine_08,7);
				break;
			case 8:
				initCard3DNodeByVecLine(vecCardLine_09);
				initBoxNodeByVecLine(vecCardLine_09,8);
				break;
			}
		}
	}
}
void MainScene::initCard3DNodeByVecLine(std::vector<int> &vec)
{
	int i,size,id;
	size = vec.size();
	for(i = 0; i < size; i++)
	{
		id = vec.at(i);
		if(!bCardActionNode[id])
		{
			bCardActionNode[id] = true;
			initCard3DNodeAndPlayAction(id);
		}
	}
}
void MainScene::initCard3DNodeAndPlayAction(int cardIndex)
{
	Node* nodeCard3D;
	ActionTimeline* actionCard3D;
	auto sp = (Sprite*)rootNode->getChildByTag(CARD_SPRITE_TAG + cardIndex);
	switch(gameState)
	{
	case GameState::Game_Common:
		nodeCard3D = CSLoader::createNode(Card3DActionName[cardType[cardIndex]]);
//		nodeCard3D = CSLoader::createNode("ef_test_02.csb");
		break;
	case GameState::Game_Reward:
		nodeCard3D = CSLoader::createNode(Card3DActionName2[cardType[cardIndex]]);
		break;
	}
	nodeCard3D->setPosition(Vec2(sp->getPosition()));
	nodeCard3D->setLocalZOrder(CARD_3D_LOCAL_ZOrder);
	nodeCard3D->setTag(CARD_3D_ACTION_TAG + cardIndex);
	rootNode->addChild(nodeCard3D);
	switch(gameState)
	{
	case GameState::Game_Common:
		actionCard3D = CSLoader::createTimeline(Card3DActionName[cardType[cardIndex]]);
//		actionCard3D = CSLoader::createTimeline("ef_test_02.csb");
		break;
	case GameState::Game_Reward:
		actionCard3D = CSLoader::createTimeline(Card3DActionName2[cardType[cardIndex]]);
		break;
	}
	actionCard3D->gotoFrameAndPlay(0, FrameNumCard3DAction, false);
	actionCard3D->setLastFrameCallFunc(std::bind(&MainScene::card3DActionCallBack, this, nodeCard3D,cardIndex));
	nodeCard3D->runAction(actionCard3D);
}
void MainScene::card3DActionCallBack(Node* node,int index)
{
	int i;
	node->stopAllActions();
	node->removeFromParent();
	bCardActionNode[index] = false;
	auto boxNode = rootNode->getChildByTag(BOX_ACTION_TAG + index);
	if(boxNode)
	{

		boxNode->stopAllActions();
		boxNode->removeFromParent();
	}
	for(i = 0; i < CARD_MAX;i++)
	{
		if(bCardActionNode[i])
		{
			return;
		}
	}
	for(i = 0; i < LINE_MAX; i++)
	{
		bWinLine[i] = false;
	}
	clearAllCardAboveSprite();
	finishRollLampAction();
	tmpClickType = -1;
	randWinLine = -1;
	tmpUpdateCoin = 0;
	isBeginUpdateCoin = true;
}
void MainScene::checkMarieGame()
{
	if(gameState == GameState::Game_Reward)
	{
		return;
	}
	isEnterMarieGameing = false;
	if(bRewardMarie)
	{

	layerColorEf =  LayerColor::create(Color4B(25, 25, 25, 125));
	this->addChild(layerColorEf);

		isCanPlayMarieGame = false;
		isEnterMarieGameing = true;
		gameState = GameState::Game_Reward;
		Node* node =  CSLoader::createNode(FrameOpenDoorAction);
		node->setPosition(Vec2(DISPLAY_CX,DISPLAY_CY));
		this->addChild(node);
		ActionTimeline* action = CSLoader::createTimeline(FrameOpenDoorAction);
		action->gotoFrameAndPlay(0, FrameNumOpenDoorAction, false);
		action->setLastFrameCallFunc(std::bind(&MainScene::actionCloseDoorCallBack, this, node));
		node->runAction(action);
	}
}
void MainScene::resetGameDateByCardActionEnd()
{
	if(!isEnterMarieGameing)
	{
		isGameEnd = false;
		if(!isAutoStart && !isEnterMarieGameing)
		{
			spBtnStartGrayPic->setVisible(false);
			chkStart->setEnabled(true);
			chkStart->setSelected(false);
		}
		//---------------------
		isGameRuning = false;
		resetGraySpGrayPic();
		//--------------------------
		checkAutoStartGame();
	}
}
void MainScene::initOpenDoorAction()
{
	nodeMarieNumScene->removeFromParent();
	Node* node =  CSLoader::createNode(FrameCloseDoorAction);
	node->setPosition(Vec2(DISPLAY_CX,DISPLAY_CY));
	this->addChild(node);
	ActionTimeline* action = CSLoader::createTimeline(FrameCloseDoorAction);
	action->gotoFrameAndPlay(0, FrameNumCloseDoorAction, false);
	action->setLastFrameCallFunc(std::bind(&MainScene::actionOpenDoorCallBack, this, node));
	node->runAction(action);
}
void MainScene::actionOpenDoorCallBack(Node* node)
{
	layerColorEf->removeFromParent();
	node->removeFromParent();
	returnCommonGame();
}
void MainScene::initMarieNumScene()
{
	
	layerColorEf =  LayerColor::create(Color4B(25, 25, 25, 125));
	this->addChild(layerColorEf);

	auto nodeNum =  CSLoader::createNode(FrameMarieNumScene);
	nodeMarieNumScene = (Node*)nodeNum->getChildByName("huojiang");
	nodeNum->setPosition(Vec2(DISPLAY_CX,DISPLAY_CY));
	this->addChild(nodeNum);
	//-------------------------------
	Node* node =  CSLoader::createNode(FrameFireworks);
	node->setPosition(Vec2(DISPLAY_CX,DISPLAY_CY));
	this->addChild(node);
	ActionTimeline* action = CSLoader::createTimeline(FrameFireworks);
	action->gotoFrameAndPlay(0, FrameNumFireworks, false);
	action->setLastFrameCallFunc(std::bind(&MainScene::actionFireworksCallBack, this, node));
	node->runAction(action);
	//--------------------------------
	initMarieNumAction();
}
void MainScene::initMarieNumAction()
{

	//layerColorEf =  LayerColor::create(Color4B(25, 25, 25, 125));
	//this->addChild(layerColorEf);

	auto spNum_01 = (Sprite*)nodeMarieNumScene->getChildByName("Sprite_8");
	auto spNum_02 = (Sprite*)nodeMarieNumScene->getChildByName("Sprite_7");
	auto spNum_03 = (Sprite*)nodeMarieNumScene->getChildByName("Sprite_6");
	auto spNum_04 = (Sprite*)nodeMarieNumScene->getChildByName("Sprite_5");
	auto spNum_05 = (Sprite*)nodeMarieNumScene->getChildByName("Sprite_4");
	auto spNum_06 = (Sprite*)nodeMarieNumScene->getChildByName("Sprite_3");
	auto node_01 =  CSLoader::createNode(FrameMarieNumAction);
	node_01->setPosition(Vec2(spNum_01->getPosition()));
	nodeMarieNumScene->addChild(node_01);
	ActionTimeline* action_01 = CSLoader::createTimeline(FrameMarieNumAction);
	action_01->gotoFrameAndPlay(0, FrameNumMarieNumAction, false);
	action_01->setLastFrameCallFunc(std::bind(&MainScene::actionMarieNumCallBack, this, node_01,countCoinDigit(5)));
	auto node_02 =  CSLoader::createNode(FrameMarieNumAction);
	node_02->setPosition(Vec2(spNum_02->getPosition()));
	nodeMarieNumScene->addChild(node_02);
	ActionTimeline* action_02 = CSLoader::createTimeline(FrameMarieNumAction);
	action_02->gotoFrameAndPlay(0, FrameNumMarieNumAction, false);
	action_02->setLastFrameCallFunc(std::bind(&MainScene::actionMarieNumCallBack, this, node_02,countCoinDigit(4)));
	auto node_03 =  CSLoader::createNode(FrameMarieNumAction);
	node_03->setPosition(Vec2(spNum_03->getPosition()));
	nodeMarieNumScene->addChild(node_03);
	ActionTimeline* action_03 = CSLoader::createTimeline(FrameMarieNumAction);
	action_03->gotoFrameAndPlay(0, FrameNumMarieNumAction, false);
	action_03->setLastFrameCallFunc(std::bind(&MainScene::actionMarieNumCallBack, this, node_03,countCoinDigit(3)));
	auto node_04 =  CSLoader::createNode(FrameMarieNumAction);
	node_04->setPosition(Vec2(spNum_04->getPosition()));
	nodeMarieNumScene->addChild(node_04);
	ActionTimeline* action_04 = CSLoader::createTimeline(FrameMarieNumAction);
	action_04->gotoFrameAndPlay(0, FrameNumMarieNumAction, false);
	action_04->setLastFrameCallFunc(std::bind(&MainScene::actionMarieNumCallBack, this, node_04,countCoinDigit(2)));
	auto node_05 =  CSLoader::createNode(FrameMarieNumAction);
	node_05->setPosition(Vec2(spNum_05->getPosition()));
	nodeMarieNumScene->addChild(node_05);
	ActionTimeline* action_05 = CSLoader::createTimeline(FrameMarieNumAction);
	action_05->gotoFrameAndPlay(0, FrameNumMarieNumAction, false);
	action_05->setLastFrameCallFunc(std::bind(&MainScene::actionMarieNumCallBack, this, node_05,countCoinDigit(1)));
	auto node_06 =  CSLoader::createNode(FrameMarieNumAction);
	node_06->setPosition(Vec2(spNum_06->getPosition()));
	nodeMarieNumScene->addChild(node_06);
	ActionTimeline* action_06 = CSLoader::createTimeline(FrameMarieNumAction);
	action_06->gotoFrameAndPlay(0, FrameNumMarieNumAction, false);
	action_06->setLastFrameCallFunc(std::bind(&MainScene::actionMarieNumCallBack, this, node_06,countCoinDigit(0)));
	node_01->runAction(action_01);
	node_02->runAction(action_02);
	node_03->runAction(action_03);
	node_04->runAction(action_04);
	node_05->runAction(action_05);
	node_06->runAction(action_06);
	spNum_01->removeFromParent();
	spNum_02->removeFromParent();
	spNum_03->removeFromParent();
	spNum_04->removeFromParent();
	spNum_05->removeFromParent();
	spNum_06->removeFromParent();

}
int MainScene::countCoinDigit(int digit)
{
	int _digit;
	switch(digit)
	{
	case 0:
		_digit = marieGameWinCoin % 10;//个位
		break;
	case 1:
		_digit = (marieGameWinCoin/10)%10;//十位
		break;
	case 2:
		_digit = (marieGameWinCoin/100)%10;//百位
		break;
	case 3:
		_digit = (marieGameWinCoin/1000)%10;//千位
		break;
	case 4:
		_digit = (marieGameWinCoin/10000)%10;//万位
		break;
	case 5:
		_digit = (marieGameWinCoin/100000)%10;//十万位
		break;
	}
	return _digit;
}
void MainScene::actionMarieNumCallBack(Node* node,int num)
{
	auto _node =  CSLoader::createNode(MarieNumSpringbackActionName[num]);
	_node->setPosition(Vec2(node->getPosition()));
	nodeMarieNumScene->addChild(_node);
	ActionTimeline* action = CSLoader::createTimeline(MarieNumSpringbackActionName[num]);
	action->gotoFrameAndPlay(0, FrameNumMarieNumSpringAction, false);
	action->setLastFrameCallFunc(std::bind(&MainScene::actionMarieNumSpringCallBack, this, _node,num));
	_node->runAction(action);
	node->removeFromParent();
}
void MainScene::actionMarieNumSpringCallBack(Node* node,int num)
{
//	auto spNum = Sprite::create(MarieNumPicName[num]);
	auto spNum = Sprite::createWithSpriteFrameName(MarieNumPicName[num]);
	spNum->setPosition(Vec2(node->getPosition()));
	nodeMarieNumScene->addChild(spNum);
	node->removeFromParent();
}
void MainScene::actionFireworksCallBack(Node* node)
{

	node->removeFromParent();
	initOpenDoorAction();
}
void MainScene::marieCard3DActionEndCheck()
{
//	marieGameNum--;
	if(marieGameNum <= 0)
	{
		initMarieNumScene();
		
	}else{
		resetGameDateByCardActionEnd();
	}
}
void MainScene::returnCommonGame()
{
	gameState = GameState::Game_Common;
	resetGameDateByCardActionEnd();
//---------------------------
	marieGameNum = 0;
	bRewardMarie = false;
	newMain->setVisible(false);
	nodeUpLogoLight->setVisible(false);
	nodeButtomLogoLight->setVisible(true);
//		nodeStickBottom->setVisible(true);
	spLogoPic->setVisible(true);
	marieLight->stopAllActions();
	marieLight->removeFromParent();
}	

void MainScene::actionCloseDoorCallBack(Node* node)
{
	layerColorEf->removeFromParent();

	marieGameWinCoin = 0;

	isCanPlayMarieGame = true;
	isEnterMarieGameing = false;
	//----------------------
	isGameEnd = false;
	if(!isAutoStart)
	{
		spBtnStartGrayPic->setVisible(false);
		chkStart->setEnabled(true);
		chkStart->setSelected(false);
	}
	chkStart->setEnabled(true);
	//---------------------
	isGameRuning = false;
	resetGraySpGrayPic();
	//---------------------------
	node->stopAllActions();
	node->removeFromParent();
	newMain->setVisible(true);
	nodeUpLogoLight->setVisible(true);
	nodeButtomLogoLight->setVisible(false);
//	nodeStickBottom->setVisible(false);
	spLogoPic->setVisible(false);
	marieLight =  CSLoader::createNode(FrameMarieLightAction);
	marieLight->setPosition(Vec2(DISPLAY_CX,DISPLAY_CY + 20));
	marieLight->setLocalZOrder(MARIE_LIGHT_ZOrder);
	marieLight->setTag(MARIE_LIGHT_TAG);
	rootNode->addChild(marieLight);
	ActionTimeline* action = CSLoader::createTimeline(FrameMarieLightAction);
	action->gotoFrameAndPlay(0, FrameNumMarieLightAction, true);
	marieLight->runAction(action);
	//--------------------------
	


	//checkAutoStartGame();

	if(isAutoStart)
	{
		startRunGame();
	}
}
int MainScene::commonCardInTheCardLine(std::vector<int> &vec)
{
	int size = vec.size();
	for(int i = 0; i < size; i++)
	{
		int card = vec.at(i);
		if(card != OMNIPOTENT_CARD)
		{
			return card;
		}
	}
	return OMNIPOTENT_CARD;
}

void MainScene::countThisGameScore(std::vector<int> &vecCardLine)
{
	int i,size,card,id,addCoin;
	if(isOverallWin)
	{
		card = cardType[0];
		addCoin = (overallWinReward[card]/5)*chargePoinMultiple[chargePointCnt][0];
	}else
	{
		size = vecCardLine.size();
		for(i = 0; i < size; i++)
		{
			id = vecCardLine.at(i);
			card = cardType[id];
			if(card != OMNIPOTENT_CARD)
			{
				break;
			}
		}
		addCoin = lineMultiple[card][size - 3]*chargePoinMultiple[chargePointCnt][0];
	}
	coin = coin + addCoin;
	totleCoin = totleCoin + addCoin;
	GameManager::getInstance()->winCoin = GameManager::getInstance()->winCoin + addCoin;

	if(isCanPlayMarieGame)
	{
		marieGameWinCoin = marieGameWinCoin + addCoin;
	}

	//GameManager::getInstance()->totleCoin = GameManager::getInstance()->totleCoin + addCoin;
	//GameManager::getInstance()->saveData();
}
 
void MainScene::checkRewardPetiteMarie(int indexLine,std::vector<int> &vecCardLine)
{
	//if(indexLine != 0 && indexLine!= 1 && indexLine != 2)
	//{
	//	return;
	//}
	int size = vecCardLine.size();
	if(size >= CARD_ARR_COL)
	{
		int tmpNum = 0;
		for(int i = 0; i < size; i++)
		{
			int id = vecCardLine.at(i);
			int card = cardType[id];
			if(card == OMNIPOTENT_CARD)
			{
				tmpNum++;
			}else 
			{
				//tmpNum = 0;
				break;
			}
		}
		if(tmpNum >= 3)
		{
			if(!bRewardMarie)
			{
				bRewardMarie = true;
				chkStart->setEnabled(false);
			}
			initMarieGameNum(tmpNum);
			return;
		}
		tmpNum = 0;
		for(int i = size - 1; i >= 0; i--)
		{
			int id = vecCardLine.at(i);
			int card = cardType[id];
			if(card == OMNIPOTENT_CARD)
			{
				tmpNum++;
			}else
			{
				//tmpNum = 0;
				break;
			}
		}
		if(tmpNum >= 3)
		{
			if(!bRewardMarie)
			{
				bRewardMarie = true;
				chkStart->setEnabled(false);
			}
			initMarieGameNum(tmpNum);
		}
	}else{
		int tmpNum = 0;
		for(int i = 0; i < size; i++)
		{
			int id = vecCardLine.at(i);
			int card = cardType[id];
			if(card == OMNIPOTENT_CARD)
			{
				tmpNum++;
			}else
			{
				//tmpNum = 0;
				break;
			}
			if(tmpNum >= 3)
			{
				if(!bRewardMarie)
				{
					bRewardMarie = true;
					chkStart->setEnabled(false);
				}
				initMarieGameNum(tmpNum);
			}
		}
	}
}

void MainScene::initMarieGameNum(int omnipotentCardNum)
{
	switch(omnipotentCardNum)
	{
	case 3:
		marieGameNum = marieGameNum + 2;
		GameManager::getInstance()->statistics[32]++;
		GameManager::getInstance()->saveData();
		break;
	case 4:
		marieGameNum = marieGameNum + 4;
		GameManager::getInstance()->statistics[33]++;
		GameManager::getInstance()->saveData();
		break;
	case 5:
		marieGameNum = marieGameNum + 6;
		break;
	}
//	marieGameNum = 1;
	
}

void MainScene::checkAutoStartGame()
{
	if(isAutoStart)
	{

		startRunGame();
	}
}


void MainScene::upDateCoinNum()
{
	if(isBeginUpdateCoin)
	{
		tmpUpdateCoin++;
		coin--;
		GameManager::getInstance()->totleCoin++;
		if(tmpUpdateCoin > COIN_UPDATE_TIME || coin <= 0)
		{
			isBeginUpdateCoin = false;
			GameManager::getInstance()->totleCoin = totleCoin;
			GameManager::getInstance()->saveData();
			coin = 0;
			//-----------------------------------
			switch(gameState)
			{
			case  GameState::Game_Common:
				checkMarieGame();
				resetGameDateByCardActionEnd();
				break;
			case  GameState::Game_Reward:
				if(isCanPlayMarieGame)
				{
					marieCard3DActionEndCheck();
				}
				break;
			}
		}
	}
}



