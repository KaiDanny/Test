//
//  GameManager.h
//  thiefTD
//
//  Created by cocos2d-x on 14-4-15.
//
//

#ifndef __GameManager__
#define __GameManager__


#include "cocos2d.h"
USING_NS_CC;




#include "Common.h"


class GameManager
{
public:
	bool init();
    void clear();
    void readData();
    void saveData();
	static GameManager* getInstance();
	int statistics[36];
	//Vector<CardConfig*> vecCardWinLine_00;
	//Vector<CardConfig*> vecCardWinLine_01;
	//Vector<CardConfig*> vecCardWinLine_02;
	//Vector<CardConfig*> vecCardWinLine_03;
	//Vector<CardConfig*> vecCardWinLine_04;
	//Vector<CardConfig*> vecCardWinLine_05;
	//Vector<CardConfig*> vecCardWinLine_06;
	//Vector<CardConfig*> vecCardWinLine_07;
	//Vector<CardConfig*> vecCardWinLine_08;
	//Vector<CardConfig*> vecCardWinLine_09;
	std::vector<CardElmen> vecCardElmen;
	std::vector<CardStatistics> vecCardStatistics;
private:
	static GameManager * instance;
public:
	int totleCoin;
	int winCoin;
	int win_percent;
	int curGameBetOn;
	int coinOperated;  //×ÜÍ¶±Ò
//	void initVecCardLine();
//	bool isFinishBetOn;
	bool isOpenBigAward; 
	bool isPlayingVideo;
	bool isPlayVideoOver;
	std::string pcMacStr;
	LayerColor* backLayerColor;
	int backLayerPercent;
	int gLubyte_alpha;
	float startVolume;

	int addScore;
	int subScore;

	int exchangeCoin;
};
#endif /* defined(__mxpp__GameManager__) */
