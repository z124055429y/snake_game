#include "initializer.hpp"

GameWelcome* Initializer::getWelcome() {
    return pWelcome;
}

GameMap* Initializer::getMap() {
    return pMap;
}

GameWall* Initializer::getWall() {
    return pWall;
}

GameStatus* Initializer::getStatus() {
    return pStatus;
}

Initializer::Initializer()
{
    pWelcome = new GameWelcome();
    pMap = new GameMap(25, 50);
    pWall = new GameWall(25, 50);
    pWall->shuffleMap(10);

    pStatus = new GameStatus();
}

Initializer::~Initializer()
{
    delete pWelcome;
    delete pMap;
    delete pWall;
    delete pStatus;
}