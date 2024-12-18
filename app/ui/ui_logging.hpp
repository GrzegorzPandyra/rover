#ifndef UI_LOGGING_H
#define UI_LOGGING_H
    #include "ncurses.h"
    #include <string.h>

    const uint8_t UI_DEFAULT_LOG_BUFFER_SIZE = 100u;
    extern char log_buff[];

    #define LOG(str) (wprintw(stdscr, (str)))
    #define LOG_FORMATED_1(format, data1) \
        sprintf(log_buff, format, data1);\
        wprintw(stdscr, (log_buff))
    #define LOG_FORMATED_2(format, data1, data2) \
        sprintf(log_buff, format, data1, data2);\
        wprintw(stdscr, (log_buff))

#endif