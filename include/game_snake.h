#if !defined(_SNAKE_H_)
#define _SNAKE_H_

#include <deque>

#include "position.hpp"

#define UP      1
#define DOWN    2
#define LEFT    3
#define RIGHT   4

#define SNAKE_CHAR 'o'

#include "game_element.hpp"

class GameSnake: public GameElement
{
private:
    int mDir;
    std::deque<Position> mBody;
public:
    GameSnake();
    ~GameSnake();
    void setDirect(int dir);
    bool contain(Position pos);
    void setBody(std::deque<Position> body);
    void move(bool isEat);
    Position next();
};




#endif // _SNAKE_H_
