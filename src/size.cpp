#include "size.hpp"

Size::Size(int rows, int cols):mRows(rows), mCols(cols)
{
}

Size::~Size()
{
}

int Size::getCols() {
    return mCols;
}

int Size::getRows() {
    return mRows;
}