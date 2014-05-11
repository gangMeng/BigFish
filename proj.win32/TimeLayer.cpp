#include "TimeLayer.h"

TimeLayer::TimeLayer(){

	counter = 0;
}
TimeLayer::~TimeLayer(){}

CCScene* TimeLayer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
  TimeLayer *layer =TimeLayer::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool TimeLayer::init(){

	setView();
	return true;
}

void TimeLayer::setView(){
	do{
		CCSize size=CCDirector::sharedDirector()->getWinSize();
		CCLabelBMFont* timerFont = CCLabelBMFont::create("Time:0","arial-14.fnt",35);
		//timerFont->setAnchorPoint(CCPointZero);
		timerFont->setPosition(ccp(size.width/2,size.height-100));
		timerFont->setScale(1.5f);
		this->addChild( timerFont,0,15 );
		//加入计时的定时任务
		this->schedule(schedule_selector(TimeLayer::time_counting_down),1.0f);	
	}while(0);

}

//计时的逻辑
void TimeLayer::time_counting_down(float t)
{
	CCLabelBMFont* timerFont = (CCLabelBMFont*) getChildByTag(15);

	char str[20] = {0};
	counter++;
	sprintf(str,"Time:%d",counter);
	timerFont->setString(str);
}