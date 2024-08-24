#include <iostream>
#include <unistd.h> 
#include "../os/os_scheduler.hpp"

int main()
{
    std::cout << "Rover control program - initializing...\n\r";

    if(os_scheduler::OS_SCHDLR_INITIALIZED != os_scheduler::Init()){
        return 1;
    }

    std::cout << "Init complete\n\r" << std::endl;

    
    while(1){
        os_scheduler::Run();
    }

    return 0;
}   