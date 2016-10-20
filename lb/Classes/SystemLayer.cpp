//
//  VideoLayer.cpp
//  mxr
//
//  Created by imac on 15/11/16.
//
//
#include "SystemLayer.h"
#include "StatisticsLayer.h"
#include "ScoreLayer.h"
#include "BarrierLayer.h"
#include "ui/CocosGUI.h"
#include"cocostudio/CocoStudio.h"
#include "SimpleAudioEngine.h"  
#include "Common.h"
using namespace CocosDenshion;
using namespace cocos2d;
using namespace cocostudio::timeline;
USING_NS_CC;
using namespace ui;
Node* rootNode;
//Text* alert;
bool SystemLayer::init()
{
    if (!Layer::init())
        return false;
	this->addChild(BarrierLayer::create());
	rootNode = CSLoader::createNode("xitong.csb");
	rootNode->setPosition(Vec2(DISPLAY_CX,DISPLAY_CY));
	this->addChild(rootNode);

	

	auto node = (Node*)rootNode->getChildByName("xitong");
	auto slider = (Slider*)node->getChildByName("Slider_1");
	int curPercent = GameManager::getInstance()->startVolume*100;
	slider->setPercent(curPercent);
	slider->addEventListenerSlider(this,sliderpercentchangedselector(SystemLayer::soundSliderChange));//添加回调函数

	auto slider_2 = (Slider*)node->getChildByName("Slider_2");
	slider_2->setPercent(GameManager::getInstance()->backLayerPercent);
	//if(GameManager::getInstance()->backLayerColor)
	//{
	//	slider_2->setPercent(GameManager::getInstance()->backLayerPercent);
	//}else{
	//	slider_2->setPercent(GameManager::getInstance()->backLayerPercent);
	//	//GameManager::getInstance()->backLayerColor = LayerColor::create(Color4B(25, 25, 25, 0));
	//	//GameManager::getInstance()->backLayerColor->setLocalZOrder(100);
	//	//getParent()->addChild(GameManager::getInstance()->backLayerColor);  
	//}
	slider_2->addEventListenerSlider(this,sliderpercentchangedselector(SystemLayer::bgColorSliderChange));//添加回调函数

    auto btnStatistics = (ui::Button*)node->getChildByName("Button_1");
	btnStatistics->addTouchEventListener(CC_CALLBACK_2(SystemLayer::btnStatisticsCallback,this));  

    auto btnBack = (ui::Button*)node->getChildByName("Button_11");
	btnBack->addTouchEventListener(CC_CALLBACK_2(SystemLayer::btnBackCallback,this));

    auto btnScore = (ui::Button*)node->getChildByName("Button_12");
	btnScore->addTouchEventListener(CC_CALLBACK_2(SystemLayer::btnScoreCallback,this));

    auto exchangeCoin_01 = (ui::Button*)node->getChildByName("Button_2");
	exchangeCoin_01->addTouchEventListener(CC_CALLBACK_2(SystemLayer::btnExchangeCoin_01,this));
    auto exchangeCoin_02 = (ui::Button*)node->getChildByName("Button_3");
	exchangeCoin_02->addTouchEventListener(CC_CALLBACK_2(SystemLayer::btnExchangeCoin_02,this));
    auto exchangeCoin_03 = (ui::Button*)node->getChildByName("Button_4");
	exchangeCoin_03->addTouchEventListener(CC_CALLBACK_2(SystemLayer::btnExchangeCoin_03,this));


    auto addScore_01 = (ui::Button*)node->getChildByName("Button_5");
	addScore_01->addTouchEventListener(CC_CALLBACK_2(SystemLayer::btnAddScore_01,this));
    auto addScore_02 = (ui::Button*)node->getChildByName("Button_6");
	addScore_02->addTouchEventListener(CC_CALLBACK_2(SystemLayer::btnAddScore_02,this));
    auto addScore_03 = (ui::Button*)node->getChildByName("Button_7");
	addScore_03->addTouchEventListener(CC_CALLBACK_2(SystemLayer::btnAddScore_03,this));

    auto subScore_01 = (ui::Button*)node->getChildByName("Button_8");
	subScore_01->addTouchEventListener(CC_CALLBACK_2(SystemLayer::btnSubScore_01,this));
    auto subScore_02 = (ui::Button*)node->getChildByName("Button_9");
	subScore_02->addTouchEventListener(CC_CALLBACK_2(SystemLayer::btnSubScore_02,this));
    auto subScore_03 = (ui::Button*)node->getChildByName("Button_10");
	subScore_03->addTouchEventListener(CC_CALLBACK_2(SystemLayer::btnSubScore_03,this));
    return true;
}
 
