#ifndef __DEGREE_LAYER_H__
#define __DEGREE_LAYER_H__

#include "BasicLayer.h"

USING_NS_CC;
class DegreeLayer:public BasicLayer
{
public:
	DegreeLayer(void);
	~DegreeLayer(void);
	virtual bool init();
	void setView();
	cocos2d::CCScene* scene();
	CREATE_FUNC(DegreeLayer);
	void TimeCallBack();
	void changescene();
public:
	int sumTime;
	cocos2d::CCLabelTTF *remTime ;
	cocos2d::CCLabelTTF *labelTime ;
};
#endif
