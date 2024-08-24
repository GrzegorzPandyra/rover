#include <iostream>
#include "input_if.hpp" 
#include "calib.hpp"
#include <ncurses.h>

static void process_input(char input);

void input_if::input_if_init(void){
    initscr(); /* ncurses */
    noecho(); /* ncurses */ 
    nodelay(stdscr, TRUE); /* ncurses */

    std::cout << "SWC [input_if] init\n\r";
}

void input_if::input_if_run(void){
    int input = getch();
    if(input != ERR){ /* ncurses: ERR = -1 */
        process_input((char)input);
    }
    refresh(); /* ncurses */
}

static void process_input(char input){
    if(input == SYSTEM_TERMINATE_CHAR) {
        endwin(); /* ncurses */
        std::cout << " Rover control program - shutdown complete\n\r";
        exit(0);
    }
}