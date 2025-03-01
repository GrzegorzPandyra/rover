#include <iostream>
#include "ThreadRunner.hpp"


ThreadRunner::ThreadRunner(std::vector<ISWC*> &swc_register) : M_SWC_REGISTER(swc_register)
{ 
    std::cout << __LINE__ <<" Thread Runner created\n";
}

ThreadRunner::~ThreadRunner()
{
}

void ThreadRunner::RunThread(ISWC::SystemType systype)
{
    // const timespec SLEEP_TIME = {.tv_nsec = cfg::SYS_THREAD_SLEEP_NS};
    do
    {
        for(auto& swc : M_SWC_REGISTER)
        {
            if((systype == swc->GetSystemType()) && (swc->GetState() == ISWC::STATE_INIT))
            {
                swc->Run();
            }
        }
        // nanosleep(&SLEEP_TIME, nullptr);

    } while(true);
}
