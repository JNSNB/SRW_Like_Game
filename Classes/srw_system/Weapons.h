#ifndef __WEAPONS__
#define __WEAPONS__

#pragma once
#include "SRW_System.h"

namespace SRW_SYSTEM
{
    class Weapons
    {
    public:
        BYTE    Type1;          //武器タイプ1(0射撃1格闘2特殊);
        BYTE    Type2;          //武器タイプ2;
        bool    IsRemovable;    //0固定武器1選択武器;
        BYTE    weight;         //使用Wゲージ;
        BYTE    minRange;       //射程xx-??;
        BYTE    maxRange;       //射程??-xx;
        BYTE    customizeCost;  //改造費用タイプ;
        BYTE    atkUpType;      //攻撃力上昇タイプ;
        WORD    mapRange;       //MAP兵器の攻撃範囲(通常武器FFFF);
        BYTE    mapEffect;      //MAP兵器的效果;
        BYTE    IsIFF;          //MAP兵器00無差別01味方識別;
        BYTE    needSkill;      //必要技能;
        BYTE    needSkillLevel; //必要技能LV;
        WORD    Atk;            //攻撃力;
        WORD    HitUp;          //命中+;
        WORD    CriticalUp;     //会心+;
        WORD    ammo;           //弾数;
        WORD    maxAmmo;        //最大弾数;
        WORD    EN_Cost;        //消費EN;
        WORD    needWill;       //必要気力;
        TerrainAdaptation   terrainAdaptation;//地形適応;
        bool    IsUsableAfterMove;//P武器関連;
        std::string    *name;   //名前[32];

        Weapons(void);
        ~Weapons(void);
    };
}

#endif