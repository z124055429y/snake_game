#if !defined(_SNAKE_H_)
#define _SNAKE_H_

#include <deque>

#include "position.hpp"

#define UP      1
#define DOWN    2
#define LEFT    3
#define RIGHT   4

#include "game_element.hpp"

class Snake: public GameElement
{
private:
    int mDir;
    std::deque<Position> mBody;
public:
    Snake();
    ~Snake();
    void setDirect(int dir);
    bool contain(Position pos);
    void setBody(std::deque<Position> body);
    void move();
};




#endif // _SNAKE_H_
