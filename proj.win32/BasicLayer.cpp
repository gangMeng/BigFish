#include "BasicLayer.h"
using namespace cocos2d;

BasicLayer::BasicLayer(void)
{
}


BasicLayer::~BasicLayer(void)
{
}

CCScene* BasicLayer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    BasicLayer *layer = BasicLayer::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool BasicLayer::init()
{
		bool bRet = false;
	do{

		CC_BREAK_IF( !CCLayer::init());

		setViews();
		bRet = true;
	
	}while(0);

	return bRet;

}
void BasicLayer::setViews()
{
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	CCSprite* bg=CCSprite::create("bj01.jpg");
	bg->setAnchorPoint(ccp(0.5,0.5));
	bg->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(bg);
}