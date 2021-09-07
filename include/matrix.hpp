#ifndef MATRIX_H
#define MATRIX_H

class matrix
{
private:
    /* data */
public:
    char board[35][35];
    char pd = 46, pg = 46, lg = 46, ld = 46, poz = 95, pion = 124;
    int count = 0;
    matrix(/* args */);
    ~matrix();
};

#endif