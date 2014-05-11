#include "OverGameLayer.h"
#include"..\Classes\HelloWorldScene.h"
using namespace cocos2d;
CCScene* OverGameLayer::scene()
{
    CCScene * scene = NULL;
    do 
    {
        // 'scene' is an autorelease object
        scene = CCScene::create();
        CC_BREAK_IF(! scene);

        // 'layer' is an autorelease object
       OverGameLayer *layer =OverGameLayer::create();
        CC_BREAK_IF(! layer);

        // add layer as a child to scene
        scene->addChild(layer);
    } while (0);

    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
bool OverGameLayer::init()
{
	
    bool bRet = false;
    do 
	{
			int score=CCUserDefault::sharedUserDefault()->getIntegerForKey("Score");
			int i;
			name1 = CCUserDefault::sharedUserDefault()->getIntegerForKey("name1");  
			name2 =CCUserDefault::sharedUserDefault()->getIntegerForKey("name2"); 
			if(name2<score)
			{
				if(name1<score)
				{
					i=score;
					score=name1;
					name1=i;

				}
				name2=score;
				
			}
			CCUserDefault::sharedUserDefault()->setIntegerForKey("name1",name1);
					CCUserDefault::sharedUserDefault()->setIntegerForKey("name2",name2);
					CCUserDefault::sharedUserDefault()->flush();
			

        CC_BREAK_IF(! CCLayer::init());

        CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
            "CloseNormal.png",
            "CloseSelected.png",
            this,
            menu_selector(OverGameLayer::menuCloseCallback));
        CC_BREAK_IF(! pCloseItem);

        // Place the menu item bottom-right conner.
        pCloseItem->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width /2- 20, 20));

        // Create a menu with the "close" menu item, it's an auto release object.
        CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
        pMenu->setPosition(CCPointZero);
        CC_BREAK_IF(! pMenu);
		this->addChild(pMenu,1);
		
		CCMenuItemImage *back = CCMenuItemImage::create(
            "back.png",
            "back.png",
            this,
            menu_selector(OverGameLayer::menuBace));
        CC_BREAK_IF(! back);

        // Place the menu item bottom-right conner.
        back->setPosition(ccp(CCDirector::sharedDirector()->getWinSize().width/2+50, 20));

        // Create a menu with the "close" menu item, it's an auto release object.
        CCMenu* pMenu2 = CCMenu::create(back, NULL);
        pMenu2->setPosition(CCPointZero);
        CC_BREAK_IF(! pMenu2);
		this->addChild(pMenu2,1);

        // 2. Add a label shows "Hello World".

        // Create a label and initialize with string "Hello World".
        CCLabelTTF* pLabel = CCLabelTTF::create("You  Lose", "Arial", 24);
        CC_BREAK_IF(! pLabel);

        // Get window size and place the label upper. 
        CCSize size = CCDirector::sharedDirector()->getWinSize();
        pLabel->setPosition(ccp(size.width / 2, size.height - 50));

        // Add the label to HelloWorld layer as a child layer.
        this->addChild(pLabel, 1);

        // 3. Add add a splash screen, show the cocos2d splash image.
        CCSprite* pSprite = CCSprite::create("HelloWorld.png");
        CC_BREAK_IF(! pSprite);

        // Place the sprite on the center of the screen
        pSprite->setPosition(ccp(size.width/2, size.height/2));

        // Add the sprite to HelloWorld layer as a child layer.
        this->addChild(pSprite, 0);

        bRet = true;
    } while (0);
	
    return bRet;
}

void OverGameLayer::menuBace(CCObject* pSender)
{
    // "close" menu item clicked
   CCDirector::sharedDirector()->replaceScene(HelloWorld::scene());
}


void OverGameLayer::menuCloseCallback(CCObject* pSender)
{
    // "close" menu item clicked
    CCDirector::sharedDirector()->end();
}
