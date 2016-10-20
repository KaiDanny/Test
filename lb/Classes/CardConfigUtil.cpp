#include "CardConfigUtil.h"
#include "GameManager.h"
#include "cocos2d.h"
#include "tinyxml2/tinyxml2.h"
using namespace tinyxml2;

using namespace cocos2d;
USING_NS_CC;

#define RETURN_IF(cond)           if((cond)) return


static const char *fileLineName[10] = {
    "line00.xml",
    "line01.xml",
    "line02.xml",
	"line03.xml",
    "line04.xml",
    "line05.xml",
    "line06.xml",
    "line07.xml",
    "line08.xml",
	"line09.xml",
};

static const char *fileResLineName[10] = {
    "xml/line00.xml",
    "xml/line01.xml",
    "xml/line02.xml",
	"xml/line03.xml",
    "xml/line04.xml",
    "xml/line05.xml",
    "xml/line06.xml",
    "xml/line07.xml",
    "xml/line08.xml",
	"xml/line09.xml",
};


CardConfigUtil* CardConfigUtil::m_instance = nullptr;

CardConfigUtil::CardConfigUtil(){
//	readCardConfigMap();
}
//
//void CardConfigUtil::writeCardConfigMap(std::vector<char*> &vecCardData)
//{
////*** 生成 json 文件，存储在 getWritablePath 文件夹下 ***
//  rapidjson::Document writedoc;
//  writedoc.SetObject();
//  rapidjson::Document::AllocatorType& allocator = writedoc.GetAllocator();
//  rapidjson::Value array(rapidjson::kArrayType);
//  rapidjson::Value object(rapidjson::kObjectType);
//  int vecSize = vecCardData.size();
//
//  object.AddMember("0", "1234445", allocator);
//  object.AddMember("1", "1234445", allocator);
//  object.AddMember("2", "1234445", allocator);
//
//  array.PushBack(object, allocator);
//   writedoc.AddMember("json", array, allocator);
// 
//  StringBuffer buffer;
//  rapidjson::Writer<StringBuffer> writer(buffer);
//  writedoc.Accept(writer);
//
//  auto path = FileUtils::getInstance()->getWritablePath();
//  path.append("myhero3.json");
//  FILE* file = fopen(path.c_str(), "wb");
//  if(file)
//  {
//    fputs(buffer.GetString(), file);
//    fclose(file);
//  }
//  CCLOG("%s",buffer.GetString());
//}
//
//void CardConfigUtil::readCardConfigMap()
//{
//	std::string  jsonStr = cocos2d::FileUtils::getInstance()->getStringFromFile("myhero3.json");
//	rapidjson::Document _mDoc;//读取"Json/HeroMessage.json"这个文件，并将这个文件转成一串string
//
//	std::string mstr = jsonStr;
//	RETURN_IF(NULL==mstr.c_str()||!mstr.compare(""));
//	_mDoc.Parse<0>(mstr.c_str());
//	RETURN_IF(_mDoc.HasParseError()||!_mDoc.IsObject());
//	const rapidjson::Value &pArr = _mDoc["json"];
//
//	log("Size = %d",pArr.Capacity());
//
//	std::string str =pArr["2"].GetString();
//
//	for(int i=0;i<pArr.Capacity();++i){
//		//BulletInfo e;
//		const rapidjson::Value &temp = pArr[i];
//		//int id = temp["id"].GetInt();
//		//e.id = temp["id"].GetInt();
//		//e.name = temp["name"].GetString();
//		//e.body_png_str = temp["body_png_str"].GetString();
//		//e.effect_id = temp["effect_id"].GetInt();
//		//e.m_atkHp = temp["atkHp"].GetInt();
//		//e.m_speed = temp["atkHp"].GetDouble();
//		////----------------------------
//		//bulletInfoMap.insert(make_pair(id, e));
//		//CCLOG("h : %s",h.r_png.c_str());
//		
//		std::string str = temp["2"].GetString();
//
//		CCLOG("h : %s",str.c_str());
//	}
//	//CCLOG("MapSize = %d", bulletInfoMap.size());
//	return;
//}


CardConfigUtil::~CardConfigUtil(){
	CC_SAFE_DELETE(m_instance);
}

