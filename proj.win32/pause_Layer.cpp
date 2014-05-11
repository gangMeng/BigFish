#include "pause_Layer.h"
#include "GamingLayer.h"

pause_Layer::pause_Layer(void)
{
}


pause_Layer::~pause_Layer(void)
{
}
CCScene* pause_Layer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    pause_Layer *layer = pause_Layer::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool pause_Layer::init()
{
		bool bRet = false;
	do{

		CC_BREAK_IF( !CCLayer::init());

		setViews();
		setView();
		bRet = true;
	
	}while(0);

	return bRet;

}
void pause_Layer::setView(){

	CCSize size=CCDirector::sharedDirector()->getWinSize();
	CCMenuItemImage* play=CCMenuItemImage::create("play.png",
		"play.png",
		this,
		menu_selector(pause_Layer::play_callback)	
		);
	CCMenu* menu=CCMenu::create(play,NULL);
	menu->setPosition(ccp(size.width-200,size.height-100));
	this->addChild(menu);
}
void pause_Layer::play_callback(CCObject* pSender){
	GamingLayer* father=(GamingLayer*)this->getParent();	
	pause_Layer *pa=(pause_Layer*)father;
	father->m_pause_layer->getChildByTag(99);
	pa->setVisible(false);
	/*
	Ga
	father2->getChildByTag(156)->setEnabled(true);

	CCMenu* pMenu=CCMenu::create(option1,NULL);
		pMenu->setPosition(ccp(size.width-200,size.height-100));
		this->addChild(pMenu,5,156);

	*/
	GamingLayer* father2=(GamingLayer*)this->getParent();
	/*
	father2->getChildByTag(156);
	CCMenu* pMenu=(CCMenu*)father2;
	pMenu->setEnabled(true);*/
	father2->menu();
	CCDirector::sharedDirector()->resume();
	//CCDirector::sharedDirector()->replaceScene(GamingLayer::scene());
}