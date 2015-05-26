#ifndef __UNITS__
#define __UNITS__

#pragma once

//#include "cocos2d.h"
#include "Pilots.h"
#include "Weapons.h"

namespace SRW_SYSTEM
{
    struct CustomizeCompleteBonus
    {
        BYTE    HPUp;           //HP+xx%;
        BYTE    ENUp;           //EN+xx%;
        BYTE    mobilityUp;     //運動性+xx%;
        BYTE    armorUp;        //装甲+xx%;
        BYTE    weaponNumUp;    //外挂武器槽+xx;
        BYTE    chipNumUp;      //強化芯片装備数+x;
        bool    unitTerrainAllS;//機体地形適応空以外S;
        //BYTE    特殊能力+; 
        //BYTE    特殊能力+;
        //BYTE    特殊能力+;
        //BYTE    特殊能力+;
        BYTE    meleeWeaponsUp; //格闘武器攻撃力+xx0;
        BYTE    rangeWeaponsUp; //射撃武器攻撃力+xx0;
        BYTE    psiWeaponsUp;   //异能武器攻撃力+xx0;
        BYTE    allWeaponsUp;   //全武器攻撃力+xx0;
        BYTE    weaponsAmmo;    //固定武器弾数+x;
        BYTE    weaponsHitUp;   //武器の命中率+xx%;
        BYTE    weaponsTerrainAllS;//固定武器地形適応S;
        std::string    *name;   //名前[32];
    };

    enum struct SpecialUnitSkill
    {
        None,
        Replication
    };

    class Units
    {
    public:
        std::string *name;
        DWORD   maxHP;      //HP上限
        WORD    maxEN;      //EN上限
        WORD    mobility;   //运动性
        WORD    armor;      //装甲
        WORD    repairCost; //修理费
        WORD    moneyDrop;  //掉落金钱
        WORD    expDrop;    //掉落经验
        BYTE    weaponNum;  //武器槽数量
        BYTE    move;       //移动力
        BYTE    chipNum;    //强化芯片槽数量
        BYTE    maxHPCustomize;         //最大HP改造段数
        BYTE    maxENCustomize;         //最大EN改造段数
        BYTE    maxMobilityCustomize;   //最大运动型改造段数
        BYTE    maxArmorCustomize;      //最大装甲改造段数
        bool    IsTransferable;         //是否可以换乘
        Units   *transformationUnit;    //变形后的机体
        Pilots  *transferPilot[5];      //可换乘驾驶员
        UnitSize size;                  //机体体型
        AdaptationType adaptationType;  //移动类型
        SpecialUnitSkill specialUnitSkill[5];   //特殊能力
        TerrainAdaptation terrainAdaptation;    //地形适应性
        CustomizeCompleteBonus customizeCompleteBonus;  //全改奖励


        Units(void);
        ~Units(void);
    };

    
    
}

#endif
