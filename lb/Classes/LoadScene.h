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



	cocos2d::ProgressTimer* loadProgress;//进度条  
  
    cocos2d::LabelTTF* percentLabel;//加载进度label  
    cocos2d::LabelTTF* loadLabel;//显示 loading: 的label  
	int m_numSp;//要加载的精灵数目,初始化为 20 张  
    int m_loadedSp;//已加载的精灵数目  
};

#endif /* MainMenuScene_hpp */
