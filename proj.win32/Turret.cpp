#include "Turret.h"
#include "GamingLayer.h"

Turret::Turret()
{
	_projectiles=CCArray::create();
	_projectiles->retain();
}


Turret::~Turret()
{
	CC_SAFE_DELETE(_projectiles);
}

CCScene* Turret::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    Turret *layer = Turret::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool Turret::init()
{
	bool bRet = false;
	do{

		CC_BREAK_IF( !CCLayer::init());

	
		setView();
		bRet = true;
	
	}while(0);

	return bRet;

}
void Turret::setView()
{
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	CCTexture2D* turret=CCTextureCache::sharedTextureCache()->addImage("dapao^007_007_060_100.png");
	float w=turret->getContentSize().width/13;
	float h=turret->getContentSize().height;
	CCSpriteFrame* frame0;
	frame0=CCSpriteFrame::createWithTexture(turret,CCRectMake(w*7,0,w,h));
	CCSprite* sprite=CCSprite::createWithSpriteFrame(frame0); 
	sprite->setPosition(ccp(size.width/2,size.height/6));
	this->addChild(sprite,3,111);
}
bool Turret::confirm(int x,int y)
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();
	CCSprite *projectile = CCSprite::create("NetCast6.png");
	projectile->setPosition(ccp(-300,800));
	projectile->setScale(0.5);
	_projectiles->addObject(projectile);
	this->addChild(projectile);
	CCMoveTo *move=CCMoveTo::create(0.01f,ccp(x,y));
	//CCFiniteTimeAction *sequence=CCSequence::create(CCDelayTime::create(1.2f),move,CCDelayTime::create(0.5f),CCCallFunc::create(this,callfunc_selector(startGame2::updateGame)),CCCallFunc::create(this,callfunc_selector(startGame2::updateGame2)),CCCallFunc::create(this,callfunc_selector(startGame2::updateGame3)),CCCallFuncN::create(this,callfuncN_selector(startGame2::spriteMoveFinished)),CCCallFunc::create(this,callfunc_selector(startGame2::TimeCallBack)),NULL);
	CCFiniteTimeAction *sequence=CCSequence::create(CCDelayTime::create(1.2f),move,CCDelayTime::create(0.5f),CCCallFunc::create(this,callfunc_selector(Turret::updateGame1)),CCCallFunc::create(this,callfunc_selector(Turret::updateGame2)),CCCallFunc::create(this,callfunc_selector(Turret::updateGame3)),CCCallFuncN::create(this,callfuncN_selector(Turret::spriteRemoveFinished)),NULL);
	projectile->runAction(sequence);
	projectile->setTag(2);
	return true;
}
bool Turret::ccTouchBegan(CCTouch * ctouch,CCEvent * event)
{		
	CCPoint location = ctouch->getLocationInView ();
	location = CCDirector::sharedDirector()->convertToGL(location);   
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();	
	CCSize size = CCDirector::sharedDirector()->getWinSize();
	CCSprite* cannon=(CCSprite*)this->getChildByTag(111);
	CCPoint direction=ccp(location.x-winSize.width/2,location.y-30);
	float degree=(float)atan2(direction.y,direction.x);
	CCActionInterval * rotateto = CCRotateTo::create(0.2, 90-degree*180/acos(-1.0));  
	CCFiniteTimeAction *sequence0=CCSequence::create(rotateto ,CCDelayTime::create(0.5f),NULL);
	cannon->runAction(sequence0);

	CCTexture2D* turret2=CCTextureCache::sharedTextureCache()->addImage("zidang.png");
	int w=turret2->getContentSize().width/7;
	int h=turret2->getContentSize().height;
	CCSpriteFrame* frame1;
	frame1=CCSpriteFrame::createWithTexture(turret2,CCRectMake(w*5,0,w,h));
	CCSprite* projectile=CCSprite::createWithSpriteFrame(frame1);
	projectile->setScale(0.7);
	projectile->setPosition(ccp(size.width/2,size.height/6));
	this->addChild(projectile,3);
	CCMoveTo* action = CCMoveTo::create(1.0f, ccp(location.x,location.y));  
	CCActionInterval * easeRateAction = CCEaseRateAction::create(action, 3);
	projectile->setRotation(90-degree*180/acos(-1.0));
	CCActionInterval * rotateto2 = CCRotateTo::create(0.3, 90-degree*180/acos(-1.0));  
	CCFiniteTimeAction *sequence=CCSequence::create(rotateto2,easeRateAction,CCCallFuncN::create(this,callfuncN_selector(Turret::spriteRemoveFinished)),NULL);
	projectile->runAction(sequence);
	confirm(location.x,location.y);
	n=location.x;
	m=location.y;
	projectile->setTag(2);	
	GamingLayer* father=(GamingLayer*)this->getParent();
	father->de->TimeCallBack();
	return true;
}

