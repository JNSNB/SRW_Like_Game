#include "HelloWorldScene.h"

USING_NS_CC;

using namespace cocos2d::ui;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
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
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create("CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    auto label = Label::createWithTTF("Hello World", "fonts/Marker Felt.ttf", 24);
    
    // position the label on the center of the screen
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(label, 1);


    //--------------------------------
    std::string file = "map/MAP_001.tmx";
    _tileMap = TMXTiledMap::create(file);
    _background = _tileMap->layerNamed("Background");

    addChild(_tileMap, -1);

    TMXObjectGroup *objects = _tileMap->getObjectGroup("man");
    CCASSERT(NULL != objects, "'man' object group not found");
    auto spawnPoint = objects->getObject("SpawnPoint");
    CCASSERT(!spawnPoint.empty(), "SpawnPoint object not found");
    int x = spawnPoint["x"].asInt() + 32;
    int y = spawnPoint["y"].asInt() + 32;

    //_player = Sprite::create("selectsquare.png");
    //_player->setPosition(x, y);
    //addChild(_player);


     
    SpriteFrameCache * cache = SpriteFrameCache::sharedSpriteFrameCache();    
    cache -> addSpriteFramesWithFile("UI/selectsquare.plist","UI/selectsquare.png");  

    _player = Sprite::createWithSpriteFrameName("selectsquare1.png");  
    _player->setPosition(x, y); 
    this->addChild( _player );  

    Vector< SpriteFrame* > sfme = Vector< SpriteFrame* >::Vector();  
    char str[20] = {0};  
    for( int i = 0 ; i < 3 ; ++i )  
    {  
        sprintf(str,"selectsquare%d.png",i+1);  
        SpriteFrame *fname = cache -> spriteFrameByName( str );  
        sfme.insert(i, fname );  
    }  
    Animation *animation = Animation::createWithSpriteFrames( sfme , 0.1f );  
    _player->runAction ( RepeatForever::create(Animate::create(animation )));

    chess = new SRPG_SYSTEM::Chess("json/chess.json");
    //chess->sprite = cocos2d::Sprite->create("../233.png");
    chess->sprite->setPosition(x+64,y);
    this->addChild(chess->sprite);
    
    
    //_player->setScale(0.5);
    setViewPointCenter(_player->getPosition());

    //Screen Touch Event Listener
    auto touchListener = EventListenerTouchOneByOne::create();
    //lambda expression: advanced feature in C++ 11
    touchListener->onTouchBegan = [&](Touch *touch, Event *unused_event)->bool { return true; };
    touchListener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);
    this->_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    //Keyboard Event Listener
    auto keyboardListener = EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = CC_CALLBACK_2(HelloWorld::keyPressed, this);
    keyboardListener->onKeyReleased = CC_CALLBACK_2(HelloWorld::keyReleased, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this); // use if your version is below cocos2d-x 3.0alpha.1
    // use this: Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(keyboardListener, this); if you are using cocos2d-x 3.0alpha.1 and later!


    

    //--------------------------------

    return true;
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

