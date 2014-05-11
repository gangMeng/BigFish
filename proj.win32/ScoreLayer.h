#ifndef __ScoreLayer_H__
#define __ScoreLayer_H__
#include "BasicLayer.h"
using namespace cocos2d;
class ScoreLayer:public BasicLayer
{
public:
	ScoreLayer(void);
	~ScoreLayer(void);
	virtual bool init();
	void setView();
	static cocos2d::CCScene* scene();
	CREATE_FUNC(ScoreLayer);
	void addScore(int score);
public :
	int sum;
	int score;
	cocos2d::CCLabelTTF *m_pLabelLoading;
	cocos2d::CCLabelTTF *m_pLabelPercent;
	cocos2d::CCLabelTTF *label ;
	cocos2d::CCLabelTTF *money1 ;

};
#endif
