#if !defined(_MAP_HPP)
#define _MAP_HPP

#include "size.hpp"

class GameMap
{
private:
    Size mSize;
public:
    GameMap(int rows, int cols);
    ~GameMap();
    Size getSize();
};



#endif // _MAP_HPP