//
void HelloWorld::setViewPointCenter(Point position) {
    auto winSize = Director::getInstance()->getWinSize();

    int x = MAX(position.x, winSize.width / 2);
    int y = MAX(position.y, winSize.height / 2);
    x = MIN(x, (_tileMap->getMapSize().width * this->_tileMap->getTileSize().width) - winSize.width / 2);
    y = MIN(y, (_tileMap->getMapSize().height * _tileMap->getTileSize().height) - winSize.height / 2);
    auto actualPosition = Point(x, y);

    auto centerOfView = Point(winSize.width / 2, winSize.height / 2);
    auto viewPoint = centerOfView - actualPosition;
    this->setPosition(viewPoint);
}
void HelloWorld::setViewPointArea(Point position) {

    auto _mapPtr = this->_tileMap;
    auto winSize = Director::getInstance()->getWinSize();
    auto mapSize = Point(_mapPtr->getMapSize().width * _mapPtr->getTileSize().width,
                         _mapPtr->getMapSize().height * _mapPtr->getTileSize().height);
    auto moveEdge = Point( _mapPtr->getTileSize().width*2,_mapPtr->getTileSize().height*2);

    int x = MAX(position.x, moveEdge.x);
    int y = MAX(position.y, moveEdge.y);
    x = MIN(x, mapSize.x - moveEdge.x);
    y = MIN(y, mapSize.y - moveEdge.y);

    auto actualPosition = Point(x, y);
    auto screenPosition = actualPosition + this->getPosition();

    if ((screenPosition.x < moveEdge.x))
    {  
        auto viewPoint = Point(MIN(this->getPositionX()+_mapPtr->getTileSize().width,0) ,this->getPositionY());
        this->setPosition(viewPoint);
    }
    else if (screenPosition.x > (winSize.width - moveEdge.x))
    {
        auto viewPoint = Point(MAX(this->getPositionX()-_mapPtr->getTileSize().width,winSize.width - mapSize.x),
                               this->getPositionY());
        this->setPosition(viewPoint);
    }
    if (screenPosition.y < moveEdge.y)
    {
        auto viewPoint = Point(this->getPositionX(),MIN(this->getPositionY()+_mapPtr->getTileSize().height,0));
        this->setPosition(viewPoint);
    }
    else if (screenPosition.y > (winSize.height - moveEdge.y))
    {
        auto viewPoint = Point(this->getPositionX(),
                               MAX(this->getPositionY()-_mapPtr->getTileSize().height,winSize.height - mapSize.y));
        this->setPosition(viewPoint);
    }
}

void HelloWorld::setPlayerPosition(Point position)
{
    _player->setPosition(position);
}

void HelloWorld::onTouchEnded(Touch *touch, Event *unused_event)
{
    auto touchLocation = touch->getLocation();
    touchLocation = this->convertToNodeSpace(touchLocation);

    auto playerPos = _player->getPosition();
    auto diff = touchLocation - playerPos;
    if (abs(diff.x) > abs(diff.y)) {
        if (diff.x > 0) {
            playerPos.x += _tileMap->getTileSize().width;
        }
        else {
            playerPos.x -= _tileMap->getTileSize().width;
        }
    }
    else {
        if (diff.y > 0) {
            playerPos.y += _tileMap->getTileSize().height;
        }
        else {
            playerPos.y -= _tileMap->getTileSize().height;
        }
    }

    if (playerPos.x <_tileMap->getTileSize().width * _tileMap->getMapSize().width &&
        playerPos.y <_tileMap->getTileSize().height * _tileMap->getMapSize().height &&
        playerPos.y >= 0 &&
        playerPos.x >= 0)
    {
        this->setPlayerPosition(playerPos);
    }

    //this->setViewPointCenter(_player->getPosition());
    this->setViewPointArea(_player->getPosition());
}

void HelloWorld::keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
    //auto playerPos = _player->getPosition();
    //if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
    //{
    //    playerPos.x -= _tileMap->getTileSize().width;
    //}
    //if (playerPos.x <_tileMap->getTileSize().width * _tileMap->getMapSize().width &&
    //    playerPos.y <_tileMap->getTileSize().height * _tileMap->getMapSize().height &&
    //    playerPos.y >= 0 &&
    //    playerPos.x >= 0)
    //{
    //    this->setPlayerPosition(playerPos);
    //}

    //this->setViewPointCenter(_player->getPosition());
}
void HelloWorld::keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
    auto playerPos = _player->getPosition();
    if (keyCode == EventKeyboard::KeyCode::KEY_UP_ARROW)
    {
        playerPos.y += _tileMap->getTileSize().height;
    }
    if (keyCode == EventKeyboard::KeyCode::KEY_DOWN_ARROW)
    {
        playerPos.y -= _tileMap->getTileSize().height;
    }
    if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW)
    {
        playerPos.x -= _tileMap->getTileSize().width;
    }
    if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW)
    {
        playerPos.x += _tileMap->getTileSize().width;
    }

    if (playerPos.x <_tileMap->getTileSize().width * _tileMap->getMapSize().width &&
        playerPos.y <_tileMap->getTileSize().height * _tileMap->getMapSize().height &&
        playerPos.y >= 0 &&
        playerPos.x >= 0)
    {
        this->setPlayerPosition(playerPos);
    }

    //this->setViewPointCenter(_player->getPosition());
    this->setViewPointArea(_player->getPosition());
}


