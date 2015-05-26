#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "CocosGUI.h"
#include "srpg_system/Chess.h"

class HelloWorld : public cocos2d::Layer
{
private:
    cocos2d::TMXTiledMap *_tileMap;
    cocos2d::TMXLayer *_background;
    cocos2d::Sprite *_player;

    SRPG_SYSTEM::Chess *chess;
    //cocos2d::Animate* createAnimate();

public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    void setViewPointCenter(cocos2d::Point position);
    void setViewPointArea(cocos2d::Point position);

    void setPlayerPosition(cocos2d::Point position);
    void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *unused_event);
    void keyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);
    void keyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);


    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
};

#endif // __HELLOWORLD_SCENE_H__
