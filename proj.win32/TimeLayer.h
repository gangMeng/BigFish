#ifndef __TIMER_LAYER_H__
#define __TIMER_LAYER_H__

#include "BasicLayer.h"

USING_NS_CC;

class TimeLayer : public BasicLayer{
public:
	TimeLayer();
	~TimeLayer();

	virtual bool init();

	void setView();

	cocos2d::CCScene* scene();
	void time_counting_down(float t);

	CREATE_FUNC(TimeLayer);

private:
	int counter;
};

#endif //__TIMER_LAYER_H__
