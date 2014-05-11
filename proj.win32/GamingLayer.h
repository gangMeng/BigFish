#ifndef __Gameing_H__
#define __Gameing_H__

#include"cocos2d.h"
using namespace cocos2d;
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;
#include "BasicLayer.h"
#include "Fish.h"
#include "Turret.h"
#include"ScoreLayer.h"
#include "TimeLayer.h"
#include "DegreeLayer.h"
#include "EnvironmentLayer.h"
#include"pause_Layer.h"
class GamingLayer:public BasicLayer
{
public:
	GamingLayer();
	~GamingLayer();
	virtual bool init();
	void setView();
    static cocos2d::CCScene* scene();
	void background_scroll_logic(float t);
	void Option();
	CCMenu* menu();
	void pause_callback(CCObject* pSender);
	void play_callback(CCObject* pSender);
	Fish* fish;
	Turret* tu;
	ScoreLayer* sc;
	TimeLayer* ti;
	DegreeLayer* de;
	EnvironmentLayer* en;
	pause_Layer* m_pause_layer;
	CREATE_FUNC(GamingLayer);
};

#endif