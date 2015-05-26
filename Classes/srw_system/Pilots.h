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
        BYTE    meleeUp;        //���L����+xx%;
        BYTE    rangeUp;        //��Ĺ���+xx%;
        BYTE    counterUp;      //����+xx%;
        BYTE    psiWeaponUp;    //����ϵ�����������`��+xx%;
        BYTE    assistAtkUp;    //Ԯ��+xx%�a��;
        BYTE    damageDown;     //���˺�-xx%�a��;
        BYTE    assistDefUp;    //Ԯ��+xx%�a��;
        BYTE    RangeAtkDamageDown;//�g�ӹ��Ĥα�����`��-xx%;
        BYTE    hitUp;          //����+xx%;
        BYTE    finalHitUp;     //��K����+xx%;
        BYTE    evadeUp;        //�ر�+xx%;
        BYTE    finalevadeUp;   //��K�ر�+xx%;
        BYTE    criticalUp;     //CT�a��+xx%;
        BYTE    expUp;          //�@��EXP+xx%;
        BYTE    moneyUp;        //�@���Y��+xx%;
        BYTE    SPUP;           //SP+;
        BYTE    spirit;         //�a������ָ��;
        BYTE    spiritSPDown;   //�a������ָ�����MSP;
        BYTE    skill;          //�a�����⼼��;
        BYTE    skillUp;        //�a�����⼼��+xx%;
        BYTE    moveUp;         //�Ƅ���+;
        //BYTE	???;
        //BYTE	???;
        //BYTE	???;
        std::string name;       //��ǰ;
    };

    class Pilots
    {
    public:

        BYTE    level;          //�ȼ�
        WORD    SP;             //�������
        BYTE    melee[100];     //��
        BYTE    range[100];     //���
        BYTE    defense[100];   //����
        BYTE    evade[100];     //�ر�
        BYTE    ability[100];   //����
        BYTE    hit[100];       //����
        WORD    experience;     //����
        //WORD      ����;

        QualityGrowth       quality;    //���Գɳ�
        Character           character;  //�Ը�
        AceBonus            aceBonus;   //ACE����
        TerrainAdaptation   terrainAdaptation;  //������Ӧ��
        PilotSpirits        pilotSpirits;       //��ʻԱ����ָ��
        PilotSkills         pilotSkill; //��ʻԱ����

        std::string         *name;      //����
        std::string         *nickname;  //����
        std::string         *bgm;       //BGM

        Pilots(void);
        ~Pilots(void);
    };

    
}



#endif