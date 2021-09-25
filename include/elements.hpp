#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <control.hpp>
#include <matrix.hpp>
#include <time.h>
#include <cstdlib>

class Snake
{
private:
public:
    int snakeX, snakeY;
    char snakeChar = 48;
    int lenght = 3;
    Snake() = default;
    ~Snake() = default;
    void snakePosition();
};

class Food
{
private:
public:
    int foodX, foodY;
    char foodChar = 35;
    Food() = default;
    ~Food() = default;
    void foodPosition();
};

#endif