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
    void plusX();
    void minusX();
    void plusY();
    void minusY();
    bool operator==(Position &other);
};



#endif // _POSITION_HPP_
