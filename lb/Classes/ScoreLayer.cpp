//
//  VideoLayer.cpp
//  mxr
//
//  Created by imac on 15/11/16.
//
//
//#include  "cocos2d\external\win32-specific\icon\include\iconv.h"
#include "ScoreLayer.h"

#include "BarrierLayer.h"
#include "ui/CocosGUI.h"
#include"cocostudio/CocoStudio.h"
#include "SimpleAudioEngine.h"  
#include "Common.h"
#include<string>

using namespace CocosDenshion;
using namespace cocos2d;
using namespace cocostudio::timeline;
USING_NS_CC;
using namespace ui;
using namespace std;


#define ST_X (350)
#define ST_Y (800)
#define GAP_X (370)
#define GAP_Y (80)

//static  const char *CardLabelName[36] = {
//    "第01种卡牌3个的次数：",
//    "第01种卡牌4个的次数：",
//    "第01种卡牌5个的次数：",
//    "第01种卡牌满屏的次数：",
//    "第02种卡牌3个的次数：",
//    "第02种卡牌4个的次数：",
//    "第02种卡牌5个的次数：",
//    "第02种卡牌满屏的次数：",
//    "第03种卡牌3个的次数：",
//    "第03种卡牌4个的次数：",
//    "第03种卡牌5个的次数：",
//    "第03种卡牌满屏的次数：",
//    "第04种卡牌3个的次数：",
//    "第04种卡牌4个的次数：",
//    "第04种卡牌5个的次数：",
//    "第04种卡牌满屏的次数：",
//    "第05种卡牌3个的次数：",
//    "第05种卡牌4个的次数：",
//    "第05种卡牌5个的次数：",
//    "第05种卡牌满屏的次数：",
//    "第06种卡牌3个的次数：",
//    "第06种卡牌4个的次数：",
//    "第06种卡牌5个的次数：",
//    "第06种卡牌满屏的次数：",
//    "第07种卡牌3个的次数：",
//    "第07种卡牌4个的次数：",
//    "第07种卡牌5个的次数：",
//    "第07种卡牌满屏的次数：",
//    "第08种卡牌3个的次数：",
//    "第08种卡牌4个的次数：",
//    "第08种卡牌5个的次数：",
//    "第08种卡牌满屏的次数：",
//    "第09种卡牌3个的次数：",
//    "第09种卡牌4个的次数：",
//    "第09种卡牌5个的次数：",
//    "第09种卡牌满屏的次数：",
//};



bool ScoreLayer::init()
{
    if (!Layer::init())
        return false;
	char str[50];
	this->addChild(BarrierLayer::create());
	auto rootNode = CSLoader::createNode("xitong_shuzhi.csb");
	rootNode->setPosition(Vec2(DISPLAY_CX,DISPLAY_CY));
	this->addChild(rootNode);

	auto nodeAll = (Node*)rootNode->getChildByName("all");

    auto btnBack = (ui::Button*)nodeAll->getChildByName("Button_1");
	btnBack->addTouchEventListener(CC_CALLBACK_2(ScoreLayer::btnBackCallback,this));

	auto node_01 = (Node*)nodeAll->getChildByName("Node_1");
	auto lbWinCoin = (TextAtlas*)node_01->getChildByName("AtlasLabel_1");
	sprintf(str, "%d",GameManager::getInstance()->winCoin);
	lbWinCoin->setString(str);

	auto node_02 = (Node*)nodeAll->getChildByName("Node_2");
	auto lbTotleCoin = (TextAtlas*)node_02->getChildByName("AtlasLabel_2");
	sprintf(str, "%d",GameManager::getInstance()->coinOperated);
	lbTotleCoin->setString(str);

	auto node_03 = (Node*)nodeAll->getChildByName("Node_3");
	auto lbAddScore = (TextAtlas*)node_03->getChildByName("AtlasLabel_3");
	sprintf(str, "%d",GameManager::getInstance()->addScore);
	lbAddScore->setString(str);

	auto node_04 = (Node*)nodeAll->getChildByName("Node_4");
	auto lbSubScore = (TextAtlas*)node_04->getChildByName("AtlasLabel_4");
	sprintf(str, "%d",GameManager::getInstance()->subScore);
	lbSubScore->setString(str);

    return true;
}
void ScoreLayer::btnBackCallback(Ref *pSender, Widget::TouchEventType type)
{
	if(type == Widget::TouchEventType::ENDED)
	{
		this->removeFromParent();
	}
	//GameManager::getInstance()->gLubyte_alpha = ALPHA_ST_VALUE;

}