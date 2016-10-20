#ifndef __cmzd__AnimationUtil__
#define __cmzd__AnimationUtil__
#include <cocos2d.h>
USING_NS_CC;

class AnimationUtil
{
public:
	/*�����ļ�����ǰ׺������������*/
	static Animation *createWithSingleFrameName(const std::string name, float delay, int iLoops);
	/*�����ļ���ǰ׺������������ָ������ͼƬ����*/
	static Animation *createWithFrameNameAndNum(const std::string name, int indexFrame, int iNum,float delay,int iLoops);
};
#endif /* defined(__mxpp__AnimationUtil__) */
