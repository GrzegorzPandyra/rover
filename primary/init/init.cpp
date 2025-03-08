#include <iostream>
#include <unistd.h>
#include "if/SWC_ThreadMgr_SysIf.hpp"
#include "if/SWC_Logger_SysIf.hpp"

#if __cplusplus < 201703L
#error Invalid C++ version - expecting C++17 or higher
#endif

int main()
{
    std::cout<<"INFO: === START ===\n";
    SWC_ThreadMgr::Init();
    SWC_Logger::SysIf::Init();

    while(true);  
    std::cout<<"INFO: === Shutdown complete ===\n";

    return 0;
}

