#ifndef MATRIX_H
#define MATRIX_H

#include <control.hpp>
#include <elements.hpp>

class Matrix
{
private:
    char rd = 46, ru = 46, lu = 46, ld = 46, horizontal = 95, upright = 124;
   
public:
    char board[35][35];
    int X[10000], Y[10000];
    int points = 0;
    Matrix() = default;
    ~Matrix() = default;
    void initBoard();
    void drawBoard();
};

#endif