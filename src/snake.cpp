#include "snake.h"
#include "position.hpp"

Snake::Snake()
{
}

Snake::~Snake()
{
}

void Snake::setBody(std::deque<Position> body) {
    mBody = body;
}

void Snake::setDirect(int dir) {
    mDir = dir;
}

bool Snake::contain(Position pos) {
    for (int i = 0; i < mBody.size(); i++)
    {
        if (mBody[i] == pos) {
            return true;
        }
    }
    return false;   
}

void Snake::move() {
    mBody.pop_front();
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
    mBody.push_back(head);
}
