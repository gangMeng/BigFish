#include "GamingLayer.h"
#include"pause_Layer.h"

GamingLayer::GamingLayer()
{
	
}


GamingLayer::~GamingLayer()
{
}

CCScene* GamingLayer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GamingLayer *layer = GamingLayer::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool GamingLayer::init()
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
void GamingLayer::setView()
{
	fish=Fish::create();
	this->addChild(fish);
	tu=Turret::create();
	this->addChild(tu);
	sc=ScoreLayer::create();
	this->addChild(sc);
	
	ti=TimeLayer::create();
	this->addChild(ti);
	
	de=DegreeLayer::create();
	this->addChild(de);

	en=EnvironmentLayer::create();
	this->addChild(en);

		 m_pause_layer = pause_Layer::create();
		m_pause_layer->setPosition( CCPointZero );
		m_pause_layer->setVisible(false);
		this->addChild(m_pause_layer,10,99);

	Option();
}


void GamingLayer::Option(){

	CCSize size=CCDirector::sharedDirector()->getWinSize();
	{
		CCMenuItemImage *option1=CCMenuItemImage::create("pause.png",
			"pause.png",
			this,
			menu_selector(GamingLayer::pause_callback)		
			); 
		
		CCMenu* pMenu=CCMenu::create(option1,NULL);
		pMenu->setPosition(ccp(size.width-200,size.height-100));
		this->addChild(pMenu,5,156);
	}

}
void GamingLayer::pause_callback(CCObject* pSender){
//1.显示这个pause layer
	getChildByTag(99)->setVisible(true);

	//2.调用CCDirector的pause函数
	CCDirector::sharedDirector()->pause();

	//3.设定CCMenu的enable为false
	CCMenu* menu= (CCMenu*)getChildByTag(156);
	menu->setEnabled(false);

	//4如果背景音乐正在播放应该去暂停它
	if(SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
	{
		SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
	}


}

CCMenu* GamingLayer::menu(){
	CCDirector::sharedDirector()->resume();
	CCMenu* menu2= (CCMenu*)getChildByTag(156);
	//menu2->setEnabled(true);
	
	return menu2;
}

