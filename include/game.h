#if !defined(_GAME_H_)
#define _GAME_H_

#include <vector>

#include "render.hpp"
#include "game_welcome.hpp"
#include "initializer.hpp"
#include "controller.hpp"

class Game
{
private:
    char *pMap;
    Render *pRender;
    Initializer *pInitializer;
    Controller *pController;
    std::vector<int> mWindow;

    void startTimer();
    void stopTimer();
    /**
     * @return: 操作后，是否退出游戏，注意此处不能使用exit，否则导致终端模式为非标准模式
    */
    bool handle(int cmd, char op);
public:
    Game();
    ~Game();
    void run();
    void render();
};

#endif // _GAME_H_
