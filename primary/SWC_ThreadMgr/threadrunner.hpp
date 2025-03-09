#ifndef THREAD_MGR_THREADRUNNER_H
#define THREAD_MGR_THREADRUNNER_H
#include <vector>
#include <mutex>
#include "SWC_Types.hpp"

namespace SWC_ThreadMgr::ThreadRunner
{
    struct SwcPool
    {
        std::vector<SWC_Types::SWC*> swcs;
        std::mutex mtx;
    };

    void RunThread(SWC_Types::SystemType systype);
    void SetSWCPool(SwcPool* swcPool);
}

#endif