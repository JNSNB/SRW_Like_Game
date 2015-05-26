#include "Map.h"

using namespace SRPG_SYSTEM;
Map::Map(void)
{
}
Map::Map(std::string tileMapFilePath)
{
    this->tileMap = cocos2d::TMXTiledMap::create(tileMapFilePath);
}

Map::~Map(void)
{
}
