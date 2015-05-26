#ifndef __SRW_SYSTEM__
#define __SRW_SYSTEM__

#include <string>

#define BYTE unsigned char
#define WORD unsigned short int
#define DWORD unsigned int

namespace SRW_SYSTEM
{
    //--------------------------------------
    //"机体"类相关结构体及枚举
    //--------------------------------------
    enum Parts
    {
        acv
    };
    enum struct AdaptationLevel  //适应性枚举
    {
        S,
        A,
        B,
        C,
        D,
        None
    };
    enum struct AdaptationType  //机体类型
    {
        Air,
        Ground,
        Water,
        Sapce
    };
    struct TerrainAdaptation  //地形适应性
    {
        AdaptationLevel Air;
        AdaptationLevel Ground;
        AdaptationLevel Water;
        AdaptationLevel Space;
    };
    enum struct UnitSize  //机体大小枚举
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
    //"驾驶员"类相关结构体及枚举
    //--------------------------------------
    struct QualityGrowth  //属性成长
    {
        BYTE melee[100];    //格斗
        BYTE range[100];    //射击
        BYTE defense[100];  //防御
        BYTE evade[100];    //回避
        BYTE ability[100];  //技量
        BYTE hit[100];      //命中
        BYTE maxSp[100];    //精神
    };
    
    struct Character //性格
    {
        BYTE	hit;        //击中敌机
        BYTE	miss;       //击空
        BYTE	evade;      //回避
        BYTE	beHit;      //被击中
        BYTE	enemyBeat;  //击坠敌机
        BYTE	ourpartBeat;//我方被击坠
        //WORD	???;
        std::string	*name;  //名字
    };

    //--------------------------------------
    //"精神"类相关结构体及枚举
    //--------------------------------------
    enum struct Target  //目标
    {
        Oneself,    //自己
        Ourpart,    //我方
        Motivation, //激励?
        Enemy       //敌方
    };
}

#endif //__SRW_SYSTEM__