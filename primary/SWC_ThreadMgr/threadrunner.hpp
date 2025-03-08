#ifndef THREAD_MGR_THREADRUNNER_H
#define THREAD_MGR_THREADRUNNER_H
#include <vector>
#include "SWC_Types.hpp"

namespace SWC_ThreadMgr::ThreadRunner
{
    void RunThread(SWC_Types::SystemType systype);
    void SetSWCPool(std::vector<SWC_Types::SWC*>* swcPool);
}

#endif