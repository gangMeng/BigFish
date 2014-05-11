#ifndef __Fish_H__
#define __Fish_H__

#include"cocos2d.h"
#include "BasicLayer.h"
#include "Box2D/Box2D.h"
using namespace cocos2d;
class Fish:public BasicLayer
{
public :
	 CCArray* _sprite1;
	 CCArray* _sprite2;
	 CCArray* _sprite3;
public:
	Fish();
	~Fish();
	void addSprite(float e);
	void addSprite2(float e);
	void addSprite3(float e);
	virtual bool init();
	void setView();
	int getRand(int start,int end);	
	void schedu(float dt);	
	CCArray* getFishArray();
	CCArray* getFishArray2();
	CCArray* getFishArray3();
	void initFish();
	void initRedFish();
	void initBigFish();
	CCSpriteBatchNode* FishNode1;
	CCSpriteBatchNode* FishNode2;
	static cocos2d::CCScene* scene();
	
	CREATE_FUNC(Fish);
};

#endif