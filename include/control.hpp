#ifndef CONTROLS_H
#define CONTROLS_H

class controls
{
private:
   
public:
    int width, height, speed;
    int up, down, leftd, rightd, key;
    char direction;
    controls() = default;
    ~controls() = default;
    void setOptions();
    void setControls();
    void toCorrect(int &x);
};
#endif