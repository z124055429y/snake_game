#if !defined(_GAME_FOOD_HPP_)
#define _GAME_FOOD_HPP_

#include "position.hpp"
#include "game_element.hpp"

#define FOOD_CHAR '$'

class GameFood: public GameElement
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
