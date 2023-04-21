#if !defined(_INITIALIZER_HPP_)
#define _INITIALIZER_HPP_

#include "game_welcome.hpp"
#include "game_map.hpp"
#include "game_wall.hpp"
#include "game_status.hpp"
#include "game_snake.h"
#include "game_food.hpp"

class Initializer
{
private:
    GameWelcome *pWelcome;
    GameMap *pMap;
    GameWall *pWall;
    GameStatus *pStatus;
    GameSnake *pSnake;
    GameFood *pFood;
    
public:
    Initializer();
    ~Initializer();
    void randomPosition(Position &pos);
    GameWelcome* getWelcome();
    GameMap* getMap();
    GameWall* getWall();
    GameStatus* getStatus();
    GameSnake* getSnake();
    GameFood* getFood();
};



#endif // _INITIALIZER_HPP_
