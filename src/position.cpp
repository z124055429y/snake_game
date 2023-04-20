#include "position.hpp"

Position::Position(int x, int y): mX(x), mY(y)
{
}

Position::~Position()
{
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