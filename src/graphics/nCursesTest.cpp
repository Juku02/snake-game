#include "../../include/graphics/nCursesTest.hpp"

void nCursesTest::sayHello()
{ 

    clear();
    printw("Hello World !!!\n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printw("*");
        }
        printw("\n");
    }
    refresh();
    getch();

 
}

void nCursesTest::makeWindow()
{
    WINDOW *window;
    initscr();
    raw();
    char ch;
    int starty = (LINES - 800) / 2;
    int startx = (COLS - 800) / 2;
    window = newwin(800, 800, starty, startx);
    printw("Type any character to see it in bold\n");
	ch = getch();	
    endwin();
   
}

