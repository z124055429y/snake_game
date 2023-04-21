#include "game_food.hpp"

GameFood::GameFood()
{
    pPos = new Position(0, 0);
}

void GameFood::setPos(Position pos) {
    *pPos = pos;
}

GameFood::~GameFood()
{
    delete pPos;
}

bool GameFood::contain(Position pos) {
    return pos == *pPos;
}