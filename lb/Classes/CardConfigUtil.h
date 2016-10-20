#ifndef _CARD_CONFIG_UTIL_H_
#define _CARD_CONFIG_UTIL_H_
//#include "CardConfig.h"
#include "Common.h"
#include "json/rapidjson.h"
#include "json/document.h"

#include "json/writer.h"
#include "json/stringbuffer.h"
using namespace  rapidjson;


#include "cocos2d.h"
#include <map>
using namespace cocos2d;

class CardConfigUtil{
public:
	static CardConfigUtil* getInstance();
	//BulletInfo getInfoById(int id);
	//map<int, BulletInfo> getBulletInfoMap();//ͨ��һ��Ӣ�۵�id����ȡ��ȫ����Ϣ��
	CardConfigUtil();
	~CardConfigUtil();
public:
	//void writeCardConfigMap(std::vector<char*> &vecCardData);
	//void readCardConfigMap();

	//void writeCardXmlData(int fileNameIndex,Vector<CardConfig*> &vecCardWinLine);
	//void readCardXmlData(int fileNameIndex,Vector<CardConfig*> &vecCardWinLine);

	void writeCardElmenXmlData(std::vector<CardElmen> &vecCardElmen);
	void readCardElmenXmlData(std::vector<CardElmen> &vecCardElmen);
	void writeXmlStatistics();
public:
	static CardConfigUtil* m_instance;
	//map<int, BulletInfo> bulletInfoMap;//����һ��map������Ӣ�۵�Ψһid��ֵ�Ƕ�Ӧ����Ϣ����
	//map<int,CardConfig> bulletInfoMap;
};
#endif