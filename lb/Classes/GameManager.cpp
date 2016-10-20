//
//  GameManager.cpp
//
//  Created by cocos2d-x on 14-4-15.
//
//

#include "GameManager.h"
#include "CardConfigUtil.h"
#include "Protocal.h"


static const char *pStatisticsKey[36] = {
    "key_01",
    "key_02",
    "key_03",
    "key_04",
    "key_05",
    "key_06",
    "key_07",
    "key_08",
    "key_09",
    "key_10",
    "key_11",
    "key_12",
    "key_13",
    "key_14",
    "key_15",
    "key_16",
    "key_17",
    "key_18",
    "key_19",
    "key_20",
    "key_21",
    "key_22",
    "key_23",
    "key_24",
    "key_25",
    "key_26",
    "key_27",
    "key_28",
    "key_29",
    "key_30",
	"key_31",
	"key_32",
	"key_33",
	"key_34",
	"key_35",
	"key_36",
};

GameManager* GameManager::instance;
GameManager* GameManager::getInstance()
{
	if (instance == NULL)
	{
		instance = new GameManager();
	}
	return instance;
}
bool GameManager::init()
{
	auto instance = GameManager::getInstance();
	return true;
}
void GameManager::clear()
{
    SpriteFrameCache::getInstance()->removeSpriteFrames();
}
void GameManager::readData()
{
    int i;
    if (!UserDefault::sharedUserDefault()->getBoolForKey("isHaveSaveFileXml_43"))
    {
        UserDefault::sharedUserDefault()->setBoolForKey("isHaveSaveFileXml_43", true);
        UserDefault::sharedUserDefault()->setIntegerForKey("totleCoin", 0);
		UserDefault::sharedUserDefault()->setIntegerForKey("winCoin", 0);
		UserDefault::sharedUserDefault()->setIntegerForKey("coinOperated", 0);
		UserDefault::sharedUserDefault()->setIntegerForKey("addScore", 0);
		UserDefault::sharedUserDefault()->setIntegerForKey("subScore", 0);
		UserDefault::sharedUserDefault()->setIntegerForKey("win_percent", 0);
		UserDefault::sharedUserDefault()->setIntegerForKey("exchangeCoin", 0);
		UserDefault::sharedUserDefault()->setStringForKey("pcMacStr", defaultPcMacStr);
		//----------------------
		UserDefault::sharedUserDefault()->setFloatForKey("startVolume", 0);
		UserDefault::sharedUserDefault()->setIntegerForKey("backLayerPercent", 0);
		UserDefault::sharedUserDefault()->setIntegerForKey("gLubyte_alpha", 0);
		//-----------------------
        UserDefault::sharedUserDefault()->flush();
        GameManager::getInstance()->totleCoin = 100000;
		GameManager::getInstance()->winCoin = 0;
		GameManager::getInstance()->coinOperated = 0;
        GameManager::getInstance()->addScore = 0;
		GameManager::getInstance()->subScore = 0;
		GameManager::getInstance()->win_percent = 90;
		//------------------------------------------
		GameManager::getInstance()->startVolume = SOUND_ST_BG_VOLUME;
		GameManager::getInstance()->backLayerPercent = ALPHA_ST_PERCENT;
		GameManager::getInstance()->gLubyte_alpha = 0;
		//--------------------------
		GameManager::getInstance()->exchangeCoin = DEFUALT_EXCHANGE_COIN;
		GameManager::getInstance()->pcMacStr = defaultPcMacStr;
		for (i = 0; i < 36; i++)
		{
			UserDefault::sharedUserDefault()->setIntegerForKey(pStatisticsKey[i], 0);//�޸Ĵ浵
		}
		for (i = 0; i < 36; i++)
		{
			statistics[i]= 0;
		}
        saveData();
    }
    else
    {
        int totleCoin = UserDefault::sharedUserDefault()->getIntegerForKey("totleCoin", 0);
		int winCoin = UserDefault::sharedUserDefault()->getIntegerForKey("winCoin", 0);
		int coinOperated = UserDefault::sharedUserDefault()->getIntegerForKey("coinOperated", 0);
        int addScore = UserDefault::sharedUserDefault()->getIntegerForKey("addScore", 0);
		int subScore = UserDefault::sharedUserDefault()->getIntegerForKey("subScore", 0);
		int win_percent = UserDefault::sharedUserDefault()->getIntegerForKey("win_percent", 0);
		int exchangeCoin = UserDefault::sharedUserDefault()->getIntegerForKey("exchangeCoin", 0);
		float startVolume = UserDefault::sharedUserDefault()->getFloatForKey("startVolume", 0);
		int backLayerPercent = UserDefault::sharedUserDefault()->getIntegerForKey("backLayerPercent", 0);
		int gLubyte_alpha = UserDefault::sharedUserDefault()->getIntegerForKey("gLubyte_alpha", 0);
		std::string pcMacStr = UserDefault::sharedUserDefault()->getStringForKey("pcMacStr");
        GameManager::getInstance()->totleCoin = totleCoin;
		GameManager::getInstance()->winCoin = winCoin;
		GameManager::getInstance()->coinOperated = coinOperated;
        GameManager::getInstance()->addScore = addScore;
		GameManager::getInstance()->subScore = subScore;
		GameManager::getInstance()->win_percent = win_percent;
		GameManager::getInstance()->exchangeCoin = exchangeCoin;
		GameManager::getInstance()->startVolume = startVolume;
		GameManager::getInstance()->backLayerPercent = backLayerPercent;
		GameManager::getInstance()->gLubyte_alpha = gLubyte_alpha;
		GameManager::getInstance()->pcMacStr = pcMacStr;
		for (i = 0; i < 36; i++)
		{
			statistics[i]= UserDefault::sharedUserDefault()->getIntegerForKey(pStatisticsKey[i], 0);
		}
    }
}
void GameManager::saveData()
{
    UserDefault::sharedUserDefault()->setIntegerForKey("totleCoin",GameManager::getInstance()->totleCoin);
	UserDefault::sharedUserDefault()->setIntegerForKey("winCoin",GameManager::getInstance()->winCoin);
	UserDefault::sharedUserDefault()->setIntegerForKey("coinOperated",GameManager::getInstance()->coinOperated);
    UserDefault::sharedUserDefault()->setIntegerForKey("addScore",GameManager::getInstance()->addScore);
	UserDefault::sharedUserDefault()->setIntegerForKey("subScore",GameManager::getInstance()->subScore);
	UserDefault::sharedUserDefault()->setIntegerForKey("win_percent",GameManager::getInstance()->win_percent);
	UserDefault::sharedUserDefault()->setIntegerForKey("exchangeCoin",GameManager::getInstance()->exchangeCoin);
	UserDefault::sharedUserDefault()->setStringForKey("pcMacStr", GameManager::getInstance()->pcMacStr);
	UserDefault::sharedUserDefault()->setFloatForKey("startVolume",GameManager::getInstance()->startVolume);
	UserDefault::sharedUserDefault()->setIntegerForKey("backLayerPercent", GameManager::getInstance()->backLayerPercent);
	UserDefault::sharedUserDefault()->setIntegerForKey("gLubyte_alpha", GameManager::getInstance()->gLubyte_alpha);
	for (int i = 0; i < 36; i++)
	{
		UserDefault::sharedUserDefault()->setIntegerForKey(pStatisticsKey[i], statistics[i]);//�޸Ĵ浵
	}
    UserDefault::sharedUserDefault()->flush();
}

//void GameManager::initVecCardLine()
//{
//	vecCardWinLine_00.clear();
//	vecCardWinLine_01.clear();
//	vecCardWinLine_02.clear();
//	vecCardWinLine_03.clear();
//	vecCardWinLine_04.clear();
//	vecCardWinLine_05.clear();
//	vecCardWinLine_06.clear();
//	vecCardWinLine_07.clear();
//	vecCardWinLine_08.clear();
//	vecCardWinLine_09.clear();
//}

