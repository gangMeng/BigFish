#ifndef __Turret_H__
#define __Turret_H__
#include "BasicLayer.h"
#include"Fish.h"
using namespace cocos2d;
class Turret:public BasicLayer
{
public:
	Turret();
	~Turret();
	virtual bool init();
	void setView();
	static cocos2d::CCScene* scene();
	bool confirm(int x,int y);
	void spriteRemoveFinished(CCNode* sender);
	bool ccTouchBegan(CCTouch * ctouch,CCEvent * event);	
	void onEnter();
    void onExit();	
	void updateGame1();
	void updateGame2();
	void updateGame3();
	CREATE_FUNC(Turret);
public :
	CCArray* _projectiles;
	int n;
	int m;
};

#endif;
