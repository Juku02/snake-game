#define SNAKE_GAME_WINDOW_H
#ifdef SNAKE_GAME_WINDOW_H

#include <curses.h>
#include "elements.hpp"
#include <memory>
#include <map>

static void win_delete(WINDOW *win);

class Window
{
private:
    uint32_t m_width,m_height;
    std::unique_ptr< WINDOW,decltype(*win_delete)> window;
    static const std::map<std::string, uint8_t> CHARS_MAP;
    uint8_t board[35][35];
public:
    Window(uint32_t width, uint32_t height) : m_width(width), m_height(height){};
    void initBoard(uint32_t m_width, uint32_t m_height);
    void drawWindow(uint32_t m_width, uint32_t m_height);
    void initWindow();
    void updateWindow();


};

#endif