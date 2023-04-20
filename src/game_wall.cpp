#include <stdlib.h>

#include "game_wall.hpp"

GameWall::GameWall(int rows, int cols): mSize(rows, cols)
{
    pCharMap = (char **)malloc(sizeof(char *) * rows);
    for (int i = 0; i < rows; i++)
    {
        pCharMap[i] = (char *)malloc(sizeof(char) * cols);
    }
}

bool GameWall::contain(Position pos) {
    return pCharMap[pos.getY()][pos.getX()] == WALL_CHAR;
}

void GameWall::shuffleMap(int barrierCount) {
    for (int i = 0; i < mSize.getRows(); i++)
    {
        pCharMap[i][0] = WALL_CHAR;
        pCharMap[i][mSize.getCols() - 1] = WALL_CHAR;
    }
    for (int i = 0; i < mSize.getCols(); i++)
    {
        pCharMap[0][i] = WALL_CHAR;
        pCharMap[mSize.getRows() - 1][i] = WALL_CHAR;
    }
    int i = 0;
    while (i < barrierCount) {
        int y = rand() % (mSize.getRows() - 2) + 1;
        int x = rand() % (mSize.getCols() - 2) + 1;
        if (nearBarrier(x, y)) {
            continue;
        }
        pCharMap[y][x] = WALL_CHAR;
        i++;
    }
    
}

bool GameWall::nearBarrier(int x, int y) {
    for (int i = x - 1; i <= x + 1; i++) {
        for (int j = y - 1; j <= y + 1; j++) {
            if (pCharMap[y][x] == WALL_CHAR) {
                return true;
            }
        }
    }
    return false;
}

GameWall::~GameWall()
{
    for (int i = 0; i < mSize.getRows(); i++)
    {
        free(pCharMap[i]);
    }
    free(pCharMap);
}