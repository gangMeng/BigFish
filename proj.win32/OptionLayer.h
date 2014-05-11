#ifndef __Option_H__
#define __Option_H__

#include"cocos2d.h"
using namespace cocos2d;
#include "BasicLayer.h"
class OptionLayer:public BasicLayer
{
public:
	OptionLayer(void);
	~OptionLayer(void);
		virtual bool init();
	void setView();
    static cocos2d::CCScene* scene();
		void back_callback(CCObject* pSender);

	void music_trigger_callback( CCObject* pSender );
	CREATE_FUNC(OptionLayer);
};
#endif();
