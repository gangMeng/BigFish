#include "MarkLayer.h"
#include "OverGameLayer.h"
using namespace cocos2d;
extern int sore;
CCScene* MarkLayer::scene()
{
    CCScene * scene = NULL;
    do 
    {

        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
        MarkLayer *layer =MarkLayer::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MarkLayer::init()
{
    bool bRet = false;
    do 
    {   /**/
		char tmp[20] = {0};
		int score=CCUserDefault::sharedUserDefault()->getIntegerForKey("Score");
		sprintf(tmp,"Score:%d",score);
		CCLabelTTF* pLabel = CCLabelTTF::create("Your total score is", "Arial", 24);
        CC_BREAK_IF(! pLabel);
        CCSize size = CCDirector::sharedDirector()->getWinSize();
        pLabel->setPosition(ccp(size.width / 2, size.height - 150));
        this->addChild(pLabel, 1);
		CCLabelTTF* pLabel2=CCLabelTTF::create("","Arial",24);
		pLabel2->setString(tmp);
		pLabel2->setPosition(ccp(size.width / 2, size.height - 200));
		this->addChild(pLabel2,2);
		this->runAction(CCSequence::create(
				CCDelayTime::create(3),
				CCCallFunc::create(this,callfunc_selector(MarkLayer::changescene)),
				NULL));
        bRet = true;		
    } while (0);
    return bRet;
}

void MarkLayer::changescene(){  

CCScene * scene2=OverGameLayer::scene();
///CCTransitionCrossFadeÇÐ»»·½Ê½
CCTransitionScene * s1=CCTransitionCrossFade::create(2,scene2);
CCDirector::sharedDirector()->replaceScene(OverGameLayer::scene());
} 

