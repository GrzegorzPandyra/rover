#include <iostream>
#include <unistd.h>
#include "SWC_ThreadManager_If.hpp"

#if __cplusplus < 201703L
#error Invalid C++ version - expecting C++17 or higher
#endif

int main()
{
    SWC_ThreadMgr::Init();

    while(true);  
    std::cout<<"INFO: === Shutdown complete ===\n";

    return 0;
}

