#ifndef LIB_NCURSES_H
#define LIB_NCURSES_H

#include <string>
#include "NCWindow.hpp"

namespace NCurses{
    void Init(void);
    void StdPrint(const std::string& str);
    NCWindow* CreateWindow(int x, int y, int width, int height, std::string name);
}

#endif /* LIB_NCURSES_H */