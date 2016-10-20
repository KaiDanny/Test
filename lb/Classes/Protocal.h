/*****************************************************************************
 * File name     : Game.h
 * Description   : 游戏的全局定义头文件
 * 
 * Version       : 1.0.0
 * Date          : 2013/11/29
 * Others        :
 *
 * History 	     :
 * Date            Version       Author               Modify
 * 2013/11/29      1.0.0         韦波                    编写
 *******************************************************************************/

#ifndef Protocal_h
#define Protocal_h

//服务器常量定义
#ifndef LOGIN_SERVER_IP
//#define LOGIN_SERVER_IP             "login2.ylz.com"     //登陆服务器地址
#define LOGIN_SERVER_IP             "192.168.0.132"     //登陆服务器地址
#endif
//
#ifndef LOGIN_SERVER_PORT
#define LOGIN_SERVER_PORT           12345               //登陆服务器端口
#endif

//消息key结构体
//struct PcMac{ 
//	char strId[32]; 
//}; 
      
     
static const int msgGetPcMacAdress = 1001;
static const int msgBetOnMoney = 1002;
static const int msgOpenBigAward = 1003;

static const std::string defaultPcMacStr = "111";

#endif