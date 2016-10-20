//
//  VideoLayer.hpp
//  mxr
//
//  Created by imac on 15/11/16.
//
//

#ifndef StatisticsLayer_h
#define StatisticsLayer_h

#include "GameManager.h"

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include"cocostudio/CocoStudio.h"
using namespace cocos2d;
using namespace cocostudio::timeline;
using namespace ui;

USING_NS_CC;
class StatisticsLayer : public Layer
{
public:
    bool init();
    CREATE_FUNC(StatisticsLayer);
	void btnBackCallback(Ref *pSender, Widget::TouchEventType type);
	//int GBKToUTF8(std::string &gbkStr,const char* toCode,const char* formCode);
	void initLabelNumCard();
public:
	Node* rootNode;

	TextAtlas* lbWinCoin;
	TextAtlas* lbTotleCoin;

	TextAtlas* lbNumCard01_01;
	TextAtlas* lbNumCard01_02;
	TextAtlas* lbNumCard01_03;
	TextAtlas* lbNumCard01_04;

	TextAtlas* lbNumCard02_01;
	TextAtlas* lbNumCard02_02;
	TextAtlas* lbNumCard02_03;
	TextAtlas* lbNumCard02_04;

	TextAtlas* lbNumCard03_01;
	TextAtlas* lbNumCard03_02;
	TextAtlas* lbNumCard03_03;
	TextAtlas* lbNumCard03_04;

	TextAtlas* lbNumCard04_01;
	TextAtlas* lbNumCard04_02;
	TextAtlas* lbNumCard04_03;
	TextAtlas* lbNumCard04_04;

	TextAtlas* lbNumCard05_01;
	TextAtlas* lbNumCard05_02;
	TextAtlas* lbNumCard05_03;
	TextAtlas* lbNumCard05_04;

	TextAtlas* lbNumCard06_01;
	TextAtlas* lbNumCard06_02;
	TextAtlas* lbNumCard06_03;
	TextAtlas* lbNumCard06_04;

	TextAtlas* lbNumCard07_01;
	TextAtlas* lbNumCard07_02;
	TextAtlas* lbNumCard07_03;
	TextAtlas* lbNumCard07_04;

	TextAtlas* lbNumCard08_01;
	TextAtlas* lbNumCard08_02;
	TextAtlas* lbNumCard08_03;
	TextAtlas* lbNumCard08_04;

	TextAtlas* lbNumCard09_01;
	TextAtlas* lbNumCard09_02;
	TextAtlas* lbNumCard09_03;
	TextAtlas* lbNumCard09_04;

};

#endif /* StatisticsLayer_hpp */
