#include "ScoreLayer.h"


ScoreLayer::ScoreLayer(void)
{
}


ScoreLayer::~ScoreLayer(void)
{
}

CCScene* ScoreLayer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
   ScoreLayer *layer =ScoreLayer::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool ScoreLayer::init()
{
	bool bRet = false;
	do{

		CC_BREAK_IF( !CCLayer::init());

	
		setView();
		bRet = true;
	
	}while(0);

	return bRet;

}
void ScoreLayer::setView()
{
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	sum=0;
	CCUserDefault::sharedUserDefault()->setIntegerForKey("Score",sum);
	label =CCLabelTTF::create("Score : ", "Arial",35);
	label->setPosition(ccp(100,size.height-100));
	money1=CCLabelTTF::create("0", "Arial",35);
	money1->setPosition(ccp(150,size.height-100));
	this->addChild(label);
	this->addChild(money1,1,333);
}


void ScoreLayer::addScore(int score)
{
	    CCUserDefault::sharedUserDefault()->setIntegerForKey("Score",sum);
		sum=sum+score;
		score=sum;
		CCLabelTTF* pTag=(CCLabelTTF*)this->getChildByTag(333);		
		char tmp[10];
	    sprintf(tmp,"%$%d",sum);
		pTag->setString( tmp );		
}
