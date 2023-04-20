#include <algorithm>
#include <cstring>

#include "game_welcome.hpp"

GameWelcome::GameWelcome()
{
    // 初始化Welcome文案
    mTitle = "Welcome to Snake Game!!!";
    mSelections.push_back("press [s] to start game");
    mSelections.push_back("press [q] to quit game");

    // 设置Welcome大小，跟随文案大小变化，title和selection中间空1行
    std::vector<const char *> v;
    v.push_back(mTitle);
    for (int i = 0; i < mSelections.size(); i++)
    {
        v.push_back(mSelections[i]);
    }
    
    size_t rows = mSelections.size() + 2;
    size_t cols = 0;

    for (size_t i = 0; i < v.size(); i++)
    {
        cols = std::max(cols, strlen(v[i]));
    }

    pSize = new Size(rows, cols);
}

GameWelcome::~GameWelcome()
{
    delete pSize;
}

Size GameWelcome::getSize() {
    return *pSize;
}

const char* GameWelcome::getTitle() {
    return mTitle;
}

std::vector<const char*> GameWelcome::getSelections() {
    return mSelections;
}