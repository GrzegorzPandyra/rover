#include <iostream>
#include <unistd.h>
#include "if/SWC_ThreadMgr_SysIf.hpp"
#include "if/NCurses.hpp"
#include "if/SWC_Logger_SysIf.hpp"
#include "if/SWC_StatMon_SysIf.hpp"
#include "if/SWC_Veh_SysIf.hpp"

#if __cplusplus < 201703L
#error Invalid C++ version - expecting C++17 or higher
#endif

int main()
{
    NCurses::Init();
    SWC_ThreadMgr::Init();
    SWC_Logger::SysIf::Init();
    SWC_StatMon::SysIf::Init();
    SWC_Veh::SysIf::Init();

    while(true);  

    return 0;
}

