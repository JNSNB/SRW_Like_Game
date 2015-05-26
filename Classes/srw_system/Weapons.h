#ifndef __WEAPONS__
#define __WEAPONS__

#pragma once
#include "SRW_System.h"

namespace SRW_SYSTEM
{
    class Weapons
    {
    public:
        BYTE    Type1;          //����������1(0���1���L2����);
        BYTE    Type2;          //����������2;
        bool    IsRemovable;    //0�̶�����1�x�k����;
        BYTE    weight;         //ʹ��W���`��;
        BYTE    minRange;       //���xx-??;
        BYTE    maxRange;       //���??-xx;
        BYTE    customizeCost;  //�����M�å�����;
        BYTE    atkUpType;      //�������ϕN������;
        WORD    mapRange;       //MAP�����ι��Ĺ���(ͨ������FFFF);
        BYTE    mapEffect;      //MAP������Ч��;
        BYTE    IsIFF;          //MAP����00�o��e01ζ���R�e;
        BYTE    needSkill;      //��Ҫ����;
        BYTE    needSkillLevel; //��Ҫ����LV;
        WORD    Atk;            //������;
        WORD    HitUp;          //����+;
        WORD    CriticalUp;     //����+;
        WORD    ammo;           //����;
        WORD    maxAmmo;        //�����;
        WORD    EN_Cost;        //���MEN;
        WORD    needWill;       //��Ҫ����;
        TerrainAdaptation   terrainAdaptation;//�����m��;
        bool    IsUsableAfterMove;//P�����v�B;
        std::string    *name;   //��ǰ[32];

        Weapons(void);
        ~Weapons(void);
    };
}

#endif