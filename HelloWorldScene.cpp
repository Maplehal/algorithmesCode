#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
   visibleSize = Director::getInstance()->getVisibleSize();
    
    return true;
}

void HelloWorld::onEnter(){

    Layer::onEnter();
    addBall(visibleSize.width/2, visibleSize.height/2);
    addEdges();
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [this](Touch *t,Event *){
    
        this->addBall(t->getLocation());
        
        return false;
    };
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

}
void HelloWorld::addBall(cocos2d::Vec2 position)
{
    addBall(position.x,position.y);

}
void HelloWorld::addEdges ()
{
    auto body = PhysicsBody::createEdgeBox(visibleSize);
    
    auto edgeShape =Node::create();
    edgeShape->setPhysicsBody(body);
    edgeShape->setPosition(visibleSize.width/2,visibleSize.height/2);
    addChild(edgeShape);
}

void HelloWorld:: addBall(float PositionX,float PositionY)
{
    Sprite * ball = Sprite::create("IconicTileSmall.png");
    ball->setPhysicsBody(PhysicsBody::createBox(ball->getContentSize()));
    ball->setPosition(PositionX, PositionY);
    addChild(ball);
    

}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
