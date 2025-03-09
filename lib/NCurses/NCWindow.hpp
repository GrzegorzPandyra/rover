#ifndef NCWINDOW_H
#define NCWINDOW_H

#include <ncurses.h>
#include <string>

class NCWindow
{
    private:
        WINDOW* m_win;
        const int m_height;
        const int m_width;
        const int m_y;
        const int m_x;
        const std::string m_name;
    public:
        NCWindow(int height, int width, int y, int x, std::string name);
        ~NCWindow();
        void Print(int y, int x, std::string str);
        void Print(std::string str);
        void Refresh(void);
};

#endif /* NCWINDOW_H */