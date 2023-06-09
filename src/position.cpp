#include <stdlib.h>

#include "position.hpp"

Position::Position(int x, int y): mX(x), mY(y)
{
}

Position::~Position()
{
}

int Position::getX() {
    return mX;
}

int Position::getY() {
    return mY;
}

bool Position::operator==(Position &other) {
    return this->mX == other.mX && this->mY == other.mY;
}

void Position::plusX() {
    mX++;
}

void Position::minusX() {
    mX--;
}

void Position::plusY() {
    mY++;
}

void Position::minusY() {
    mY--;
}

void Position::random(int minX, int maxX, int minY, int maxY) {
    mY = rand() % (maxY - minY + 1) + minY;
    mX = rand() % (maxX - minX + 1) + minX;
}