void Turret::spriteRemoveFinished(CCNode* sender)
{
	CCSprite *sprite = (CCSprite *)sender;
	this->removeChild(sprite, true);//删除精灵
	if (sprite->getTag() == 2) // // 如果是projectile话从_projectile中删除
	{
		_projectiles->removeObject(sprite);
	}
}


void Turret::onEnter(){
//开启触屏监听
	CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,0,false);
	CCLayer::onEnter();//一定不要忘了
}

void Turret::onExit(){
//关闭触屏监听
	CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCLayer::onExit();//一定不要忘了
}

void Turret::updateGame1(){		
	
    CCObject* it=NULL;
    CCObject* jt = NULL;
    CCARRAY_FOREACH(_projectiles,it){ 
        CCSprite *projectile=dynamic_cast<CCSprite*>(it);
        CCRect projectileRect =CCRectMake(
        projectile->getPosition().x-150 - (projectile->getContentSize().width/2+100),
        projectile->getPosition().y-150-(projectile->getContentSize().height/2+100),     
		projectile->getContentSize().width-100,
        projectile->getContentSize().height-100);
        CCArray* targetsToDelete=new CCArray;     
		GamingLayer* father=(GamingLayer*)this->getParent();
		CCArray* _sprite1=father->fish->getFishArray();		
        CCARRAY_FOREACH(_sprite1,jt)//循环每一个敌人
        {				
			CCSize winSize = CCDirector::sharedDirector()->getWinSize();
            CCSprite *sprite2 = dynamic_cast<CCSprite*>(jt);//将数组中的对象强转化成CCSprite
            CCRect sprite2Rect = CCRectMake(
            sprite2->getPosition().x-300 - (sprite2->getContentSize().width/2+150),
            sprite2->getPosition().y-300 - (sprite2->getContentSize().height/2+150),
            sprite2->getContentSize().width-100,
            sprite2->getContentSize().height-100);
            if (projectileRect.intersectsRect(sprite2Rect)) //这里做矩形交集检测，如果两者有产生交集则将需要删除的敌人存放于数组里面
            {
			
				CCTexture2D* turret=CCTextureCache::sharedTextureCache()->addImage("3.png");
				int  w=turret->getContentSize().width/5;
				int  h=turret->getContentSize().height;
				CCSpriteFrame *frame0=CCSpriteFrame::createWithTexture(turret,CCRectMake(w*0,0,w,h));
				CCSpriteFrame *frame1=CCSpriteFrame::createWithTexture(turret,CCRectMake(w*1,0,w,h));
				CCSpriteFrame *frame2=CCSpriteFrame::createWithTexture(turret,CCRectMake(w*2,0,w,h));
				CCSpriteFrame *frame3=CCSpriteFrame::createWithTexture(turret,CCRectMake(w*3,0,w,h));
				CCSprite *sprite=CCSprite::createWithSpriteFrame(frame0);
				sprite->setPosition(ccp(n,m));
				this->addChild(sprite);
				CCArray *animFrames=CCArray ::create();
				animFrames->addObject(frame0);
				animFrames->addObject(frame1);
				animFrames->addObject(frame2);
				animFrames->addObject(frame3);
				CCAnimation *animation=CCAnimation::createWithSpriteFrames(animFrames,0.1f);
				CCAnimate *animate=CCAnimate::create(animation);
				sprite->runAction(CCRepeatForever::create(animate));				
				CCActionInterval *jumpby=CCJumpTo::create(0.3,ccp(n,m),35,5);					
				CCFiniteTimeAction *sequence=CCSequence::create(jumpby,CCCallFuncN::create(this,callfuncN_selector(Turret::spriteRemoveFinished)),NULL);
				sprite->runAction(sequence);
				
                targetsToDelete->addObject(sprite2);
				//projectileToDelete->addObject(projectile);
				GamingLayer* father=(GamingLayer*)this->getParent();
				father->sc->addScore(5);			
            }
			
        }
         CCARRAY_FOREACH(targetsToDelete, jt)//循环需要删除的敌人
         {
             CCSprite *sprite2 = dynamic_cast<CCSprite*>(jt);
			//将敌人从产生的敌人数组里面删除1
			 GamingLayer* father=(GamingLayer*)this->getParent();
			 father->fish->removeChild(sprite2, true);//从图层删除  
			 _sprite1->removeObject(sprite2);
          }
         targetsToDelete->release();
		 
    }
	/*
    CCARRAY_FOREACH(projectileToDelete,it){ //最后循环飞镖将飞镖删除掉

        CCSprite *projectile =dynamic_cast<CCSprite*>(it);
        _projectiles->removeObject(projectile);
        this->removeChild(projectile,true);
    }
    projectileToDelete->release();
	*/
}


