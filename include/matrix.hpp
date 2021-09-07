#ifndef MATRIX_H
#define MATRIX_H

#include<control.hpp>
#include<elements.hpp>

class matrix
{
private:
    char rd = 46, ru = 46, lu = 46, ld = 46, horizontal = 95, upright = 124;
public:
    char board[35][35];
    int points = 0;
    matrix() = default;
    ~matrix() = default;
    void initBoard(class controls *co);
    void drawBoard(class controls *co, class snake *sk, class food *fo);
};

#endif