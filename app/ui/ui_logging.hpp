#ifndef UI_LOGGING_H
#define UI_LOGGING_H
    #include "ncurses.h"
    #include <string.h>

    const uint8_t UI_DEFAULT_LOG_BUFFER_SIZE = 50u;

    #define LOG(str) (wprintw(stdscr, (str)))
    #define LOG_FORMATED_1(buff, format, data1) \
        sprintf(buff, format, data1);\
        wprintw(stdscr, (buff))
    #define LOG_FORMATED_2(buff, format, data1, data2) \
        sprintf(buff, format, data1, data2);\
        wprintw(stdscr, (buff))

#endif