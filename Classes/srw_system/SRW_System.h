#ifndef __SRW_SYSTEM__
#define __SRW_SYSTEM__

#include <string>

#define BYTE unsigned char
#define WORD unsigned short int
#define DWORD unsigned int

namespace SRW_SYSTEM
{
    //--------------------------------------
    //"����"����ؽṹ�弰ö��
    //--------------------------------------
    enum Parts
    {
        acv
    };
    enum struct AdaptationLevel  //��Ӧ��ö��
    {
        S,
        A,
        B,
        C,
        D,
        None
    };
    enum struct AdaptationType  //��������
    {
        Air,
        Ground,
        Water,
        Sapce
    };
    struct TerrainAdaptation  //������Ӧ��
    {
        AdaptationLevel Air;
        AdaptationLevel Ground;
        AdaptationLevel Water;
        AdaptationLevel Space;
    };
    enum struct UnitSize  //�����Сö��
    {
        SS,
        S,
        M,
        L,
        LL
    };
    //enum PilotSkills
    //{
    //    dili
    //};
    //--------------------------------------
    //"��ʻԱ"����ؽṹ�弰ö��
    //--------------------------------------
    struct QualityGrowth  //���Գɳ�
    {
        BYTE melee[100];    //��
        BYTE range[100];    //���
        BYTE defense[100];  //����
        BYTE evade[100];    //�ر�
        BYTE ability[100];  //����
        BYTE hit[100];      //����
        BYTE maxSp[100];    //����
    };
    
    struct Character //�Ը�
    {
        BYTE	hit;        //���ел�
        BYTE	miss;       //����
        BYTE	evade;      //�ر�
        BYTE	beHit;      //������
        BYTE	enemyBeat;  //��׹�л�
        BYTE	ourpartBeat;//�ҷ�����׹
        //WORD	???;
        std::string	*name;  //����
    };

    //--------------------------------------
    //"����"����ؽṹ�弰ö��
    //--------------------------------------
    enum struct Target  //Ŀ��
    {
        Oneself,    //�Լ�
        Ourpart,    //�ҷ�
        Motivation, //����?
        Enemy       //�з�
    };
}

#endif //__SRW_SYSTEM__