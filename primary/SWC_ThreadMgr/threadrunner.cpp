#include "threadrunner.hpp"
#include <iostream>
#include "SWC_Logger_ClientIf.hpp"

using namespace SWC_Logger::ClientIf;

namespace SWC_ThreadMgr::ThreadRunner
{
    SwcPool* swcPoolPtr;

    void RunThread(SWC_Types::SystemType systype)
    {
        // const timespec SLEEP_TIME = {.tv_nsec = cfg::SYS_THREAD_SLEEP_NS};
        if(nullptr == swcPoolPtr) return;

        do
        {
            std::lock_guard<std::mutex> lock(swcPoolPtr->mtx);
            for(auto& swc : swcPoolPtr->swcs)
            {
                if((systype == swc->systemType))
                {
                    swc->run();
                }
            }
            // nanosleep(&SLEEP_TIME, nullptr);
    
        } while(true);
    }

    void SetSWCPool(SwcPool* swcPool)
    {
        swcPoolPtr = swcPool;
    }
}
