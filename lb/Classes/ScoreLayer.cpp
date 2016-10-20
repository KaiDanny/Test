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
//    "��01�ֿ���3���Ĵ�����",
//    "��01�ֿ���4���Ĵ�����",
//    "��01�ֿ���5���Ĵ�����",
//    "��01�ֿ��������Ĵ�����",
//    "��02�ֿ���3���Ĵ�����",
//    "��02�ֿ���4���Ĵ�����",
//    "��02�ֿ���5���Ĵ�����",
//    "��02�ֿ��������Ĵ�����",
//    "��03�ֿ���3���Ĵ�����",
//    "��03�ֿ���4���Ĵ�����",
//    "��03�ֿ���5���Ĵ�����",
//    "��03�ֿ��������Ĵ�����",
//    "��04�ֿ���3���Ĵ�����",
//    "��04�ֿ���4���Ĵ�����",
//    "��04�ֿ���5���Ĵ�����",
//    "��04�ֿ��������Ĵ�����",
//    "��05�ֿ���3���Ĵ�����",
//    "��05�ֿ���4���Ĵ�����",
//    "��05�ֿ���5���Ĵ�����",
//    "��05�ֿ��������Ĵ�����",
//    "��06�ֿ���3���Ĵ�����",
//    "��06�ֿ���4���Ĵ�����",
//    "��06�ֿ���5���Ĵ�����",
//    "��06�ֿ��������Ĵ�����",
//    "��07�ֿ���3���Ĵ�����",
//    "��07�ֿ���4���Ĵ�����",
//    "��07�ֿ���5���Ĵ�����",
//    "��07�ֿ��������Ĵ�����",
//    "��08�ֿ���3���Ĵ�����",
//    "��08�ֿ���4���Ĵ�����",
//    "��08�ֿ���5���Ĵ�����",
//    "��08�ֿ��������Ĵ�����",
//    "��09�ֿ���3���Ĵ�����",
//    "��09�ֿ���4���Ĵ�����",
//    "��09�ֿ���5���Ĵ�����",
//    "��09�ֿ��������Ĵ�����",
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