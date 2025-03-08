#include "threadrunner.hpp"
#include <iostream>
#include "SWC_Logger_ClientIf.hpp"

using namespace SWC_Logger::ClientIf;

namespace SWC_ThreadMgr::ThreadRunner
{
    std::vector<SWC_Types::SWC*>* swcPoolPtr;

    void RunThread(SWC_Types::SystemType systype)
    {
        // const timespec SLEEP_TIME = {.tv_nsec = cfg::SYS_THREAD_SLEEP_NS};
        if(nullptr == swcPoolPtr) return;

        do
        {
            for(auto& swc : *swcPoolPtr)
            {
                if((systype == swc->systemType))
                {
                    swc->run();
                }
            }
            // nanosleep(&SLEEP_TIME, nullptr);
    
        } while(true);
    }

    void SetSWCPool(std::vector<SWC_Types::SWC*>* swcPool)
    {
        swcPoolPtr = swcPool;
    }
}
