#include "ncurses_wrapper.hpp" 
#include <ncurses.h>
// #include "../app/ui/ui_logging.hpp"

void ncurses::init(void){
    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);
    
    // LOG("LIB [ncurses] init\n");
}
