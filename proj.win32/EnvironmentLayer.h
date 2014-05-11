#ifndef __Environment_H__
#define __Environment_H__

#include"cocos2d.h"
#include "BasicLayer.h"
using namespace cocos2d;
class EnvironmentLayer:public BasicLayer
{
public:
	EnvironmentLayer(void);
	~EnvironmentLayer(void);
	virtual bool init();
	void setView();
	void add_NewBk(int x,int y);
	void add_NewHc(int x,int y);
	static cocos2d::CCScene* scene();
	CCSpriteBatchNode* bk_BatchNode;
	CCSpriteBatchNode* hc_BatchNode;
	CREATE_FUNC(EnvironmentLayer);
};
#endif
