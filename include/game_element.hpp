#if !defined(_GAME_ELEMENT_HPP_)
#define _GAME_ELEMENT_HPP_

#include "position.hpp"

class GameElement
{
private:
    
public:
    GameElement(/* args */);
    virtual ~GameElement();
    virtual bool contain(Position pos) = 0;
};



#endif // _GAME_ELEMENT_HPP_
