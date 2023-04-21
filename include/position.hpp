#if !defined(_POSITION_HPP_)
#define _POSITION_HPP_

class Position
{
private:
    int mX;
    int mY;
public:
    Position(int x, int y);
    ~Position();
    int getX();
    int getY();
    void plusX();
    void plusY();
    void minusX();
    void minusY();
    void random(int minX, int maxX, int minY, int maxY);
    bool operator==(Position &other);
};



#endif // _POSITION_HPP_
