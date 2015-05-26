#ifndef __CHESS__
#define __CHESS__

#pragma once
#include "cocos2d.h"
#include "SRPG_System.h"

namespace SRPG_SYSTEM
{
    class Chess
    {
    public:
        BYTE    battlefieldID;  //战场ID
        bool    actionStatus;   //行动状态
        WORD    HP;             //当前血量
        WORD    EN;             //当前EN
        WORD    Move;           //移动力
        cocos2d::Vec2 stayPos;
        cocos2d::Sprite* sprite;

        Chess(void);
        Chess(std::string jsonFilePath);
        ~Chess(void);
        

        virtual void selected2Menu();    //选中显示菜单
        virtual void move2TilePos(cocos2d::Vec2 newTilePos);//移动到某个坐标
        virtual void battleWith(Chess *enemyChess); //战斗
        virtual void showStatus();  //显示属性
        virtual void standBy();     //待机
        virtual void calculateMovement(cocos2d::TMXTiledMap *tileMap);

    };
}

#endif