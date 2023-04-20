#include "game_map.hpp"

GameMap::GameMap(int rows, int cols): mSize(rows, cols)
{
}

GameMap::~GameMap()
{
}

Size GameMap::getSize() {
    return mSize;
}