#include <ncurses.h>
#include "NCurses.hpp" 
#include "Logger_ClientIf.hpp"

#define NCURSES_LIB_NAME "NCurses"

void NCurses::Init(void){
    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);
    
    // INFO(NCURSES_LIB_NAME " lib init");
}

void NCurses::StdPrint(const std::string& str){
    wprintw(stdscr, "%s", str.c_str());
    wrefresh(stdscr);
}

NCWindow* NCurses::CreateWindow(int x, int y, int width, int height, std::string name)
{
    return new NCWindow(height, width, y, x, name);
}