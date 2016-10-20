//
//  MainMenuScene.hpp
//  mxr
//
//  Created by imac on 15/11/14.
//
//

#ifndef MainScene_h
#define MainScene_h

#include "ui/CocosGUI.h"
#include"cocostudio/CocoStudio.h"
using namespace cocos2d;
using namespace cocostudio::timeline;
USING_NS_CC;
using namespace ui;

#include "cocos2d.h"
//#include "CardSprite.h"

enum RollLampType{
    RollLamp_Common,
    RollLamp_Win
};
enum GameState{
    Game_Common,
    Game_Reward
};
class MainScene : public Scene
{
public:
    virtual bool init();
    CREATE_FUNC(MainScene);
	virtual void update(float dt);
	//void videoUpdate();
	void initData();
	void initCard();
	void initBtnAndGrayBgPic();
	void initCardSprite(int rand,Point pt,int tag);
	void initGrayCardSprite();
	//void onClickBtnStart();
	void initNumber();
	void chkStartCallback(Ref* sender,CheckBoxEventType type);
	void chkAutoStartCallback(Ref* sender,CheckBoxEventType type);
	void btnChargePointCallback(Ref *pSender, Widget::TouchEventType type);
	void btnChargePointMaxCallback(Ref *pSender, Widget::TouchEventType type);
	//-------------------------
	void btnTestCallback(Ref* pSender);
	void btnSystemCallback(Ref* pSender);
	//-------------------------
	void cardActionStartRun();
	void onClickBtnWinRand();
	ActionTimeline* createRandRollActionByIndex(int index);
	void actionCardRollCallBack();
	void actionCardSpringback(Node* node);
	void stopAllCardRoll();
	void stopAllCardRollCallBack(Node* node,int index);
	void checkWinOnLine();
	bool isGameWinOnTheLine(int indexLine ,std::vector<int> &vecCardLine,const int *CardLineIndex);
	void playLineAction(int lineIndex);
	void playLineActionCallBack(Node* node,int index);
	void addBoxNodeByLineIndex(int index);
	void initBoxNodeByVecLine(std::vector<int> &vec,int indexLine);
	void initLightNodeByVecLine(std::vector<int> &vec);
	void initBoxNodeAndPlayAction(Node* nodeBox,ActionTimeline* actionBox,int cardIndex,int indexLine);
	void playLightActionCallBack(Node* node,int index);
	void addCard3D();
	void initCard3DNodeByVecLine(std::vector<int> &vec);
	void initCard3DNodeAndPlayAction(int cardIndex);
	void card3DActionCallBack(Node* node,int index);
	int commonCardInTheCardLine(std::vector<int> &vec);
	void initRollLamp();
	void playRollLampAction(RollLampType rollLampType);
	void finishRollLampAction();
	void addGrayCardByCardLine(std::vector<int> &vec); 
	void clearAllCardAboveSprite();
//	std::vector<std::string> split(std::string str, std::string pattern);
	void countThisGameScore(std::vector<int> &vecCardLine);
	void checkRewardPetiteMarie(int indexLine,std::vector<int> &vecCardLine);//是可以否奖励小玛丽
	void checkMarieGame();
	void marieCard3DActionEndCheck();
	void actionCloseDoorCallBack(Node* node);
	void initMarieGameNum(int omnipotentCardNum);
	void resetGraySpGrayPic();
	void startRunGame();
	void checkAutoStartGame();
	void resetGameDateByCardActionEnd();
	void upDateCoinNum();
	void upDateCoinNumCallBack();
	void subTotleCoin();
	//void playStickAction();
	//void initStickNode();
	//void playStickActionCallBack();
	void initlogoLihtAction();
    //void coinNumRunAction(int score);
    //void coinNumActionCallBack(Label *label);
	void createCardByRandom();
	void playVideoAction();
	void playVideoActionCallBack();
	//--------------
	void initBallAction();
	//------------
	void initMarieNumScene();
	int countCoinDigit(int digit);
	void initMarieNumAction();
	void initOpenDoorAction();
	void returnCommonGame();
	void actionFireworksCallBack(Node* node);
	void actionOpenDoorCallBack(Node* node);
	void actionMarieNumCallBack(Node* node,int num);
	void actionMarieNumSpringCallBack(Node* node,int num);
	//--------------------
	bool isOverallWinCard();
	void statisticsCardWinLine(int card, int lineSize);
	//----------------
	void sendMesBetOnToServer();
public:
	GameState gameState;
	int coin;//获得分数
	int totleCoin;//总分数
	int marieGameWinCoin;
	int tmpUpdateCoin;
	int chargePointCnt;
	bool bRewardMarie;
	bool isCanPlayMarieGame;
	bool isEnterMarieGameing;
	bool isAutoStart;
	bool isBeginUpdateCoin;

	bool bGameOver;

	int marieGameNum;
	int cardType[15];
	bool bWinLine[9];
	bool isOverallWin;
	//bool bCardBoxNode[15];
	//bool bCardRollEnd[15];
	bool bCardActionNode[15];
	float cardSpInitStX;
	float cardSpInitStY;
	float gapCardSpX;
	float gapCardSpY;
	float _center_x;
	float _center_y;
	int actionCardIndex;
	bool isCardRuning;
	bool isGameEnd;
	bool isGameRuning;
	Node* rootNode;
	//------------
	Node* nodeRollLampCommon;//跑马灯
	Node* nodeRollLampWin;//跑马灯
	Node* nodeMarieNumScene;
	//----------
	Node* nodeYaoGan;
	Node* nodeBigBox;
	Node* newMain;
	Node* marieLight;
	//Sprite* spStickBottom;
	//Sprite* spStickUp;
	Sprite* spLogoPic;

	Node* nodeStickBottom;
	Node* nodeStickUp;
	Node* nodeButtomLogoLight;
	Node* nodeUpLogoLight;

	Sprite* spButtomLogo;
	Sprite* spUpLogo;

	ActionTimeline* actionYaogan;
	std::vector<int> vecCardLine_01;
	std::vector<int> vecCardLine_02;
	std::vector<int> vecCardLine_03;
	std::vector<int> vecCardLine_04;
	std::vector<int> vecCardLine_05;
	std::vector<int> vecCardLine_06;
	std::vector<int> vecCardLine_07;
	std::vector<int> vecCardLine_08;
	std::vector<int> vecCardLine_09;
	//int finalActionOfCardIndex;
	int randWinLine;

	int tmpClickType;

	//Label* lbLineSingle;
	//Label* lbLineNine;
	//Label* lbLineCoin;

	TextAtlas* lbLineSingle;
	TextAtlas* lbLineNine;
	TextAtlas* lbLineCoin;

	TextAtlas* lbMarieGameNum;
	TextAtlas* lbTotleCoin;


	Node* nodeEffectMarieGame;
	ActionTimeline* actionMarieGame; 

	Sprite* spVideo;
	FiniteTimeAction *actionVideo;
	Animation* animationVideo; 

	//---------------
	LayerColor* layerColorEf;

};

#endif /* MainScene_h */
