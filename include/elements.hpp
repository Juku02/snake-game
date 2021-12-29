#ifndef _SNAKE_GAME_ELEMENTS_H
#define _SNAKE_GAME_ELEMENTS_H


#include <time.h>
#include <cstdlib> 

class Elements
{
private:
public:
    uint32_t snakeX, snakeY,foodX, foodY;
    uint32_t lenght = 3;
    Elements() = default;
    ~Elements() = default;
    void snakePosition();
    void foodPosition();

};
#endif