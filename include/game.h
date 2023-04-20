#if !defined(_GAME_H_)
#define _GAME_H_

#include "render.hpp"
#include "welcome.hpp"

class Game
{
private:
    char *pMap;
    Render *pRender;
    Welcome *welcome;

    void startTimer();
    void stopTimer();
public:
    Game();
    ~Game();
    void run();
    void render();
};

#endif // _GAME_H_
