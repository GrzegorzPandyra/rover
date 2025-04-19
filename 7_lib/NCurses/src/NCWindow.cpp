#include "NCWindow.hpp" 

constexpr int WINDOW_NAME_X = 4;
constexpr int WINDOW_NAME_Y = 0;

NCWindow::NCWindow(int height, int width, int y, int x, std::string name) 
                        : m_height(height), m_width(width), m_y(y), m_x(x), m_name(name)
{
    m_win = newwin(m_height, m_width, m_y, m_x);
}

NCWindow::~NCWindow()
{
    delete m_win;
}

void NCWindow::Print(std::string str)
{
    wprintw(m_win, str.c_str());
}

void NCWindow::Print(int x, int y, std::string str)
{
    mvwprintw(m_win, y, x, "%s", str.c_str());
}

void NCWindow::Refresh(void)
{
    box(m_win, 0, 0);
    mvwprintw(m_win, WINDOW_NAME_Y, WINDOW_NAME_X, "%s", m_name.c_str());
    wrefresh(m_win);
}