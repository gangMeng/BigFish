#include "Fish.h"
Fish::Fish()
{
	 _sprite1=CCArray::create();
	 _sprite1->retain();
	 _sprite2=CCArray::create();
	 _sprite2->retain();
	 _sprite3=CCArray::create();
	 _sprite3->retain();
}
Fish::~Fish()
{
	CC_SAFE_DELETE(_sprite1);
	CC_SAFE_DELETE(_sprite2);
	CC_SAFE_DELETE(_sprite3);
}
CCScene* Fish::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Fish *layer = Fish::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}
bool Fish::init()
{
	bool bRet = false;
	do{
		CC_BREAK_IF( !CCLayer::init());		
		setView();
		this->schedule(schedule_selector(Fish::schedu),1.0f);
		if(_sprite1->count()>=10||_sprite2->count()>=10)
		{
			this->unscheduleUpdate();
		}
		bRet = true;	
	}while(0);
	return bRet;
}

void Fish::setView()
{	
	initRedFish();
	initFish();
	initBigFish();
}

void Fish::initRedFish()
{
	addSprite(2.0);
}

void Fish::initFish()
{
	CCTexture2D::PVRImagesHavePremultipliedAlpha(true);
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("fish.plist","fish.png");
	FishNode1=CCSpriteBatchNode::create("fish.png");
	this->addChild(FishNode1);
	addSprite2(1.0);
	addSprite2(2.0);
	addSprite2(3.0);
	addSprite2(4.0);
	addSprite2(5.0);
	addSprite2(6.0);
}

void Fish::initBigFish()
{
	CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("fish3.plist","fish3.png");
	FishNode2=CCSpriteBatchNode::create("fish3.png");
	this->addChild(FishNode2);
	addSprite3(2.0);
}

int Fish::getRand(int start,int end)
{
	 float i = CCRANDOM_0_1()*(end-start+1)+start;  //产生一个从start到end间的随机数
	 return (int)i;
}

void Fish::schedu(float dt)
{
	cc_timeval psv;  
	CCTime::gettimeofdayCocos2d(&psv, NULL);  
	unsigned long int rand_seed = psv.tv_sec*1000 + psv.tv_usec/1000;  
	srand(rand_seed); 
	int i=getRand(0,2);
	switch(i)
		{
			case 0:
				//this->scheduleOnce(schedule_selector(Fish::addSprite), 1.0f)
				addSprite(1.0);break;
			case 1:
				//this->scheduleOnce(schedule_selector(Fish::addSprite2), 1.0f);
				addSprite2(2.0);break;
			case 2:break;
				addSprite3(3.0);break;
		}	
}

void Fish::addSprite(float e)
{
	 CCTexture2D *texture1 = CCTextureCache::sharedTextureCache()->addImage("3.png");
	 float w1=texture1->getContentSize().width/5;
	 float h1=texture1->getContentSize().height;
	 CCSpriteFrame *frame1_0 = CCSpriteFrame::createWithTexture(texture1, CCRectMake(w1*0, 0, w1, h1));  
	 CCSpriteFrame *frame1_1 = CCSpriteFrame::createWithTexture(texture1, CCRectMake(w1*1, 0,w1, h1));
	 CCSpriteFrame *frame1_2 = CCSpriteFrame::createWithTexture(texture1, CCRectMake(w1*2, 0, w1, h1));
	 CCSpriteFrame *frame1_3 = CCSpriteFrame::createWithTexture(texture1, CCRectMake(w1*3, 0, w1, h1));
	 CCSprite* sprite1 = CCSprite::createWithSpriteFrame(frame1_0);
	 sprite1->setPosition(ccp(100+e*50,100+e*50));	
	 this->addChild(sprite1);
	 CCArray* animFrames1=CCArray::create();
	 animFrames1->addObject(frame1_0);
	 animFrames1->addObject(frame1_1);
	 animFrames1->addObject(frame1_2);
	 animFrames1->addObject(frame1_3);
	CCAnimation *animation1  = CCAnimation::createWithSpriteFrames(animFrames1, 0.5f);
	CCAnimate *animate1 = CCAnimate::create(animation1);
	sprite1->runAction( CCRepeatForever::create( CCAnimate::create(animation1) ) );
	ccBezierConfig config;
	config.controlPoint_1=ccp(100+e*50,100+e*50);
	config.controlPoint_2=ccp(300+e*50,300+e*50);
	config.endPosition=ccp(600+e*50,600+e*50);
	CCBezierTo *bezierTo=CCBezierTo::create(10.0f,config);
	CCActionInterval * move = CCMoveBy::create(10,ccp(300+e*50,100+e*50));
	CCActionInterval * move1 = CCMoveTo::create(10, ccp(100+e*50,300+e*50));
	CCFiniteTimeAction* seq = CCSequence::create(bezierTo,move,move1,NULL);
	CCActionInterval * repeatForever =CCRepeatForever::create((CCActionInterval* )seq);
	sprite1->runAction(repeatForever);
	sprite1->setTag(3); 	
	_sprite1->addObject(sprite1);
}

