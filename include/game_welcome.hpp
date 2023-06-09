#if !defined(_WELCOME_HPP_)
#define _WELCOME_HPP_

#include <vector>
#include <algorithm>

#include "size.hpp"

class GameWelcome
{
private:
    Size *pSize;
    const char* mTitle;
    std::vector<const char*> mSelections;
public:
    GameWelcome();
    ~GameWelcome();
    Size getSize();
    const char* getTitle();
    std::vector<const char*> getSelections();
};

#endif // _WELCOME_HPP_
