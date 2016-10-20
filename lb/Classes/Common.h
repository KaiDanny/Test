#ifndef __COMMON_H__
#define __COMMON_H__

#include "cocos2d.h"
USING_NS_CC;

enum CurDirect{
    Direct_Left,
    Direct_Right,
    Direct_Up,
    Direct_Down
};


struct CardData{      //声明一个结构体类型
  int id;         //声明一个整形变量num 
  int arrCard[15];
 };//声明变量
struct CardElmen{      //声明一个结构体类型
	int multipleScore;
	std::vector<CardData> vecCardData;
    bool   operator <  (const   CardElmen&   rhs   )  const   //升序排序时必须写的函数
    {   
      return   multipleScore   <   rhs.multipleScore; 
    }

 };//声明变量
struct CardStatistics{      //声明一个结构体类型
  int multiple;         //倍数
  int multipleCnt;   //倍数个数
 };
//-----------------
const int ZORDER_PLAYER = 10;
const int SPRITE_BATCH_NODE = 1001;
const int PARTICLE_ZORDER = 1002;
//--------------------
//#define ON_PLAYER_STOP_EVENT  "onPlayerStopEvent"
//#define ON_ROLE_MOVE_LEFT_EVENT  "onRoleMoveLeftEvent"
//#define ON_ROLE_MOVE_RIGHT_EVENT  "onRoleMoveRightEvent"
//#define ON_ROLE_MOVE_UP_EVENT  "onRoleMoveUpEvent"
//#define ON_ROLE_MOVE_DOWN_EVENT  "onRoleMoveDownEvent"
//#define ON_ROLE_MOVE_END_EVENT  "onRoleMoveEndEvent"
//#define ON_ROLE_START_ACTION_EVENT  "onRoleStartActionEvent"
//#define ON_GAME_PAUSE_EVENT  "onGamePauseEvent"
//

//-------------------------
#define DISPLAY_SIZE (Director::getInstance()->getWinSize())
#define DISPLAY_CX (DISPLAY_SIZE.width / 2)
#define DISPLAY_CY (DISPLAY_SIZE.height / 2)
#define DISPLAY_WIDTH (DISPLAY_SIZE.width)
#define DISPLAY_HEIGHT (DISPLAY_SIZE.height)
#define DISPLAY_LEFT (0)
#define DISPLAY_RIGHT (DISPLAY_SIZE.width)
#define DISPLAY_BOTTOM (0)
#define DISPLAY_TOP (DISPLAY_SIZE.height)
#define DISPLAY_TITLE_WIDTH_NUM (8)
#define DISPLAY_TITLE_HEIGHT_NUM (5)

#define FrameNumRollLampCommon (85)
#define FrameNumRollLampWin (28)
#define FrameNumCardRoll (84)
#define FrameNumCardSpring (28)
#define FrameNumCardLine (60)
#define FrameNumCardBox (60)
#define FrameNumCard3DAction (144)
#define FrameNumLight (37)
#define FrameNumYaogan (60)
#define FrameNumCloseDoorAction (196)
#define FrameNumOpenDoorAction (196)
#define FrameNumMarieLightAction (160)
#define FrameNumStickAction (60)
#define FrameNumButtomLogoLight (44)
#define FrameNumUpLogoLight (44)
#define FrameNumBall (124)
#define FrameNumFireworks (220)
#define FrameNumMarieNumAction (30)
#define FrameNumMarieNumSpringAction (20)
#define FrameColouredLightNumAction (120)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    

#define PLAYER_X_SPEED (3)
#define PLAYER_Y_SPEED (20)
#define OBJECT_GRAVITY (0.94)

#define SOUND_ST_BG_VOLUME (0.2f)
#define ALPHA_ST_PERCENT (100)

#define M_PI_VALUE (3.14159f)

#define MAX_MENU (8)

#define MAX_ALPHA (150)

