#include "elements.hpp"

void Elements::snakePosition()
{
    srand(time(NULL));
    snakeX = rand() % width;
    snakeY = rand() % control.height;

    ma.board[snakeX][snakeY] = 's';

}

void Elements::foodPosition()
{
    srand(time(NULL));
    foodX = rand() % control.width;
    foodY = rand() % control.height;

    ma.board[foodX][foodY] = 'f';
}