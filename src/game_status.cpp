#include "game_status.hpp"

GameStatus::GameStatus()
{
    pSize = new Size(1, 40);
}

GameStatus::~GameStatus()
{
    delete pSize;
}

Size GameStatus::getSize() {
    return *pSize;
}
    
int GameStatus::getScore() {
    return mScore;
}

void GameStatus::addScore(int plus) {
    mScore += plus;
}
