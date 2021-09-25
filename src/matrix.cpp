#include "../include/matrix.hpp"

void Matrix::initBoard()
{
       Control control;
     for (int i = 0; i < control.height; i++)
    {
        for (int j = 0; j < control.width; j++)
        {
            board[j][i] = 'e';
        }
    }
}
void Matrix::drawBoard()
{
    Snake snake;
    Food food;
    Control control;
    int i, j;
    //up frame
    std::cout << lu;
    for (i = 0; i < control.width; i++)
    {
        std::cout <<  horizontal << horizontal;
    }
    std::cout << ru;
    for (i = 0; i < control.height; i++)
    {
        std::cout << std::endl
                  << upright; //left frame
        for (j = 0; j < control.width; j++)
        {
            switch (board[j][i])
            {
            case 'e':
                std::cout << "  ";
                break;
            case 's':
                std::cout << snake.snakeChar << snake.snakeChar;
                break;
            case 'f':
                std::cout << food.foodChar << food.foodChar;
                break;
            }
        }
        std::cout <<  upright; //right frame
    }
    std::cout << std::endl;
    //down frame
    std::cout << ld;
    for (i = 0; i < control.width; i++)
    {
        std::cout << horizontal << horizontal;
    }
    std::cout << rd;

}