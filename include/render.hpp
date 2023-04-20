#if !defined(_RENDER_HPP_)
#define _RENDER_HPP_

#include "size.hpp"
#include "game_welcome.hpp"
#include "game_map.hpp"
#include "game_wall.hpp"
#include "game_status.hpp"

class Render
{
private:
    Size mSize;
    char **pCharMap;
public:
    Render(Size size);
    ~Render();
    void clear();
    void refresh();
    /**
     * 渲染Welcome Window
    */
    void renderWelcomeWindow(GameWelcome *welcome);
    /**
     * 渲染Game Window
    */
    void renderGameWindow(GameMap *map, GameWall *wall, GameStatus *status);
};


#endif // _RENDER_HPP_
