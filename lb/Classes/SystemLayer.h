//
//  VideoLayer.hpp
//  mxr
//
//  Created by imac on 15/11/16.
//
//

#ifndef SystemLayer_h
#define SystemLayer_h

#include "GameManager.h"

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include"cocostudio/CocoStudio.h"
using namespace cocos2d;
using namespace cocostudio::timeline;
using namespace ui;

USING_NS_CC;
class SystemLayer : public Layer
{
public:
    bool init();
    CREATE_FUNC(SystemLayer);
	void soundSliderChange(Ref* psender, SliderEventType type);
	void bgColorSliderChange(Ref* psender, SliderEventType type);
	void btnStatisticsCallback(Ref *pSender, Widget::TouchEventType type);
	void btnBackCallback(Ref *pSender, Widget::TouchEventType type);
	void btnTestCallback(Ref* pSender);
	void btnScoreCallback(Ref *pSender, Widget::TouchEventType type);

	void btnExchangeCoin_01(Ref *pSender, Widget::TouchEventType type);
	void btnExchangeCoin_02(Ref *pSender, Widget::TouchEventType type);
	void btnExchangeCoin_03(Ref *pSender, Widget::TouchEventType type);

	void btnAddScore_01(Ref *pSender, Widget::TouchEventType type);
	void btnAddScore_02(Ref *pSender, Widget::TouchEventType type);
	void btnAddScore_03(Ref *pSender, Widget::TouchEventType type);

	void btnSubScore_01(Ref *pSender, Widget::TouchEventType type);
	void btnSubScore_02(Ref *pSender, Widget::TouchEventType type);
	void btnSubScore_03(Ref *pSender, Widget::TouchEventType type);

};

#endif /* SystemLayer_hpp */
