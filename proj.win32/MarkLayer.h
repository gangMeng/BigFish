#ifndef __Mark_SCENE_H__
#define __Mark_SCENE_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

class MarkLayer : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    // there's no 'id' in cpp, so we recommand to return the exactly class pointer
    static cocos2d::CCScene* scene();
	int Time;
	int name1;
	int name2;
	void changescene();
    // implement the "static node()" method manually
    CREATE_FUNC(MarkLayer);
};
#endif