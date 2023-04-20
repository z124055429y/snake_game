#if !defined(_RENDER_HPP_)
#define _RENDER_HPP_

#include "size.hpp"
#include "welcome.hpp"

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
    void renderWelcomeWindow(Welcome *welcome);
};


#endif // _RENDER_HPP_
