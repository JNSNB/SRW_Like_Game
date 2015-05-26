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
        BYTE    battlefieldID;  //ս��ID
        bool    actionStatus;   //�ж�״̬
        WORD    HP;             //��ǰѪ��
        WORD    EN;             //��ǰEN
        WORD    Move;           //�ƶ���
        cocos2d::Vec2 stayPos;
        cocos2d::Sprite* sprite;

        Chess(void);
        Chess(std::string jsonFilePath);
        ~Chess(void);
        

        virtual void selected2Menu();    //ѡ����ʾ�˵�
        virtual void move2TilePos(cocos2d::Vec2 newTilePos);//�ƶ���ĳ������
        virtual void battleWith(Chess *enemyChess); //ս��
        virtual void showStatus();  //��ʾ����
        virtual void standBy();     //����
        virtual void calculateMovement(cocos2d::TMXTiledMap *tileMap);

    };
}

#endif