#define DEFUALT_EXCHANGE_COIN (1000)
#define EXCHANGE_COIN_02 (2000)
#define EXCHANGE_COIN_03 (3000)

#define ADD_SCORE_01 (1000)
#define ADD_SCORE_02 (2000)
#define ADD_SCORE_03 (3000)
#define MAX_TOTLE_SCORE (99999999)

#define SUB_SCORE_01 (1000)
#define SUB_SCORE_02 (2000)
#define SUB_SCORE_03 (3000)


#define mid_multiple_coin (2000)
#define max_multiple_coin (5000)

static const char cardElmenFileNameStr[] = "xml/cardElmenFile.xml";
static const char cardElmenStatistics[] = "cardStatistics.xml";

static const char CommonRollLampFrameName[] = "effect_paomadeng.csb";
static const char WinRollLampFrameName[] = "effect_paomadeng_shangsuo.csb";
static const char FrameNameBoxNodeType_01[] = "effect_zhong_there.csb";
static const char FrameNameBoxNodeType_02[] = "effect_zhong_si.csb";
static const char FrameNameBoxNodeType_03[] = "effect_zhong_all.csb";
static const char FrameNameLight[] = "effect_light.csb";
static const char FrameCloseDoorAction[] = "effect_tuichang.csb";
static const char FrameOpenDoorAction[] = "effect_jinchang.csb";
static const char FrameMarieLightAction[] = "effect_xin_deng.csb";
static const char FrameStickAction[] = "effect_yaogan.csb";
static const char FrameMarieNumScene[] = "huojiang.csb";
static const char FrameBall[] = "effect_qiu.csb";
static const char FrameFireworks[] = "effect_yanhua.csb";

static const char FrameButtomLogoLight[] = "effect_logo_jiu_light.csb";
static const char FrameUpLogoLight[] = "effect_logo_xin_light.csb";
static const char FrameMarieNumAction[] = "effect_gd_shuzi.csb";
static const char FrameColouredLightAction[] = "effect_logo_deng.csb";
//Point fireTargetPoint;
// 封装帧动画接口
//Sprite* newFramesSprte(const char* plist, const char*png,
//	const char*name_format, int index, int count, float time);
//
//void setFramesSprte(Sprite* it, const char* plist, const char*png,
//	const char*name_format, int index, int count, float time);
//
//void setFramesSprteOnce(Sprite* it, const char* plist, const char*png,
//	const char*name_format, int index, int count, float time);
//// end
//
//inline CCPoint operator +(CCPoint p1, CCPoint p2){
//	return ccp(p1.x + p2.x, p1.y + p2.y);
//}
//
//inline CCPoint operator -(CCPoint p1, CCPoint p2){
//	return ccp(p1.x - p2.x, p1.y - p2.y);
//}
//
//float calRadianByTwoPoint(const CCPoint& beginPoint, const CCPoint& endPoint);
//
//float calAngleByTwoPoint(const CCPoint& beginPoint, const CCPoint& endPoint);

#endif


	//ArrayList<Integer> dataList = new ArrayList<>();
	//	ArrayList<HashMap<Integer, Integer>>list = new ArrayList<>();
	//	int b = new Random().nextInt(100);
	//	dataList.add(0);
	//	dataList.add(b);
	//	dataList.add(1);
	//	dataList.add(1);
	//	dataList.add(1);
	//	dataList.add(b);
	//	int sameNumber = 0;	//哪个数有连续
	//	int sameNum=0;		//连续的数连有几个
	//	for(int i=0; i<dataList.size()-1; i++)
	//	{
	//		if(dataList.get(i)==dataList.get(i+1))
	//		{
	//			sameNumber = dataList.get(i);
	//			sameNum++;
	//		}
	//		else
	//		{
	//			if(sameNum>0)
	//			{
	//				HashMap<Integer, Integer>map=new HashMap<>();
	//				map.put(sameNumber, sameNum);
	//				list.add(map);
	//			}
	//			sameNum = 0;
	//		}
	//	}
