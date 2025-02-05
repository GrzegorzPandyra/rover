#include <iostream>
#include <unistd.h> 
#include "os_scheduler.hpp"
// #include "../ui/ui_logging.hpp"

 #if __cplusplus < 201703L
 #error Invalid C++ version - expecting C++17 or higher
 #endif

int main()
{
    // LOG("Rover control program - initializing...\n");

    if(os_scheduler::OS_SCHDLR_INITIALIZED != os_scheduler::Init()){
        return 1;
    }

    // LOG("Init complete\n\r");

    
    while(1){
        os_scheduler::Run();
    }

    return 0;
}   