CardConfigUtil* CardConfigUtil::getInstance(){
	if(m_instance == nullptr){
		m_instance = new CardConfigUtil();
	}
	return m_instance;
}

//map<int, BulletInfo> BulletInfoUtil::getBulletInfoMap(){
//	return bulletInfoMap;
//}
//
//BulletInfo BulletInfoUtil::getInfoById(int id){
//	auto it = bulletInfoMap.find(id);
//	CCASSERT(it != bulletInfoMap.end(), "can't get hero msg of the id");
//	return (*it).second;
//}
//
//void CardConfigUtil::writeCardXmlData(int fileNameIndex,Vector<CardConfig*> &vecCardWinLine)
//{
//	//--------------------
//	//std::string str = CCFileUtils::sharedFileUtils()->getWritablePath();
//	//CCFileUtils::sharedFileUtils()->setWritablePath("E:/xml/");
//	//---------------------
//	//要储存XML文件的路径
//    std::string filePath = CCFileUtils::sharedFileUtils()->getWritablePath() + fileLineName[fileNameIndex];
//    //xml文档
//    tinyxml2::XMLDocument *pDoc = new tinyxml2::XMLDocument();
//    if (NULL==pDoc) {
//        return ;
//    }
//    //xml声明
//    XMLDeclaration *pDel = pDoc->NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\"");
//    if (NULL==pDel) {
//        return ;
//    }
//    pDoc->LinkEndChild(pDel);
//    //节点plist
//    XMLElement *plistElement = pDoc->NewElement("plist");
//    plistElement->SetAttribute("version", "1.0");//给节点设置属性
//    pDoc->LinkEndChild(plistElement);
//        //节点dict
//        XMLElement *dictElement = pDoc->NewElement("dict");
//        plistElement->LinkEndChild(dictElement);
//			int sizeCardData = vecCardWinLine.size();
//			for(int i = 0; i < sizeCardData; i++)
//			{
//			   //节点key
//				XMLElement *keyElement = pDoc->NewElement("key");
//
//				char id[10];
//				sprintf(id,"%d",i);
//				keyElement->LinkEndChild(pDoc->NewText(id));//给节点设置值
//				dictElement->LinkEndChild(keyElement);
//					////节点string
//					//XMLElement *stringElement = pDoc->NewElement("string");
//					//stringElement->LinkEndChild(pDoc->NewText("stringText"));//给节点设置值
//					//dictElement->LinkEndChild(stringElement);
//				//节点array
//				XMLElement *arrayElemet = pDoc->NewElement("array");
//				dictElement->LinkEndChild(arrayElemet);
//
//				//CardData cardData = vecCardData.at(i);
//				//int sizeVecCard = vecCardData.at(i).size();
//					for (int j = 0; j < 15; j++) {
//						XMLElement *strEle = pDoc->NewElement("integer");
//						//strEle->LinkEndChild(pDoc->NewText("icon"));
//
//						char a[10];
//						sprintf(a,"%d",vecCardWinLine.at(i)->arrCard[j]);
//						strEle->LinkEndChild(pDoc->NewText(a));
//						arrayElemet->LinkEndChild(strEle);
//					}
//			}
//    pDoc->SaveFile(filePath.c_str());//保存文件 参数：路径
//    pDoc->Print();//打印
//    delete pDoc;
//}
//
//void CardConfigUtil::readCardXmlData(int fileNameIndex,Vector<CardConfig*> &vecCardWinLine)
//{
////最外面的 CCDictionary  
//   CCDictionary* pDict = CCDictionary::createWithContentsOfFile(fileResLineName[fileNameIndex]);  
///*第三层  下面说的是Array中包含string  
//        <key>special_3</key> 
//        <array> 
//            <integer>45.0</integer> 
//            <integer>3</integer> 
//            <integer>43.444</integer> 
//        </array> 
//        */  
//    unsigned int  cntAll = pDict->count();
//	for (int i = 0;i < cntAll;i++)  
//	{
//		char a[10];
//		sprintf(a,"%d",i); 
//		CCArray* pArray = new CCArray();  
//		pArray->retain();  
//		pArray = (CCArray*)pDict->objectForKey(a);  
//		int cntArr = pArray->count();
//		//--------------------------
//		CardConfig* cardConfig = CardConfig::create();
//		cardConfig->id = i;
//		//-------------------------------
//		for (int j = 0;j < cntArr;j++)  
//		{  
//			CCString str = ((CCString*)pArray->objectAtIndex(j))->getCString();
//			//CCLOG("pArray3%i:%s",j+1,((CCString*)pArray->objectAtIndex(j))->getCString());  
//			int tmp = atoi(((CCString*)pArray->objectAtIndex(j))->getCString());    // i = 15
//			CCLOG ("%d \n", tmp); 
//			cardConfig->arrCard[j] = tmp;
//		} 
//		vecCardWinLine.pushBack(cardConfig);
//	}
// 
//}


