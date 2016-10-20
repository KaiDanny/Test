#include "Common.h"

//// ����֡�����Ľӿڣ�
//Sprite* newFramesSprte(const char* plist, const char*png,
//	const char*name_format, int index, int count, float time)
//{
//	char name[128];
//	// �����Ƿ�
//	if (count <= 0 || plist == NULL || png == NULL) {
//		return NULL;
//	}
//
//	// ��Դ���ؽ�����
//	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
//	frameCache->addSpriteFramesWithFile(plist, png);
//
//	int i = 0;
//	Vector<SpriteFrame*> animFrames;
//	for (i = index; i < index + count; i++) {
//		sprintf(name, name_format, i);
//		SpriteFrame* frame = frameCache->getSpriteFrameByName(name);
//		animFrames.pushBack(frame);
//	}
//
//	Animation* animation = Animation::createWithSpriteFrames(animFrames, time);
//	Animate* anim = Animate::create(animation);
//
//	Sprite* it = Sprite::create();
//	
//	// ��ʼ��Ϊ��һ֡
//	// player01-%04d.png  player01-0000.png
//	sprintf(name, name_format, index);
//	SpriteFrame* frame = frameCache->getSpriteFrameByName(name);
//	it->setSpriteFrame(frame);
//	// end
//
//	it->runAction(CCRepeatForever::create(anim));
//
//	return it;
//}
//
//// ����֡�����Ľӿڣ�
//void setFramesSprte(Sprite* it, const char* plist, const char*png,
//	const char*name_format, int index, int count, float time)
//{
//	char name[128];
//	// �����Ƿ�
//	if (count <= 0 || plist == NULL || png == NULL) {
//		return;
//	}
//
//	// begin
//	it->cleanup(); // ���һ����ǰ�Ķ�����
//	// end
//
//	// ��Դ���ؽ�����
//	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
//	frameCache->addSpriteFramesWithFile(plist, png);
//
//	int i = 0;
//	Vector<SpriteFrame*> animFrames;
//	for (i = index; i < index + count; i++) {
//		sprintf(name, name_format, i);
//		SpriteFrame* frame = frameCache->getSpriteFrameByName(name);
//		animFrames.pushBack(frame);
//	}
//
//	Animation* animation = Animation::createWithSpriteFrames(animFrames, time);
//	Animate* anim = Animate::create(animation);
//
//	// Sprite* it = Sprite::create();
//
//	// ��ʼ��Ϊ��һ֡
//	// player01-%04d.png  player01-0000.png
//	sprintf(name, name_format, index);
//	SpriteFrame* frame = frameCache->getSpriteFrameByName(name);
//	it->setSpriteFrame(frame);
//	// end
//
//	it->runAction(CCRepeatForever::create(anim));
//
//	return;
//}
//
//
//// ����֡�����Ľӿڣ�
//void setFramesSprteOnce(Sprite* it, const char* plist, const char*png,
//	const char*name_format, int index, int count, float time)
//{
//	char name[128];
//	// �����Ƿ�
//	if (count <= 0 || plist == NULL || png == NULL) {
//		return;
//	}
//
//	// begin
//	it->cleanup(); // ���һ����ǰ�Ķ�����
//	// end
//
//	// ��Դ���ؽ�����
//	SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
//	frameCache->addSpriteFramesWithFile(plist, png);
//
//	int i = 0;
//	Vector<SpriteFrame*> animFrames;
//	for (i = index; i < index + count; i++) {
//		sprintf(name, name_format, i);
//		SpriteFrame* frame = frameCache->getSpriteFrameByName(name);
//		animFrames.pushBack(frame);
//	}
//
//	Animation* animation = Animation::createWithSpriteFrames(animFrames, time);
//	Animate* anim = Animate::create(animation);
//
//	// Sprite* it = Sprite::create();
//
//	// ��ʼ��Ϊ��һ֡
//	// player01-%04d.png  player01-0000.png
//	sprintf(name, name_format, index);
//	SpriteFrame* frame = frameCache->getSpriteFrameByName(name);
//	it->setSpriteFrame(frame);
//	// end
//
//	it->runAction((anim));
//
//	return;
//}
//float calRadianByTwoPoint(const CCPoint& beginPoint, const CCPoint& endPoint)
//{
//	float radian;
//	Point shootVector = ccpSub(endPoint, beginPoint);
//	radian = ccpToAngle(shootVector);
//	return radian;
//}
//float calAngleByTwoPoint(const CCPoint& beginPoint, const CCPoint& endPoint)
//{
//	float angle;
//	Point shootVector = ccpSub(endPoint, beginPoint);
//	float shootAngle = ccpToAngle(shootVector);
//	angle = CC_RADIANS_TO_DEGREES(-1 * shootAngle);
//	return angle;
//}