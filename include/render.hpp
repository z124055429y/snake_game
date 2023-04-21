#if !defined(_RENDER_HPP_)
#define _RENDER_HPP_

#include "size.hpp"
#include "initializer.hpp"
#include "game_welcome.hpp"
#include "game_map.hpp"
#include "game_wall.hpp"
#include "game_status.hpp"
#include "game_snake.h"
#include "game_food.hpp"

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
    void renderGameWindow(Initializer* initializer, GameMap *map, GameWall *wall, GameSnake *snake, GameFood *food, GameStatus *status);
};


#endif // _RENDER_HPP_
