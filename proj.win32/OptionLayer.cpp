#include "OptionLayer.h"
#include "..\Classes\HelloWorldScene.h"

OptionLayer::OptionLayer(void)
{
}


OptionLayer::~OptionLayer(void)
{
}

CCScene* OptionLayer::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    OptionLayer *layer = OptionLayer::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

bool OptionLayer::init()
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
void OptionLayer::setView(){

	CCSize size=CCDirector::sharedDirector()->getWinSize();
	//加入menutitle
	CCSprite* title = CCSprite::create("menuTitle.png",CCRectMake(0,0,134,35));

	title->setAnchorPoint(ccp(0.5,1));
	title->setPosition(ccp(size.width/2 ,size.height - 20));
	this->addChild(title);

	//加入menu-- 创建CCMenuItemToggle
	CCMenuItemToggle* music_trigger = CCMenuItemToggle::createWithTarget(
		this,menu_selector(OptionLayer::music_trigger_callback),
		CCMenuItemFont::create("Music :Off"),
		CCMenuItemFont::create("Music :On"),NULL);
	
	music_trigger->setPosition(ccp(size.width/2,size.height/2));

	 //根据背景音乐播放与否来显示相关的文字选项
	if(SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
	{
		music_trigger->setSelectedIndex(1);

	}
	else
	{
		music_trigger->setSelectedIndex(0);
	} 

	//创建回退的CCMenuItem
	CCLabelBMFont* fontofback =CCLabelBMFont::create("Go Back","arial-14.fnt");
	fontofback->setScale(1.5f);
	
	CCMenuItemLabel* backlabel = CCMenuItemLabel::create(fontofback,this,
		menu_selector(OptionLayer::back_callback) );
	backlabel->setAnchorPoint(ccp(0.5,0));
	backlabel->setPosition(ccp(size.width/2,30));

	CCMenu* menu =  CCMenu::create(music_trigger,backlabel,NULL);
	menu->setPosition(CCPointZero);
	//menu->setPosition(ccp(getWinSize().width/2,getWinSize().height/2));
	this->addChild(menu);
}

void OptionLayer::back_callback(CCObject* pSender)
{
	CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(
		0.5f,HelloWorld::scene()));
}


//开关回调函数
void OptionLayer::music_trigger_callback( CCObject* pSender )
{
	
	if(SimpleAudioEngine::sharedEngine()->isBackgroundMusicPlaying())
	{
		SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();		
		CCUserDefault::sharedUserDefault()->setBoolForKey("music_not_playing",true);
		CCLOG("music is stopped");
	}else
	{
		SimpleAudioEngine::sharedEngine()->playBackgroundMusic("mainMainMusic.mp3",true);
		SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();		
		CCUserDefault::sharedUserDefault()->setBoolForKey("music_not_playing",false);
		CCLOG("music is resume");
	}

}

