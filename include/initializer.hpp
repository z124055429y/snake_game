#if !defined(_INITIALIZER_HPP_)
#define _INITIALIZER_HPP_

#include "game_welcome.hpp"
#include "game_map.hpp"
#include "game_wall.hpp"
#include "game_status.hpp"

class Initializer
{
private:
    GameWelcome *pWelcome;
    GameMap *pMap;
    GameWall *pWall;
    GameStatus *pStatus;
    
public:
    Initializer();
    ~Initializer();
    GameWelcome* getWelcome();
    GameMap* getMap();
    GameWall* getWall();
    GameStatus* getStatus();
};



#endif // _INITIALIZER_HPP_
