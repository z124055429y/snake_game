#include <curses.h>
#include <string.h>

#include "render.hpp"

void Render::clear() {
    for (size_t i = 0; i < mSize.getRows(); i++)
    {
        memset(pCharMap[i], ' ', mSize.getCols());
    }
}

Render::Render(Size size): mSize(size)
{
    pCharMap = (char **)malloc(sizeof(char*) * size.getRows());
    for (int i = 0; i < size.getRows(); i++)
    {
        pCharMap[i] = (char*)malloc(sizeof(char) * size.getCols());
    }
}

void Render::refresh() {
    for (size_t i = 0; i < mSize.getRows(); i++)
    {
        for (size_t j = 0; j < mSize.getCols(); j++)
        {
            mvaddch(i, j, pCharMap[i][j]);
        }
    }
    ::refresh();
}

Render::~Render()
{
    for (int i = 0; i < mSize.getRows(); i++)
    {
        free(pCharMap[i]);
    }
    free(pCharMap);
}

void Render::renderGameWindow(Initializer *initializer, GameMap *map, GameWall *wall, GameSnake* snake, GameFood* food, GameStatus *status) {
    clear();
    const char *tmp = "Game Window";

    memcpy(pCharMap[0], tmp, strlen(tmp));

    Position pos = snake->next();
    if (food->contain(pos)) {
        initializer->randomPosition(pos);
        food->setPos(pos);
        snake->move(true);
        status->addScore(1);
    } else if (wall->contain(pos)) {
        ::exit(0);
    } else {
        snake->move(false);
    }

    Size mapSize = map->getSize();
    Size statusSize = status->getSize();
    int gap = 10;                                   // status 和 map 之间的间距
    int rowRetain = mSize.getRows() - mapSize.getRows() - statusSize.getRows();
    int colRetain = mSize.getCols() - mapSize.getCols() - statusSize.getCols() - gap;

    int mx = colRetain / 2, my = rowRetain / 2;
    for (size_t i = 0; i < mapSize.getRows(); i++)
    {
        for (size_t j = 0; j < mapSize.getCols(); j++)
        {
            if (wall->contain(Position(j, i))) {
                pCharMap[my + i][mx + j] = WALL_CHAR;
            }
            if (food->contain(Position(j, i))) {
                pCharMap[my + i][mx + j] = FOOD_CHAR;
            }
            if (snake->contain(Position(j, i))) {
                pCharMap[my + i][mx + j] = SNAKE_CHAR;
            }
        }
    }

    int sy = my, sx = mx + mapSize.getCols() + gap;
    char buf[256] = {0};
    snprintf(buf, 256, "score = %d", status->getScore());
    memcpy(pCharMap[sy] + sx, buf, strlen(buf));
}

void Render::renderWelcomeWindow(GameWelcome *welcome) {
    clear();
    Size wSize = welcome->getSize();
    int rowRetain = mSize.getRows() - wSize.getRows();
    int colRetain = mSize.getCols() - wSize.getCols();

    int x = colRetain / 2, y = rowRetain / 2;
    char buf[1024] = {0};

    const char *title= welcome->getTitle();
    memcpy(pCharMap[y] + x, title, strlen(title));

    y+=2;

    std::vector<const char*> selections = welcome->getSelections();
    for (size_t i = 0; i < selections.size(); i++)
    {
        memcpy(pCharMap[y + i] + x + 1, selections[i], strlen(selections[i]));
    }
    
}