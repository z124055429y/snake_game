#if !defined(_GAME_STATUS_HPP)
#define _GAME_STATUS_HPP

#include "size.hpp"

class GameStatus
{
private:
    Size* pSize;
    int mScore;
public:
    GameStatus();
    ~GameStatus();
    Size getSize();
    int getScore();
    void addScore(int plus);
};



#endif // _GAME_STATUS_HPP