void Turret::updateGame2(){			
	
    CCObject* it=NULL;
    CCObject* jt = NULL;
    CCARRAY_FOREACH(_projectiles,it){ 
        CCSprite *projectile=dynamic_cast<CCSprite*>(it);
        CCRect projectileRect =CCRectMake(
        projectile->getPosition().x-200 - (projectile->getContentSize().width/2),
        projectile->getPosition().y-200-(projectile->getContentSize().height/2),     
		projectile->getContentSize().width-100,
        projectile->getContentSize().height-100);
        CCArray* targetsToDelete=new CCArray;     
		GamingLayer* father=(GamingLayer*)this->getParent();
		CCArray* _sprite2=father->fish->getFishArray2();
		CCLog("aaaaaaaaaaa%d",_sprite2->count());		
        CCARRAY_FOREACH(_sprite2,jt)//循环每一个敌人
        {				
			CCSize winSize = CCDirector::sharedDirector()->getWinSize();
            CCSprite *sprite2 = dynamic_cast<CCSprite*>(jt);//将数组中的对象强转化成CCSprite
            CCRect sprite2Rect = CCRectMake(
            sprite2->getPosition().x-100 - (sprite2->getContentSize().width/2),
            sprite2->getPosition().y-100 - (sprite2->getContentSize().height/2),
            sprite2->getContentSize().width,
            sprite2->getContentSize().height);
			
            if (projectileRect.intersectsRect(sprite2Rect)) //这里做矩形交集检测，如果两者有产生交集则将需要删除的敌人存放于数组里面
            {								
                targetsToDelete->addObject(sprite2);
				GamingLayer* father=(GamingLayer*)this->getParent();
				father->sc->addScore(3);			
            }			
        }
         CCARRAY_FOREACH(targetsToDelete, jt)//循环需要删除的敌人
         {
             CCSprite *sprite2 = dynamic_cast<CCSprite*>(jt);
			//将敌人从产生的敌人数组里面删除1
			 GamingLayer* father=(GamingLayer*)this->getParent();
			 father->fish->FishNode1->removeChild(sprite2, true);
			 _sprite2->removeObject(sprite2);
          }
         targetsToDelete->release();		 
    }

}

void Turret::updateGame3(){			
	
    CCObject* it=NULL;
    CCObject* jt = NULL;
    CCARRAY_FOREACH(_projectiles,it){ 
        CCSprite *projectile=dynamic_cast<CCSprite*>(it);
        CCRect projectileRect =CCRectMake(
        projectile->getPosition().x+300 - (projectile->getContentSize().width/2),
        projectile->getPosition().y+300-(projectile->getContentSize().height/2),     
		projectile->getContentSize().width-100,
        projectile->getContentSize().height-100);
        CCArray* targetsToDelete=new CCArray;     
		GamingLayer* father=(GamingLayer*)this->getParent();
		CCArray* _sprite3=father->fish->getFishArray3();
		CCLog("aaaaaaaaaaa%d",_sprite3->count());		
        CCARRAY_FOREACH(_sprite3,jt)//循环每一个敌人
        {				
			CCSize winSize = CCDirector::sharedDirector()->getWinSize();
            CCSprite *sprite2 = dynamic_cast<CCSprite*>(jt);//将数组中的对象强转化成CCSprite
            CCRect sprite2Rect = CCRectMake(
            sprite2->getPosition().x-500 - (sprite2->getContentSize().width/2),
            sprite2->getPosition().y-500 - (sprite2->getContentSize().height/2),
            sprite2->getContentSize().width,
            sprite2->getContentSize().height);
			
            if (projectileRect.intersectsRect(sprite2Rect)) //这里做矩形交集检测，如果两者有产生交集则将需要删除的敌人存放于数组里面
            {								
                targetsToDelete->addObject(sprite2);
				GamingLayer* father=(GamingLayer*)this->getParent();
				father->sc->addScore(30);			
            }			
        }
         CCARRAY_FOREACH(targetsToDelete, jt)//循环需要删除的敌人
         {
             CCSprite *sprite2 = dynamic_cast<CCSprite*>(jt);
			//将敌人从产生的敌人数组里面删除1
			 GamingLayer* father=(GamingLayer*)this->getParent();
			 father->fish->FishNode2->removeChild(sprite2, true);
			 _sprite3->removeObject(sprite2);
          }
         targetsToDelete->release();		 
    }
	
}