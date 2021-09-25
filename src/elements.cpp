#include "../include/elements.hpp"

void Snake::snakePosition()
{
    srand(time(NULL));
    snakeX = rand() % control.width;
    snakeY = rand() % control.height;

    ma.board[snakeX][snakeY] = 's';

}

void Food::foodPosition()
{
    srand(time(NULL));
    foodX = rand() % control.width;
    foodY = rand() % control.height;

    ma.board[foodX][foodY] = 'f';
}