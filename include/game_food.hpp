#if !defined(_GAME_FOOD_HPP_)
#define _GAME_FOOD_HPP_

#include "position.hpp"

#define FOOD_CHAR '$'

class GameFood
{
private:
    Position* pPos;
public:
    GameFood();
    ~GameFood();
    void setPos(Position pos);
    bool contain(Position pos);
};

#endif // _GAME_FOOD_HPP_
