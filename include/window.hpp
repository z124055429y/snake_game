#if !defined(_WINDOW_H_)
#define _WINDOW_H_

#include "position.hpp"
#include "size.hpp"

class Window
{
private:
    Position mPos;
    Size mSize;
public:
    Window(Position pos, Size size);
    ~Window();
    Position getPosition();
    Size getSize();
};



#endif // _WINDOW_H_
