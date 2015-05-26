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
        BYTE    mobilityUp;     //�\����+xx%;
        BYTE    armorUp;        //װ��+xx%;
        BYTE    weaponNumUp;    //���������+xx;
        BYTE    chipNumUp;      //����оƬװ����+x;
        bool    unitTerrainAllS;//�C������m�������S;
        //BYTE    ��������+; 
        //BYTE    ��������+;
        //BYTE    ��������+;
        //BYTE    ��������+;
        BYTE    meleeWeaponsUp; //���L����������+xx0;
        BYTE    rangeWeaponsUp; //�������������+xx0;
        BYTE    psiWeaponsUp;   //��������������+xx0;
        BYTE    allWeaponsUp;   //ȫ����������+xx0;
        BYTE    weaponsAmmo;    //�̶���������+x;
        BYTE    weaponsHitUp;   //������������+xx%;
        BYTE    weaponsTerrainAllS;//�̶����������m��S;
        std::string    *name;   //��ǰ[32];
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
        DWORD   maxHP;      //HP����
        WORD    maxEN;      //EN����
        WORD    mobility;   //�˶���
        WORD    armor;      //װ��
        WORD    repairCost; //�����
        WORD    moneyDrop;  //�����Ǯ
        WORD    expDrop;    //���侭��
        BYTE    weaponNum;  //����������
        BYTE    move;       //�ƶ���
        BYTE    chipNum;    //ǿ��оƬ������
        BYTE    maxHPCustomize;         //���HP�������
        BYTE    maxENCustomize;         //���EN�������
        BYTE    maxMobilityCustomize;   //����˶��͸������
        BYTE    maxArmorCustomize;      //���װ�׸������
        bool    IsTransferable;         //�Ƿ���Ի���
        Units   *transformationUnit;    //���κ�Ļ���
        Pilots  *transferPilot[5];      //�ɻ��˼�ʻԱ
        UnitSize size;                  //��������
        AdaptationType adaptationType;  //�ƶ�����
        SpecialUnitSkill specialUnitSkill[5];   //��������
        TerrainAdaptation terrainAdaptation;    //������Ӧ��
        CustomizeCompleteBonus customizeCompleteBonus;  //ȫ�Ľ���


        Units(void);
        ~Units(void);
    };

    
    
}

#endif