//------------------------------------------------------------------------------
void CardConfigUtil:: writeCardElmenXmlData(std::vector<CardElmen> &vecCardElmen)
{
	//--------------------
	//std::string str = CCFileUtils::sharedFileUtils()->getWritablePath();
	//CCFileUtils::sharedFileUtils()->setWritablePath("E:/xml/");
	//---------------------
	//要储存XML文件的路径
    std::string filePath = CCFileUtils::sharedFileUtils()->getWritablePath() + cardElmenFileNameStr;
    //xml文档
    tinyxml2::XMLDocument *pDoc = new tinyxml2::XMLDocument();
    if (NULL==pDoc) {
        return ;
    }
    //xml声明
    XMLDeclaration *pDel = pDoc->NewDeclaration("xml version=\"1.0\" encoding=\"UTF-8\"");
    if (NULL==pDel) {
        return ;
    }
    pDoc->LinkEndChild(pDel);
    //节点plist
    XMLElement *plistElement = pDoc->NewElement("plist");
    plistElement->SetAttribute("version", "1.0");//给节点设置属性
    pDoc->LinkEndChild(plistElement);
    //节点dict
    XMLElement *dictElement = pDoc->NewElement("dict");
    plistElement->LinkEndChild(dictElement);
	int sizeVec = vecCardElmen.size();
	for(int i = 0; i < sizeVec; i++)
	{
		//节点key
		char _multiple[20]="multiple_";
		XMLElement *keyElement = pDoc->NewElement("key");
		CCString* strKey=CCString::createWithFormat("%d",i);
		const char* idKey = strKey->getCString();
		char* _multiple_key = strcat(_multiple,idKey);
		keyElement->LinkEndChild(pDoc->NewText(_multiple_key));//给节点设置值
		dictElement->LinkEndChild(keyElement);
		//---------------------------------------
		XMLElement *strEle = pDoc->NewElement("integer");
		int multipleScore = vecCardElmen.at(i).multipleScore;
		CCString* strMultiple =CCString::createWithFormat("%d",multipleScore);
		const char* idMultiple = strMultiple->getCString();
		strEle->LinkEndChild(pDoc->NewText(idMultiple));
		dictElement->LinkEndChild(strEle);
		//-------------------------------
		XMLElement *keyElement2 = pDoc->NewElement("key");
		char _vec[20]="vec_";
		char* _vec_key = strcat(_vec,idKey);
		keyElement2->LinkEndChild(pDoc->NewText(_vec_key));//给节点设置值
		dictElement->LinkEndChild(keyElement2);

		XMLElement *dictElement2 = pDoc->NewElement("dict");
		dictElement->LinkEndChild(dictElement2);
		//--------------------------
		int sizeCard = vecCardElmen.at(i).vecCardData.size();
		for (int j = 0; j < sizeCard; j++)
		{
		   //节点key
			XMLElement *keyElement = pDoc->NewElement("key");
			CCString* ns=CCString::createWithFormat("%d",j);
			const char* id= ns->getCString();
			keyElement->LinkEndChild(pDoc->NewText(id));//给节点设置值
			dictElement2->LinkEndChild(keyElement);
			XMLElement *arrayElemet = pDoc->NewElement("array");
			dictElement2->LinkEndChild(arrayElemet);
			for (int k = 0; k < 15; k++) 
			{
				XMLElement *strEle = pDoc->NewElement("integer");
				CCString* ns=CCString::createWithFormat("%d",vecCardElmen.at(i).vecCardData.at(j).arrCard[k]);
				const char* a= ns->getCString();
				strEle->LinkEndChild(pDoc->NewText(a));
				arrayElemet->LinkEndChild(strEle);
			}
		}
	}
    pDoc->SaveFile(filePath.c_str());//保存文件 参数：路径
    pDoc->Print();//打印
    delete pDoc;
}


