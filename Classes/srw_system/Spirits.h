#ifndef __SPIRITS__
#define __SPIRITS__
#pragma once

#include "SRW_System.h"
namespace SRW_SYSTEM
{
    class Spirits
    {
    public:
        BYTE	SpiritType;    //���
        Target  target;     //���ö���
        bool	IsOtherUse; //�����Ƿ����ʹ��
        BYTE	costSp;     //����SP
        //WORD	�������ֵĵ�һ����;
        std::string	 *name; //����
        std::string	 *introduction; //˵��

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