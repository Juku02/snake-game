#ifndef CONTROLS_H
#define CONTROLS_H

class controls
{
private:
    /* data */
public:
    int width, height, speed;
    int up, down, leftd, rightd, key;
    char direction;
    controls(/* args */);
    ~controls();
};
#endif