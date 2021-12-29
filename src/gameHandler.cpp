#include "gameHandler.hpp"

void GameHandler::displayWindow(std::unique_ptr<Window> window)
{
    initscr();
    // window->initWindow();
    endwin();
}