#if !defined(_GAME_STATUS_HPP)
#define _GAME_STATUS_HPP

#include "size.hpp"

class GameStatus
{
private:
    Size* pSize;
    int mScore;
    bool mExit;
public:
    GameStatus();
    ~GameStatus();
    Size getSize();
    int getScore();
    void addScore(int plus);
    void exit();
};



#endif // _GAME_STATUS_HPP