void CardConfigUtil::readCardElmenXmlData(std::vector<CardElmen> &vecCardElmen)
{
//最外面的 CCDictionary  
   CCDictionary* pDict = CCDictionary::createWithContentsOfFile(cardElmenFileNameStr);   
   unsigned int  sizeDict = pDict->count();
   	int sizeTmp = sizeDict/2;
	for (int i = 0;i < sizeTmp;i++)  
	{
		CardElmen cardElmen;
		CardData cardData;
		CardStatistics cardStatistics;
		char _multiple[20]="multiple_";
		CCString* strKey=CCString::createWithFormat("%d",i);
		const char* idKey = strKey->getCString();
		//节点key
		char* _multiple_key = strcat(_multiple,idKey);
		CCString* ns=(CCString*)pDict->valueForKey(_multiple_key);
		const char* key= ns->getCString();
		int multipleScore = atoi(ns->getCString());
		cardElmen.multipleScore= multipleScore;
		cardStatistics.multiple = multipleScore;
		//---------------------------------
		char _vec[20]="vec_";
		char* _vec_key = strcat(_vec,idKey); 
		CCDictionary* pDict2  = (CCDictionary*)pDict->objectForKey(_vec_key);  
		int sizeDict2 = pDict2->count();
		cardStatistics.multipleCnt = sizeDict2;
		for (int j = 0;j < sizeDict2;j++)  
		{
			cardData.id = j;
			CCString* ns=CCString::createWithFormat("%d",j);
			const char* a= ns->getCString();
			CCArray* pArray = new CCArray();  
			pArray->retain();  
			pArray = (CCArray*)pDict2->objectForKey(a);  
			int sizeArr = pArray->count();
			//-----------------------------
			for (int k = 0;k < sizeArr;k++)	
			{
				CCString str = ((CCString*)pArray->objectAtIndex(k))->getCString();
				//CCLOG("pArray3%i:%s",j+1,((CCString*)pArray->objectAtIndex(j))->getCString());  
				int tmp = atoi(((CCString*)pArray->objectAtIndex(k))->getCString());    // i = 15
				CCLOG ("%d \n", tmp); 
				cardData.arrCard[k] = tmp;
			}
			cardElmen.vecCardData.push_back(cardData);
		}
		vecCardElmen.push_back(cardElmen);
		GameManager::getInstance()->vecCardStatistics.push_back(cardStatistics);
	}
	CCLOG ("%d", 1); 
}

void CardConfigUtil::writeXmlStatistics()
{
	std::string filePath = CCFileUtils::sharedFileUtils()->getWritablePath() + cardElmenStatistics;
    //xml文档
    tinyxml2::XMLDocument *pDoc = new tinyxml2::XMLDocument();
    if (NULL==pDoc) {
        return ;
    }
	 XMLElement *dictElement = pDoc->NewElement("dict");
    pDoc->LinkEndChild(dictElement);
	//--------------------------------
	int sizeVec = GameManager::getInstance()->vecCardStatistics.size();
	for(int i = 0; i < sizeVec; i++)
	{
		char str_01[50];
		char str_02[50];
		char str_03[50];
		int multipleScore = GameManager::getInstance()->vecCardStatistics.at(i).multiple;
		sprintf(str_01,"%d",multipleScore); 
		int sizeCard = GameManager::getInstance()->vecCardStatistics.at(i).multipleCnt;	
		sprintf(str_02,"%d",sizeCard);
		sprintf(str_03, "%s%s%s", str_01, "倍数的个数：",str_02); 
		XMLElement *keyElement = pDoc->NewElement("key");
		keyElement->LinkEndChild(pDoc->NewText(str_03));//给节点设置值
		dictElement->LinkEndChild(keyElement);
	}
    pDoc->SaveFile(filePath.c_str());//保存文件 参数：路径
    pDoc->Print();//打印
    delete pDoc;
}