#ifndef __BASIC_LAYER2_H__
#define __BASIC_LAYER2_H__

#include"cocos2d.h"
using namespace cocos2d;
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
class BasicLayer : public CCLayer
{
public:
	BasicLayer(void);
	~BasicLayer(void);
	virtual bool init();
	void setViews();
    static cocos2d::CCScene* scene();
	CREATE_FUNC(BasicLayer);
};

#endif
