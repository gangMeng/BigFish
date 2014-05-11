#ifndef __About_H__
#define __About_H__

#include"cocos2d.h"
using namespace cocos2d;
#include "BasicLayer.h"
class AboutLayer:public BasicLayer
{
public:
	AboutLayer(void);
	~AboutLayer(void);
	virtual bool init();
	void setView();

    static cocos2d::CCScene* scene();
	void back_callback(CCObject* pSender);
	CREATE_FUNC(AboutLayer);
};

#endif