//
//  VideoLayer.hpp
//  mxr
//
//  Created by imac on 15/11/16.
//
//

#ifndef ScoreLayer_h
#define ScoreLayer_h

#include "GameManager.h"

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include"cocostudio/CocoStudio.h"
using namespace cocos2d;
using namespace cocostudio::timeline;
using namespace ui;

USING_NS_CC;
class ScoreLayer : public Layer
{
public:
    bool init();
    CREATE_FUNC(ScoreLayer);
	void btnBackCallback(Ref *pSender, Widget::TouchEventType type);
};

#endif /* StatisticsLayer_hpp */
