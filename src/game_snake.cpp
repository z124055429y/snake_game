#include "game_snake.h"
#include "position.hpp"

GameSnake::GameSnake()
{
}

GameSnake::~GameSnake()
{
}

void GameSnake::setBody(std::deque<Position> body) {
    mBody = body;
}

void GameSnake::setDirect(int dir) {
    mDir = dir;
}

bool GameSnake::contain(Position pos) {
    for (int i = 0; i < mBody.size(); i++)
    {
        if (mBody[i] == pos) {
            return true;
        }
    }
    return false;   
}

Position GameSnake::next() {
    Position head = mBody.back();
    switch (mDir)
    {
    case UP:
        head.minusY();
        break;
    case DOWN:
        head.plusY();
        break;
    case LEFT:
        head.minusX();
        break;
    case RIGHT:
        head.plusX();
        break;
    }
    return head;
}

void GameSnake::move(bool isEat) {
    if (!isEat) {
        mBody.pop_front();
    }
    Position head = next();
    mBody.push_back(head);
}
