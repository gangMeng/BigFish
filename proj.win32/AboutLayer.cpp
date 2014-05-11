#include "AboutLayer.h"
#include "..\Classes\HelloWorldScene.h"

AboutLayer::AboutLayer(void)
{
}


AboutLayer::~AboutLayer(void)
{
}

CCScene* AboutLayer::scene()
{
	CCScene* sc =NULL;

	do{
		sc = CCScene::create();
		CC_BREAK_IF( !sc );

		AboutLayer* layer = AboutLayer::create();
		CC_BREAK_IF( !layer);

		sc->addChild( layer );

	} while(0);

	return sc;
}

bool AboutLayer::init()
{
	bool sRet = false;
	do{
	
		CC_BREAK_IF(!BasicLayer::init() );

		setViews();
		setView();

		sRet=true;
	}while(0);

	return sRet;
}
void AboutLayer::setView()
{
	CCSize size=CCDirector::sharedDirector()->getWinSize();
	//加入Title
	CCSprite* title = CCSprite::create("menuTitle.png",CCRectMake(0,34,130,38));
	title->setAnchorPoint(ccp(0.5,1));
	title->setPosition(ccp(size.width/2 + 15,size.height - 20));
	this->addChild(title);
	//加入文字说明
	CCLabelBMFont* pOes = CCLabelBMFont::create("Hello,this is my fish!Here is the ranking ","arial-14.fnt",30);
	pOes->setPosition(ccp(size.width/2,size.height/2));
	this->addChild(pOes);

	int name1,name2;
	name1 = CCUserDefault::sharedUserDefault()->getIntegerForKey("name1");  
	name2= CCUserDefault::sharedUserDefault()->getIntegerForKey("name2");
	char tmp[10];
	sprintf(tmp,"%$%d",name1);
	CCLabelTTF* ttf=CCLabelTTF::create("name1","Arial",35);
	ttf->setString(tmp); 
	ttf->setPosition(ccp(size.width/2,size.height-100));
	this->addChild(ttf);	
	char tmp2[10];
    sprintf(tmp2,"%$%d",name2);
	CCLabelTTF* ttf2=CCLabelTTF::create("nam2","Arial",35);
	ttf2->setString(tmp2); 
	ttf2->setPosition(ccp(size.width/2,size.height-200));
	this->addChild(ttf2);

	//回到欢迎屏幕
	CCLabelBMFont* fontofback =CCLabelBMFont::create("Go Back","arial-14.fnt");
	fontofback->setScale(1.5f);
	
	CCMenuItemLabel* backlabel = CCMenuItemLabel::create(fontofback,this,
		menu_selector(AboutLayer::back_callback) );
	backlabel->setAnchorPoint(ccp(0.5,0));
	backlabel->setPosition(ccp(size.width/2,30));

	CCMenu* menu = CCMenu::create(backlabel,NULL);
	menu->setPosition(CCPointZero);

	this->addChild( menu );
}

void AboutLayer::back_callback(CCObject* pSender)
{
	CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(
		0.5f,HelloWorld::scene()));
}