void SystemLayer::soundSliderChange(Ref* psender, SliderEventType type)
{
  if (type == SLIDER_PERCENTCHANGED) {
        Slider* slider = dynamic_cast<Slider*>(psender);
        int percent = slider->getPercent();
		float _volume = percent/(float)100;
		GameManager::getInstance()->startVolume = _volume;
		SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(_volume);
        //alert->setText(StringUtils::format("Percent %d",percent).c_str());
		GameManager::getInstance()->saveData();
    }
}
void SystemLayer::bgColorSliderChange(Ref* psender, SliderEventType type)
{
  if (type == SLIDER_PERCENTCHANGED) {
        Slider* slider = dynamic_cast<Slider*>(psender);
        int percent = slider->getPercent();
		GameManager::getInstance()->backLayerPercent = percent;
		float _volume = percent/(float)100;
		GameManager::getInstance()->gLubyte_alpha = MAX_ALPHA - _volume*MAX_ALPHA;
  //     if(GameManager::getInstance()->backLayerColor)
	 //  {
		//   GameManager::getInstance()->backLayerColor->removeFromParent();
		//   GameManager::getInstance()->backLayerColor = NULL;
	 //  }
		//GameManager::getInstance()->backLayerColor = LayerColor::create(Color4B(25, 25, 25, GameManager::getInstance()->gLubyte_alpha));
		//GameManager::getInstance()->backLayerColor->setLocalZOrder(100);
		//getParent()->addChild(GameManager::getInstance()->backLayerColor);   
		GameManager::getInstance()->backLayerColor->myUpdateColor(GameManager::getInstance()->gLubyte_alpha);
		GameManager::getInstance()->saveData();

    }
}

void SystemLayer::btnStatisticsCallback(Ref *pSender, Widget::TouchEventType type)
{
	if(type == Widget::TouchEventType::ENDED)
	{
		this->addChild(StatisticsLayer::create());
	}
}
void SystemLayer::btnBackCallback(Ref *pSender, Widget::TouchEventType type)
{
	if(type == Widget::TouchEventType::ENDED)
	{
		this->removeFromParent();
	}
}
void SystemLayer::btnScoreCallback(Ref *pSender, Widget::TouchEventType type)
{
	if(type == Widget::TouchEventType::ENDED)
	{
		this->addChild(ScoreLayer::create());
	}
}


void SystemLayer::btnExchangeCoin_01(Ref *pSender, Widget::TouchEventType type)
{
	if(type == Widget::TouchEventType::ENDED)
	{
		if(GameManager::getInstance()->exchangeCoin != DEFUALT_EXCHANGE_COIN)
		{
			GameManager::getInstance()->exchangeCoin = DEFUALT_EXCHANGE_COIN;
			GameManager::getInstance()->saveData();
		}
	}
}
void SystemLayer::btnExchangeCoin_02(Ref *pSender, Widget::TouchEventType type)
{
	if(type == Widget::TouchEventType::ENDED)
	{
		if(GameManager::getInstance()->exchangeCoin != EXCHANGE_COIN_02)
		{
			GameManager::getInstance()->exchangeCoin = EXCHANGE_COIN_02;
			GameManager::getInstance()->saveData();
		}
	}
}
void SystemLayer::btnExchangeCoin_03(Ref *pSender, Widget::TouchEventType type)
{
	if(type == Widget::TouchEventType::ENDED)
	{
		if(GameManager::getInstance()->exchangeCoin != EXCHANGE_COIN_03)
		{
			GameManager::getInstance()->exchangeCoin = EXCHANGE_COIN_03;
			GameManager::getInstance()->saveData();
		}
	}
}

