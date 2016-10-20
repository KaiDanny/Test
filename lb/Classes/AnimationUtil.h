#ifndef __cmzd__AnimationUtil__
#define __cmzd__AnimationUtil__
#include <cocos2d.h>
USING_NS_CC;

class AnimationUtil
{
public:
	/*根据文件名字前缀创建动画对象*/
	static Animation *createWithSingleFrameName(const std::string name, float delay, int iLoops);
	/*根据文件名前缀创建动画对象，指定动画图片数量*/
	static Animation *createWithFrameNameAndNum(const std::string name, int indexFrame, int iNum,float delay,int iLoops);
};
#endif /* defined(__mxpp__AnimationUtil__) */
