#ifndef __PILOTS__
#define __PILOTS__

#pragma once
#include "SRW_System.h"
#include "Spirits.h"
#include "Skills.h"

namespace SRW_SYSTEM
{

    struct AceBonus
    {
        BYTE    meleeUp;        //格闘攻撃+xx%;
        BYTE    rangeUp;        //射撃攻撃+xx%;
        BYTE    counterUp;      //反撃+xx%;
        BYTE    psiWeaponUp;    //异能系武器の与ダメージ+xx%;
        BYTE    assistAtkUp;    //援攻+xx%補正;
        BYTE    damageDown;     //被伤害-xx%補正;
        BYTE    assistDefUp;    //援防+xx%補正;
        BYTE    RangeAtkDamageDown;//間接攻撃の被ダメージ-xx%;
        BYTE    hitUp;          //命中+xx%;
        BYTE    finalHitUp;     //最終命中+xx%;
        BYTE    evadeUp;        //回避+xx%;
        BYTE    finalevadeUp;   //最終回避+xx%;
        BYTE    criticalUp;     //CT補正+xx%;
        BYTE    expUp;          //獲得EXP+xx%;
        BYTE    moneyUp;        //獲得資金+xx%;
        BYTE    SPUP;           //SP+;
        BYTE    spirit;         //補正精神指令;
        BYTE    spiritSPDown;   //補正精神指令消費SP;
        BYTE    skill;          //補正特殊技能;
        BYTE    skillUp;        //補正特殊技能+xx%;
        BYTE    moveUp;         //移動力+;
        //BYTE	???;
        //BYTE	???;
        //BYTE	???;
        std::string name;       //名前;
    };

    class Pilots
    {
    public:

        BYTE    level;          //等级
        WORD    SP;             //精神点数
        BYTE    melee[100];     //格斗
        BYTE    range[100];     //射击
        BYTE    defense[100];   //防御
        BYTE    evade[100];     //回避
        BYTE    ability[100];   //技量
        BYTE    hit[100];       //命中
        WORD    experience;     //经验
        //WORD      换乘;

        QualityGrowth       quality;    //属性成长
        Character           character;  //性格
        AceBonus            aceBonus;   //ACE奖励
        TerrainAdaptation   terrainAdaptation;  //地形适应性
        PilotSpirits        pilotSpirits;       //驾驶员精神指令
        PilotSkills         pilotSkill; //驾驶员技能

        std::string         *name;      //姓名
        std::string         *nickname;  //爱称
        std::string         *bgm;       //BGM

        Pilots(void);
        ~Pilots(void);
    };

    
}



#endif