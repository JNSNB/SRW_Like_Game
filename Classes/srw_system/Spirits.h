#ifndef __SPIRITS__
#define __SPIRITS__
#pragma once

#include "SRW_System.h"
namespace SRW_SYSTEM
{
    class Spirits
    {
    public:
        BYTE	SpiritType;    //类别
        Target  target;     //作用对象
        bool	IsOtherUse; //他人是否可以使用
        BYTE	costSp;     //消耗SP
        //WORD	精神名字的第一个字;
        std::string	 *name; //名字
        std::string	 *introduction; //说明

        Spirits(void);
        ~Spirits(void);
    };

    class PilotSpirits
    {
    public:
        Spirits	*spirits[6];
        BYTE    lernLevel[6];
        BYTE    costSp[6];

        PilotSpirits(void);
        ~PilotSpirits(void);
    };

    

}



#endif