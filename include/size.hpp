#if !defined(_SIZE_H_)
#define _SIZE_H_

class Size
{
private:
    int mRows;
    int mCols;
public:
    Size(int rows, int cols);
    ~Size();
    int getRows();
    int getCols();
};



#endif // _SIZE_H_
