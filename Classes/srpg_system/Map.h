#ifndef __MAP__
#define __MAP__

#pragma once
#include"cocos2d.h"
#include"SRPG_System.h"
#include"Tile.h"


namespace SRPG_SYSTEM
{
    class Map
    {
    public:
        cocos2d::TMXTiledMap *tileMap;




        Map(void);
        Map(std::string tileMapFilePat);
        ~Map(void);
    };
}

#endif // !__MAP__