void Fish::addSprite2(float e){	

	CCSize size=CCDirector::sharedDirector()->getWinSize();
	CCSprite* fish1=CCSprite::createWithSpriteFrameName("fish01_01.png");	
	fish1->setPosition(ccp(300+e*20,200+e*20));
	FishNode1->addChild(fish1);	
	CCArray* animFrames_bk = CCArray::createWithCapacity(5);
    char str_bk[100] = {0};
    for(int i = 1; i <=7; i++)
    {
        sprintf(str_bk, "fish01_0%i.png", i);
        CCSpriteFrame *frame_bk = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str_bk);
        animFrames_bk->addObject(frame_bk);
    }

    CCAnimation *animation_bk= CCAnimation::createWithSpriteFrames(animFrames_bk, 0.3f);
    animation_bk->setLoops(-1);    
    fish1->runAction(CCAnimate::create(animation_bk));
	ccBezierConfig config;
	config.controlPoint_1=ccp(30+e*20,30+e*20);
	config.controlPoint_2=ccp(100+e*20,100+e*20);
	config.endPosition=ccp(200+e*20,200+e*20);
	CCBezierTo *bezierTo=CCBezierTo::create(10.0f,config);

	CCActionInterval * move = CCMoveBy::create(10,ccp(300+e*20,100+e*20));
    CCActionInterval * move1 = CCMoveTo::create(10, ccp(100+e*20,300+e*20));
	
    CCFiniteTimeAction* seq = CCSequence::create(bezierTo,move,move1,NULL);
    CCActionInterval * repeatForever =CCRepeatForever::create((CCActionInterval* )seq);
    fish1->runAction(repeatForever);

    CCActionInterval * move2_0 = CCMoveTo::create(10,ccp(700+e*20,100+e*20));
    CCActionInterval * move2_1 = CCMoveTo::create(10, ccp(600+e*20,200+e*20));
	CCPointArray* array=CCPointArray::create(20);
	array->addControlPoint(ccp(650+e*20,100+e*20));
	array->addControlPoint(ccp(620+e*20,120+e*20));
	array->addControlPoint(ccp(600+e*20,180+e*20));
	array->addControlPoint(ccp(530+e*20,350+e*20));
	array->addControlPoint(ccp(450+e*20,360+e*20));
	array->addControlPoint(ccp(450+e*20,400+e*20));
	array->addControlPoint(ccp(450+e*20,450+e*20));
	array->addControlPoint(ccp(420+e*20,470+e*20));
	array->addControlPoint(ccp(320+e*20,500+e*20));
	array->addControlPoint(ccp(290+e*20,450+e*20));
	CCCardinalSplineTo *cardinalSpineTo=CCCardinalSplineTo::create(20.0f,array,0);
    CCFiniteTimeAction* seq2 = CCSequence::create(cardinalSpineTo,move2_0,move2_1,NULL);
    CCActionInterval * repeatForever2 =CCRepeatForever::create((CCActionInterval* )seq2);
    fish1->runAction(repeatForever2);
	_sprite2->addObject(fish1);
}

void Fish::addSprite3(float e){	
	
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	CCSprite* fish1=CCSprite::createWithSpriteFrameName("fish17_01.png");	
	fish1->setPosition(ccp(900+e*20,e*20));
	FishNode2->addChild(fish1);	
	CCArray* animFrames_bk = CCArray::createWithCapacity(5);
    char str_bk[100] = {0};
    for(int i = 1; i <=8; i++)
    {
        sprintf(str_bk, "fish17_0%i.png", i);
        CCSpriteFrame *frame_bk = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(str_bk);
        animFrames_bk->addObject(frame_bk);
    }

    CCAnimation *animation_bk= CCAnimation::createWithSpriteFrames(animFrames_bk, 0.3f);
    animation_bk->setLoops(-1);    
    fish1->runAction(CCAnimate::create(animation_bk));
	ccBezierConfig config;
	config.controlPoint_1=ccp(500+e*20,30+e*20);
	config.controlPoint_2=ccp(100+e*20,100+e*20);
	config.endPosition=ccp(200+e*20,200+e*20);
	CCBezierTo *bezierTo=CCBezierTo::create(10.0f,config);

	CCActionInterval * move = CCMoveBy::create(10,ccp(500+e*20,100+e*20));
    CCActionInterval * move1 = CCMoveTo::create(10, ccp(100+e*20,300+e*20));
	
    CCFiniteTimeAction* seq = CCSequence::create(bezierTo,move,move1,NULL);
    CCActionInterval * repeatForever =CCRepeatForever::create((CCActionInterval* )seq);
    fish1->runAction(repeatForever);

    CCActionInterval * move2_0 = CCMoveTo::create(10,ccp(700+e*20,100+e*20));
    CCActionInterval * move2_1 = CCMoveTo::create(10, ccp(600+e*20,200+e*20));
	CCPointArray* array=CCPointArray::create(20);
	array->addControlPoint(ccp(650+e*20,100+e*20));
	array->addControlPoint(ccp(620+e*20,120+e*20));
	array->addControlPoint(ccp(600+e*20,180+e*20));
	array->addControlPoint(ccp(530+e*20,350+e*20));
	array->addControlPoint(ccp(450+e*20,360+e*20));
	array->addControlPoint(ccp(450+e*20,400+e*20));
	array->addControlPoint(ccp(450+e*20,450+e*20));
	array->addControlPoint(ccp(420+e*20,470+e*20));
	array->addControlPoint(ccp(320+e*20,500+e*20));
	array->addControlPoint(ccp(290+e*20,450+e*20));
	CCCardinalSplineTo *cardinalSpineTo=CCCardinalSplineTo::create(20.0f,array,0);
    CCFiniteTimeAction* seq2 = CCSequence::create(cardinalSpineTo,move2_0,move2_1,NULL);
    CCActionInterval * repeatForever2 =CCRepeatForever::create((CCActionInterval* )seq2);
    fish1->runAction(repeatForever2);
	_sprite3->addObject(fish1);

}


CCArray* Fish::getFishArray()
{
	return _sprite1;
}

CCArray* Fish::getFishArray2(){
	return _sprite2;
}

CCArray* Fish::getFishArray3(){

	return _sprite3;

}
