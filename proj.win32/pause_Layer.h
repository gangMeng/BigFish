#ifndef __Pause_H__
#define __Pause_H__

#include"cocos2d.h"
using namespace cocos2d;
#include "BasicLayer.h"
class pause_Layer:public BasicLayer
{
public:
	pause_Layer(void);
	~pause_Layer(void);
	virtual bool init();
	void setView();
    static cocos2d::CCScene* scene();
	void play_callback(CCObject* pSender);
	CREATE_FUNC(pause_Layer);
};
#endif
