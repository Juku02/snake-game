#ifndef ELEMENTS_H
#define ELEMENTS_H

class snake
{
private:
public:
    int snakeX, snakeY;
    char snakeSymbol = 48;
    int lenght = 3;
    snake() = default;
    ~snake() = default;
    void snakePosition();
};

class food
{
private:
public:
    int foodX, foodY;
    char foodChar = 35;
    food() = default;
    ~food() = default;
    void foodPosition();
};

#endif