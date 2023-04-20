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

void Render::renderWelcomeWindow(Welcome *welcome) {
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