void SystemLayer::btnAddScore_01(Ref *pSender, Widget::TouchEventType type)
{
	if(type == Widget::TouchEventType::ENDED)
	{
		int score = GameManager::getInstance()->totleCoin + ADD_SCORE_01;
		if(score <= MAX_TOTLE_SCORE)
		{
			GameManager::getInstance()->addScore = GameManager::getInstance()->addScore  + ADD_SCORE_01;
			GameManager::getInstance()->totleCoin = GameManager::getInstance()->totleCoin + ADD_SCORE_01;
			GameManager::getInstance()->saveData();
		}
	}

}
void SystemLayer::btnAddScore_02(Ref *pSender, Widget::TouchEventType type)
{
	if(type == Widget::TouchEventType::ENDED)
	{
		int score = GameManager::getInstance()->totleCoin + ADD_SCORE_02;
		if(score <= MAX_TOTLE_SCORE)
		{
			GameManager::getInstance()->addScore = GameManager::getInstance()->addScore  + ADD_SCORE_02;
			GameManager::getInstance()->totleCoin = GameManager::getInstance()->totleCoin + ADD_SCORE_02;
			GameManager::getInstance()->saveData();
		}
	}

}
void SystemLayer::btnAddScore_03(Ref *pSender, Widget::TouchEventType type)
{
	if(type == Widget::TouchEventType::ENDED)
	{
		int score = GameManager::getInstance()->totleCoin + ADD_SCORE_03;
		if(score <= MAX_TOTLE_SCORE)
		{
			GameManager::getInstance()->addScore = GameManager::getInstance()->addScore  + ADD_SCORE_03;
			GameManager::getInstance()->totleCoin = GameManager::getInstance()->totleCoin + ADD_SCORE_03;
			GameManager::getInstance()->saveData();
		}
	}
}

void SystemLayer::btnSubScore_01(Ref *pSender, Widget::TouchEventType type)
{
	if(type == Widget::TouchEventType::ENDED)
	{
		int score = GameManager::getInstance()->totleCoin - SUB_SCORE_01;
		if(score > 0)
		{
			GameManager::getInstance()->subScore = GameManager::getInstance()->subScore  + SUB_SCORE_01;
			GameManager::getInstance()->totleCoin = GameManager::getInstance()->totleCoin - SUB_SCORE_01;
			GameManager::getInstance()->saveData();
		}
	}
}

void SystemLayer::btnSubScore_02(Ref *pSender, Widget::TouchEventType type)
{
	if(type == Widget::TouchEventType::ENDED)
	{
		int score = GameManager::getInstance()->totleCoin - SUB_SCORE_02;
		if(score > 0)
		{
			GameManager::getInstance()->subScore = GameManager::getInstance()->subScore  + SUB_SCORE_02;
			GameManager::getInstance()->totleCoin = GameManager::getInstance()->totleCoin - SUB_SCORE_02;
			GameManager::getInstance()->saveData();
		}
	}
}
void SystemLayer::btnSubScore_03(Ref *pSender, Widget::TouchEventType type)
{
	if(type == Widget::TouchEventType::ENDED)
	{
		int score = GameManager::getInstance()->totleCoin - SUB_SCORE_03;
		if(score > 0)
		{
			GameManager::getInstance()->subScore = GameManager::getInstance()->subScore  + SUB_SCORE_03;
			GameManager::getInstance()->totleCoin = GameManager::getInstance()->totleCoin - SUB_SCORE_03;
			GameManager::getInstance()->saveData();
		}
	}

}