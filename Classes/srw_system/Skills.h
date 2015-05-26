#ifndef __SKILLS__
#define __SKILLS__
#pragma once
#include "SRW_System.h"

namespace SRW_SYSTEM
{

    enum struct SkillType
    {
        Attack,
        Defence,
        Assist,
        Will,
        Special
    };

    class Skills
    {
    public:
        bool IsToLearn;
        bool IsHierarchical;
        SkillType skillType;
        BYTE costPP[9];
        BYTE maxLevel;
        std::string	 *name; //Ãû×Ö
        std::string	 *introduction; //ËµÃ÷

        Skills(void);
        ~Skills(void);
    };

    class PilotSkills
    {
    public:
        Skills skills[6];
        BYTE   learnLevel[6];

        PilotSkills(void);
        ~PilotSkills(void);
    };

}

#endif
