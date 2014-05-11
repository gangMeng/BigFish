#include "EnvironmentLayer.h"


EnvironmentLayer::EnvironmentLayer(void)
{
}


EnvironmentLayer::~EnvironmentLayer(void)
{
}

CCScene* EnvironmentLayer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    EnvironmentLayer *layer = EnvironmentLayer::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}
bool EnvironmentLayer::init()
{
	bool bRet = false;
	do{
		CC_BREAK_IF( !CCLayer::init());		
		setView();
		bRet = true;	
	}while(0);
	return bRet;
}
void EnvironmentLayer::setView()
{
	CCTexture2D::PVRImagesHavePremultipliedAlpha(true);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("fish3.plist","fish3.png");
	bk_BatchNode=CCSpriteBatchNode::create("fish3.png");
	this->addChild(bk_BatchNode);
	
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("fish2.plist");
	hc_BatchNode=CCSpriteBatchNode::create("fish2.png");
	this->addChild(hc_BatchNode);
	int temp=0;
	for(int i=0;i<5;i++)
	{
		temp=i+1;
		//this->schedule(schedule_selector(EnvironmentLayer::add_NewBk),0.5f);
		//this->schedule(schedule_selector(EnvironmentLayer::add_NewHc),0.5f);
		add_NewBk(temp,temp);
		add_NewHc(temp,temp);
	}
	
	

}

void EnvironmentLayer::add_NewBk(int x,int y)
{
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	CCSprite* bk=CCSprite::createWithSpriteFrameName("bk_01.png");	
	bk->setPosition(ccp(size.width/x+80,size.height/y+200));
	bk_BatchNode->addChild(bk);	
	CCArray* animFrames_bk = CCArray::createWithCapacity(5);
    char str_bk[100] = {0};
    for(int i = 1; i <=7; i++)
    {
        sprintf(str_bk, "bk_0%i.png", i);
        CCSpriteFrame *frame_bk = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str_bk);
        animFrames_bk->addObject(frame_bk);
    }

    CCAnimation *animation_bk= CCAnimation::createWithSpriteFrames(animFrames_bk, 0.3f);
    animation_bk->setLoops(-1);    
    bk->runAction(CCAnimate::create(animation_bk));
}


void EnvironmentLayer::add_NewHc(int x,int y)
{
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	CCSprite* sp_hc=CCSprite::createWithSpriteFrameName("hc_01.png");	
	//this->setAnchorPoint(ccp(0.5f, 0.5f));
	sp_hc->setPosition(ccp(size.width/y+130,size.height/x+100));
	hc_BatchNode->addChild(sp_hc);
	CCArray* animFrames_hc = CCArray::createWithCapacity(5);
    char str[100] = {0};
    for(int i = 1; i <=5; i++)
    {
        sprintf(str, "hc_0%i.png", i);
        CCSpriteFrame *frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str);
        animFrames_hc->addObject(frame);
    }
    CCAnimation *animation_2 = CCAnimation::createWithSpriteFrames(animFrames_hc, 0.3f);
    animation_2->setLoops(-1);    
    sp_hc->runAction(CCAnimate::create(animation_2));

}
