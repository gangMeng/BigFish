#include "HelloWorldScene.h"
#include "..\proj.win32\BasicLayer.h"
#include "..\proj.win32\GamingLayer.h"
#include "..\proj.win32\OptionLayer.h"
#include "..\proj.win32\AboutLayer.h"
USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize size = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
	setViews();
	//加入菜单项
	//第一步:加入菜单
	 CCSprite* pStartNormal = CCSprite::create("menu.png",CCRectMake(0,0,126,33));
	 CCSprite* pStartPressed = CCSprite::create("menu.png",CCRectMake(0,33,126,33));
	 CCSprite* pStartDisabled = CCSprite::create("menu.png",CCRectMake(0,66,126,33));

	 CCMenuItemSprite* startGame = CCMenuItemSprite::create(pStartNormal,pStartPressed,pStartDisabled,this,
		 menu_selector(HelloWorld::startgame_callback));

	 //第二步：加入关于菜单
	 CCSprite* pAboutNormal = CCSprite::create("menu.png",CCRectMake(255,0,126,33));
	 CCSprite* pAboutPressed = CCSprite::create("menu.png",CCRectMake(255,33,126,33));
	 CCSprite* pAboutDisabled = CCSprite::create("menu.png",CCRectMake(255,66,126,33));

	 CCMenuItemSprite* aboutGame = CCMenuItemSprite::create(pAboutNormal,pAboutPressed,pAboutDisabled,this,
		 menu_selector(HelloWorld::aboutgame_callback));

	 //第三步：加入选项菜单,
	 CCSprite* pOptionNormal = CCSprite::create("menu.png",CCRectMake(126,0,126,33));
	 CCSprite* pOptionPressed = CCSprite::create("menu.png",CCRectMake(126,33,126,33));
	 CCSprite* pOptionDisabled = CCSprite::create("menu.png",CCRectMake(126,66,126,33));

	 CCMenuItemSprite* optionGame = CCMenuItemSprite::create(pOptionNormal,pOptionPressed,pOptionDisabled,this,
		 menu_selector(HelloWorld::optiongame_callback));

	 //创建菜单
	 CCMenu* pMenu = CCMenu::create(startGame,optionGame,aboutGame,NULL);
	 pMenu->setPosition(ccp(size.width/2,size.height/2));
	 pMenu->alignItemsVerticallyWithPadding(10);

	 this->addChild( pMenu );
  
    
    return true;
}
void HelloWorld::startgame_callback(CCObject* pSender)
{
	CCLog("start");
	CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f,GamingLayer::scene()));
}

void HelloWorld::aboutgame_callback(CCObject* pSender)
{
	CCLog("about");
	CCDirector::sharedDirector()->pushScene( CCTransitionFade::create(0.5f,AboutLayer::scene()));
}

void HelloWorld::optiongame_callback(CCObject* pSender)
  {
	CCLog("option");
	CCDirector::sharedDirector()->pushScene( CCTransitionFade::create(0.5f,OptionLayer::scene()));
}
void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
