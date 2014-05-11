#include "DegreeLayer.h"
#include"MarkLayer.h"

DegreeLayer::DegreeLayer(void)
{
}


DegreeLayer::~DegreeLayer(void)
{
}
CCScene* DegreeLayer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
  DegreeLayer *layer =DegreeLayer::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool DegreeLayer::init(){

	setView();
	return true;
}

void DegreeLayer::setView(){

	CCSize size = CCDirector::sharedDirector()->getWinSize();
	sumTime=10;
	labelTime =CCLabelTTF::create("Degree: ", "arial-14.fnt",25);
	labelTime->setPosition(ccp(size.width-150,size.height-100));
	remTime=CCLabelTTF::create("10", "arial-14.fnt",25);
	remTime->setPosition(ccp(size.width-100,size.height-100));
	this->addChild(labelTime);
	this->addChild(remTime,1,555);
}


void DegreeLayer::TimeCallBack()
{
		sumTime=sumTime-1;		
		CCLabelTTF* tag=(CCLabelTTF*)this->getChildByTag(555);
		CCLog("%d",sumTime);
		char tmp[10];
		sprintf(tmp,"%^%d",sumTime);  
		tag->setString(tmp);
		if (sumTime==0)
		{
			this->runAction(CCSequence::create(
				CCDelayTime::create(1),
				CCCallFunc::create(this,callfunc_selector(DegreeLayer::changescene)),
				NULL));					
		}
}

void DegreeLayer::changescene(){  

	CCScene * scene2=MarkLayer::scene();
	///CCTransitionCrossFadeÇÐ»»·½Ê½
	CCTransitionScene * s1=CCTransitionCrossFade::create(2,scene2);
	CCDirector::sharedDirector()->replaceScene(MarkLayer::scene());
}  