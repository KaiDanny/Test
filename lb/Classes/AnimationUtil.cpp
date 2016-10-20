#include "AnimationUtil.h"
USING_NS_CC;

Animation *AnimationUtil::createWithSingleFrameName(const std::string name, float delay,
	int iLoops)
{

	SpriteFrameCache *cache = SpriteFrameCache::getInstance();
	Vector<SpriteFrame*> frameVec;
	SpriteFrame *frame = NULL;
	char str[50] = { 0 };
	int index = 1;
	do{
		sprintf(str, name.c_str(), index++);
		frame = cache->getSpriteFrameByName(str);
		/*不断地获取SpriteFrame对象，知道获取的值NULL*/
		if (frame == NULL)
		{
			break;
		}
		frameVec.pushBack(frame);
	} while (true);
	Animation *animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(iLoops);
	animation->setRestoreOriginalFrame(true);
	animation->setDelayPerUnit(delay);
	return animation;
}
Animation *AnimationUtil::createWithFrameNameAndNum(const std::string name, int indexFrame, int iNum,float delay, int iLoops)
{
	SpriteFrameCache *cache = SpriteFrameCache::getInstance();
	Vector<SpriteFrame*> frameVec;
	SpriteFrame *frame = NULL;
	char str[50] = { 0 };
	int index = indexFrame;
	for (int i = 1; i <= iNum; i++){
		sprintf(str, name.c_str(), index++);
		frame = cache->getSpriteFrameByName(str);
		if (frame == NULL)
		{
			break;
		}
		frameVec.pushBack(frame);
	}
	Animation *animation = Animation::createWithSpriteFrames(frameVec);
	animation->setLoops(iLoops);
	animation->setRestoreOriginalFrame(true);
	animation->setDelayPerUnit(delay);
	return animation;
}
