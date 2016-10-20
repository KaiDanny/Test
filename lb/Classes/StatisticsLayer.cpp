//
//  VideoLayer.cpp
//  mxr
//
//  Created by imac on 15/11/16.
//
//
//#include  "cocos2d\external\win32-specific\icon\include\iconv.h"
#include "StatisticsLayer.h"

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



bool StatisticsLayer::init()
{
    if (!Layer::init())
        return false;
	char str[50];
	this->addChild(BarrierLayer::create());
	rootNode = CSLoader::createNode("xitong_tongji.csb");
	rootNode->setPosition(Vec2(DISPLAY_CX,DISPLAY_CY));
	this->addChild(rootNode);
	auto node = (Node*)rootNode->getChildByName("tongji");
    auto btnBack= (ui::Button*)node->getChildByName("Button_1");
	btnBack->addTouchEventListener(CC_CALLBACK_2(StatisticsLayer::btnBackCallback,this));  

	//lbTotleCoin = (TextAtlas*)node->getChildByName("AtlasLabel_1");
	//sprintf(str, "%d",GameManager::getInstance()->totleCoin);
	//lbTotleCoin->setString(str);

	//lbWinCoin = (TextAtlas*)node->getChildByName("AtlasLabel_2");
	//sprintf(str, "%d",GameManager::getInstance()->totleCoin);
	//lbWinCoin->setString(str);
	initLabelNumCard();

	//for(int i = 0; i < 36; i++)
	//{
	//	int row,col;
	//	float x,y;
	//	char str_01[50];
	//	char str_02[50];
	//	row = i/4;
	//	col = i - 4*row;
	//	x = ST_X + GAP_X*col;
	//	y = ST_Y - row*GAP_Y;
	//	int num = GameManager::getInstance()->statistics[i];
	//	sprintf(str_01,"%d",num);
	//	sprintf(str_02, "%s%s", CardLabelName[i], str_01); 
	//	std::string star_str = std::string(str_02);//先定义一个string
	//	GBKToUTF8(star_str,"gb2312","utf-8");
	//	auto m_label = LabelTTF::create(star_str,"Arial",25);//创建一个label
	//	m_label->setPosition(Point(x,y));
	//	this->addChild(m_label,2);
	//}

    return true;
}
void StatisticsLayer::initLabelNumCard()
{
	char str[50];
	auto nodeCard_01 = (Node*)rootNode->getChildByName("shuzi_er");
	lbNumCard01_01 = (TextAtlas*)nodeCard_01->getChildByName("AtlasLabel_3");
	sprintf(str, "%d",GameManager::getInstance()->statistics[0]);
	lbNumCard01_01->setString(str);
	//------------
	lbNumCard01_02 = (TextAtlas*)nodeCard_01->getChildByName("AtlasLabel_4");
	sprintf(str, "%d",GameManager::getInstance()->statistics[1]);
	lbNumCard01_02->setString(str);
	//------------
	lbNumCard01_03 = (TextAtlas*)nodeCard_01->getChildByName("AtlasLabel_5");
	sprintf(str, "%d",GameManager::getInstance()->statistics[2]);
	lbNumCard01_03->setString(str);
	//------------
	lbNumCard01_04 = (TextAtlas*)nodeCard_01->getChildByName("AtlasLabel_6");
	sprintf(str, "%d",GameManager::getInstance()->statistics[3]);
	lbNumCard01_04->setString(str);
//=============================================================================
	auto nodeCard_02 = (Node*)rootNode->getChildByName("shuzi_jie");
	lbNumCard02_01 = (TextAtlas*)nodeCard_02->getChildByName("AtlasLabel_7");
	sprintf(str, "%d",GameManager::getInstance()->statistics[4]);
	lbNumCard02_01->setString(str);
	//------------
	lbNumCard02_02 = (TextAtlas*)nodeCard_02->getChildByName("AtlasLabel_8");
	sprintf(str, "%d",GameManager::getInstance()->statistics[5]);
	lbNumCard02_02->setString(str);
	//------------
	lbNumCard02_03 = (TextAtlas*)nodeCard_02->getChildByName("AtlasLabel_9");
	sprintf(str, "%d",GameManager::getInstance()->statistics[6]);
	lbNumCard02_03->setString(str);
	//------------
	lbNumCard02_04 = (TextAtlas*)nodeCard_02->getChildByName("AtlasLabel_10");
	sprintf(str, "%d",GameManager::getInstance()->statistics[7]);
	lbNumCard02_04->setString(str);
//=============================================================================
	auto nodeCard_03 = (Node*)rootNode->getChildByName("shuzi_lian");
	lbNumCard03_01 = (TextAtlas*)nodeCard_03->getChildByName("AtlasLabel_11");
	sprintf(str, "%d",GameManager::getInstance()->statistics[8]);
	lbNumCard03_01->setString(str);
	//------------
	lbNumCard03_02 = (TextAtlas*)nodeCard_03->getChildByName("AtlasLabel_12");
	sprintf(str, "%d",GameManager::getInstance()->statistics[9]);
	lbNumCard03_02->setString(str);
	//------------
	lbNumCard03_03 = (TextAtlas*)nodeCard_03->getChildByName("AtlasLabel_13");
	sprintf(str, "%d",GameManager::getInstance()->statistics[10]);
	lbNumCard03_03->setString(str);
	//------------
	lbNumCard03_04 = (TextAtlas*)nodeCard_03->getChildByName("AtlasLabel_14");
	sprintf(str, "%d",GameManager::getInstance()->statistics[11]);
	lbNumCard03_04->setString(str);
//=============================================================================
	auto nodeCard_04 = (Node*)rootNode->getChildByName("shuzi_nva");
	lbNumCard04_01 = (TextAtlas*)nodeCard_04->getChildByName("AtlasLabel_15");
	sprintf(str, "%d",GameManager::getInstance()->statistics[12]);
	lbNumCard04_01->setString(str);
	//------------
	lbNumCard04_02 = (TextAtlas*)nodeCard_04->getChildByName("AtlasLabel_16");
	sprintf(str, "%d",GameManager::getInstance()->statistics[13]);
	lbNumCard04_02->setString(str);
	//------------
	lbNumCard04_03 = (TextAtlas*)nodeCard_04->getChildByName("AtlasLabel_17");
	sprintf(str, "%d",GameManager::getInstance()->statistics[14]);
	lbNumCard04_03->setString(str);
	//------------
	lbNumCard04_04 = (TextAtlas*)nodeCard_04->getChildByName("AtlasLabel_18");
	sprintf(str, "%d",GameManager::getInstance()->statistics[15]);
	lbNumCard04_04->setString(str);
//=============================================================================
	auto nodeCard_05 = (Node*)rootNode->getChildByName("shuzi_nvb");
	lbNumCard05_01 = (TextAtlas*)nodeCard_05->getChildByName("AtlasLabel_19");
	sprintf(str, "%d",GameManager::getInstance()->statistics[16]);
	lbNumCard05_01->setString(str);
	//------------
	lbNumCard05_02 = (TextAtlas*)nodeCard_05->getChildByName("AtlasLabel_20");
	sprintf(str, "%d",GameManager::getInstance()->statistics[17]);
	lbNumCard05_02->setString(str);
	//------------
	lbNumCard05_03 = (TextAtlas*)nodeCard_05->getChildByName("AtlasLabel_21");
	sprintf(str, "%d",GameManager::getInstance()->statistics[18]);
	lbNumCard05_03->setString(str);
	//------------
	lbNumCard05_04 = (TextAtlas*)nodeCard_05->getChildByName("AtlasLabel_22");
	sprintf(str, "%d",GameManager::getInstance()->statistics[19]);
	lbNumCard05_04->setString(str);
//=============================================================================
	auto nodeCard_06 = (Node*)rootNode->getChildByName("shuzi_nvc");
	lbNumCard06_01 = (TextAtlas*)nodeCard_06->getChildByName("AtlasLabel_23");
	sprintf(str, "%d",GameManager::getInstance()->statistics[20]);
	lbNumCard06_01->setString(str);
	//------------
	lbNumCard06_02 = (TextAtlas*)nodeCard_06->getChildByName("AtlasLabel_24");
	sprintf(str, "%d",GameManager::getInstance()->statistics[21]);
	lbNumCard06_02->setString(str);
	//------------
	lbNumCard06_03 = (TextAtlas*)nodeCard_06->getChildByName("AtlasLabel_25");
	sprintf(str, "%d",GameManager::getInstance()->statistics[22]);
	lbNumCard06_03->setString(str);
	//------------
	lbNumCard06_04 = (TextAtlas*)nodeCard_06->getChildByName("AtlasLabel_26");
	sprintf(str, "%d",GameManager::getInstance()->statistics[23]);
	lbNumCard06_04->setString(str);
//=============================================================================
	auto nodeCard_07 = (Node*)rootNode->getChildByName("shuzi_nvd");
	lbNumCard07_01 = (TextAtlas*)nodeCard_07->getChildByName("AtlasLabel_27");
	sprintf(str, "%d",GameManager::getInstance()->statistics[24]);
	lbNumCard07_01->setString(str);
	//------------
	lbNumCard07_02 = (TextAtlas*)nodeCard_07->getChildByName("AtlasLabel_28");
	sprintf(str, "%d",GameManager::getInstance()->statistics[25]);
	lbNumCard07_02->setString(str);
	//------------
	lbNumCard07_03 = (TextAtlas*)nodeCard_07->getChildByName("AtlasLabel_29");
	sprintf(str, "%d",GameManager::getInstance()->statistics[26]);
	lbNumCard07_03->setString(str);
	//------------
	lbNumCard07_04 = (TextAtlas*)nodeCard_07->getChildByName("AtlasLabel_30");
	sprintf(str, "%d",GameManager::getInstance()->statistics[27]);
	lbNumCard07_04->setString(str);
//=============================================================================
	auto nodeCard_08 = (Node*)rootNode->getChildByName("shuzi_xie");
	lbNumCard08_01 = (TextAtlas*)nodeCard_08->getChildByName("AtlasLabel_31");
	sprintf(str, "%d",GameManager::getInstance()->statistics[28]);
	lbNumCard08_01->setString(str);
	//------------
	lbNumCard08_02 = (TextAtlas*)nodeCard_08->getChildByName("AtlasLabel_32");
	sprintf(str, "%d",GameManager::getInstance()->statistics[29]);
	lbNumCard08_02->setString(str);
	//------------
	lbNumCard08_03 = (TextAtlas*)nodeCard_08->getChildByName("AtlasLabel_33");
	sprintf(str, "%d",GameManager::getInstance()->statistics[30]);
	lbNumCard08_03->setString(str);
	//------------
	lbNumCard08_04 = (TextAtlas*)nodeCard_08->getChildByName("AtlasLabel_34");
	sprintf(str, "%d",GameManager::getInstance()->statistics[31]);
	lbNumCard08_04->setString(str);
//=============================================================================
	auto nodeCard_09 = (Node*)rootNode->getChildByName("shuzi_logo");
	lbNumCard09_01 = (TextAtlas*)nodeCard_09->getChildByName("AtlasLabel_35");
	sprintf(str, "%d",GameManager::getInstance()->statistics[32]);
	lbNumCard09_01->setString(str);
	//------------
	lbNumCard09_02 = (TextAtlas*)nodeCard_09->getChildByName("AtlasLabel_36");
	sprintf(str, "%d",GameManager::getInstance()->statistics[33]);
	lbNumCard09_02->setString(str);
	//------------
	lbNumCard09_03 = (TextAtlas*)nodeCard_09->getChildByName("AtlasLabel_37");
	sprintf(str, "%d",GameManager::getInstance()->statistics[34]);
	lbNumCard09_03->setString(str);
	//------------
	lbNumCard09_04 = (TextAtlas*)nodeCard_09->getChildByName("AtlasLabel_38");
	sprintf(str, "%d",GameManager::getInstance()->statistics[35]);
	lbNumCard09_04->setString(str);
}

void StatisticsLayer::btnBackCallback(Ref *pSender, Widget::TouchEventType type)
{
	if(type == Widget::TouchEventType::ENDED)
	{
		this->removeFromParent();
	}
}

//int StatisticsLayer::GBKToUTF8(std::string &gbkStr,const char* toCode,const char* formCode){
//     iconv_t iconvH;
//     iconvH = iconv_open(formCode,toCode);
//      if(iconvH == 0){
//          return -1;
//      }
//      const char* strChar = gbkStr.c_str();
//      const char** pin = &strChar;
//      size_t strLength = gbkStr.length();
//     char *outbuf = (char*) malloc(strLength*4);
//     char *pBuff = outbuf;
//     memset(outbuf,0,strLength*4);
//     size_t outLength = strLength*4;
//     if(-1 == iconv(iconvH,pin,&strLength,&outbuf,&outLength)){
//         iconv_close(iconvH);
//         return -1;
//     }
//     gbkStr = pBuff;
//     iconv_close(iconvH);
//     return 0;
// }