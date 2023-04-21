#include <deque>

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

GameSnake* Initializer::getSnake() {
    return pSnake;
}

GameFood* Initializer::getFood() {
    return pFood;
}

void Initializer::randomPosition(Position &pos) {
    do {
        pos.random(2, 48, 2, 23);
    } while (pWall->contain(pos) || pSnake->contain(pos));
}

Initializer::Initializer()
{
    pWelcome = new GameWelcome();
    pMap = new GameMap(25, 50);
    pWall = new GameWall(25, 50);
    pWall->shuffleMap(10);

    Position pos(2, 2);
    do {
        pos.random(2, 48, 2, 23);
    } while (pWall->nearBarrier(pos, 2));

    std::deque<Position> body;
    body.push_back(pos);
    pos.minusX();
    body.push_back(pos);
    pSnake = new GameSnake();
    pSnake->setBody(body);
    pSnake->setDirect(RIGHT);
    
    randomPosition(pos);
    pFood = new GameFood();
    pFood->setPos(pos);

    pStatus = new GameStatus();
}

Initializer::~Initializer()
{
    delete pWelcome;
    delete pMap;
    delete pWall;
    delete pStatus;
}