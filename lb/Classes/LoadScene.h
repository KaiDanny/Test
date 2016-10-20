//
//  MainMenuScene.hpp
//  mxr
//
//  Created by imac on 15/11/14.
//
//

#ifndef LoadScene_h
#define LoadScene_h

#include "ui/CocosGUI.h"
#include"cocostudio/CocoStudio.h"
using namespace cocos2d;
using namespace cocostudio::timeline;
USING_NS_CC;
using namespace ui;

#include <spine/spine-cocos2dx.h>

#include "cocos2d.h"


class LoadScene : public Scene
{
public:
	LoadScene();
    virtual bool init();
    CREATE_FUNC(LoadScene);
public:
	void callBackAddImageAsync(cocos2d::Texture2D *texture);
	void callBackAddPlistAsync(Object* obj, const std::string& plistpath);
	void logic(float dt);
	void loadResources();
	ProgressTimer *addProgress();
	void transitionScene();
private:
	/**
	* Called when the texture (exp. atlas.png) is loading finish, will call this function
	* this function finish build all the SpritFrame by using AtlasLoader
	*/
	ProgressTimer* progressBar;
	int numberOfLoadedRes;
	int totalOfLoadedRes;



	cocos2d::ProgressTimer* loadProgress;//������  
  
    cocos2d::LabelTTF* percentLabel;//���ؽ���label  
    cocos2d::LabelTTF* loadLabel;//��ʾ loading: ��label  
	int m_numSp;//Ҫ���صľ�����Ŀ,��ʼ��Ϊ 20 ��  
    int m_loadedSp;//�Ѽ��صľ�����Ŀ  
};

#endif /* MainMenuScene_hpp */
