#ifndef _NCURSES_TEST
#define _NCURSES_TEST

#include <ncurses.h>
#include <iostream>

class nCursesTest
{
private:
    /* data */
public:
    nCursesTest(/* args */) = default;
    ~nCursesTest() = default;
    void sayHello();
    void makeWindow();
};

#endif