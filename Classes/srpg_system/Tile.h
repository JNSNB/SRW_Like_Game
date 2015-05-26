#ifndef __TILE__
#define __TILE__

#pragma once
#include"SRPG_System.h"
#include "math\Vec2.h"

namespace SRPG_SYSTEM
{
    struct TerrainEffect 
    {
        BYTE    HP;
        BYTE    EN;
        BYTE    DEF;
        BYTE    HIT;
    };

    enum struct TerrainType
    {
        Ground,
        Water,
        GroundOnly,
        Space,
        Moon,
        Impassability
    };

    class Tile
    {
    public:
        cocos2d::Point  coordinate;
        std::string     *terrainName;
        BYTE   moveCostGround;
        BYTE   moveCostWater;
        TerrainEffect   terrainEffect;
        TerrainType terrainType;

        Tile(void);
        ~Tile(void);
    };
}
#endif
