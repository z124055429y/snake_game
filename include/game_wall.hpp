#if !defined(_GAME_WALL_HPP_)
#define _GAME_WALL_HPP_

#define WALL_CHAR '#'

#include "size.hpp"
#include "game_element.hpp"

class GameWall: public GameElement
{
private:
    Size mSize;
    char **pCharMap;
public:
    GameWall(int rows, int cols);
    ~GameWall();
    bool contain(Position pos);
    void shuffleMap(int barrierCount);
    bool nearBarrier(Position pos, int padding);
};

#endif // _GAME_WALL_HPP_
