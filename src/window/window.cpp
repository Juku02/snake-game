#include "window/window.hpp"

const std::map<std::string, uint8_t>Window::CHARS_MAP = {
    {"CORNER", '.'},
    {"SIDE", '|'},
    {"BASE", '-'},
    {"SNAKE", 'O'},
    {"FOOD", '$'}};

static void win_delete(WINDOW* win) 
{
    delwin(win);
}   

void Window::initBoard(uint32_t width,uint32_t height)
{

    for (uint32_t i = 0; i < height; i++)
    {
        for (uint32_t j = 0; j < width; j++)
        {
            board[j][i] = 'e';
        }
    }
}

void Window::drawWindow(uint32_t width,uint32_t height)
{
    int i, j;
    // up frame
    addch(CHARS_MAP.at("CORNER")); //dot
    for (i = 0; i < m_width; i++)
    {
      addch(CHARS_MAP.at("BASE"));
    }
    addch(CHARS_MAP.at("CORNER"));
    for (i = 0; i < m_height; i++)
    {
        addch('\n');
        addch(CHARS_MAP.at("SIDE")); //left frame
        for (j = 0; j < m_width; j++)
        {
            switch (board[j][i])
            {
            case 'e':
                addch(' ');
                break;
            // case 's':
            //     addch(CHARS_MAP.at("SNAKE"));
            //     // std::cout << snake.snakeChar << snake.snakeChar;
            //     break;
            // case 'f':
            //     addch(CHARS_MAP.at("FOOD"));
            //     // std::cout << food.foodChar << food.foodChar;
            //     break;
            }
        }
       addch(CHARS_MAP.at("SIDE")); //right frame
    }
    addch('\n');
    //down frame
    addch(CHARS_MAP.at("CORNER"));
    for (i = 0; i < m_width; i++)
    {
        addch(CHARS_MAP.at("BASE"));
       
    }
    addch(CHARS_MAP.at("CORNER"));

}
void Window::initWindow()
{
   
    initscr();
    cbreak();
    raw();
    char ch;
    uint32_t starty = (LINES - m_height) / 2;
    uint32_t startx = (COLS - m_width) / 2;
    using win = std::unique_ptr<WINDOW, decltype(&win_delete)>;
    win windows(newwin(m_width, m_height, starty, startx),&win_delete);
    // initBoard(m_width,m_height);
    // drawWindow(m_width,m_height);
	ch = getch();
    

}


void Window::updateWindow()
{
}