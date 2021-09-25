#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>

class Control
{
private:
public:
    int width, height, speed;
    int up, down, leftd, rightd, key;
    char direction;

    Control() = default;
    ~Control() = default;
    void setOptions();
    void setControls();
    void toCorrect(int &x);
};
#endif