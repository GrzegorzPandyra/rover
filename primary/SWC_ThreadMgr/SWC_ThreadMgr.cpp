#include <vector>
#include "if/SWC_ThreadMgr_ClientIf.hpp"
#include "if/SWC_ThreadMgr_SysIf.hpp"
#include "threadpool.hpp"
#include "threadrunner.hpp"

namespace SWC_ThreadMgr
{
    using namespace SWC_Types;
    std::vector<SWC_Types::SWC*> swcPool;

    Status Init()
    {
        SWC_ThreadMgr::ThreadPool::CreateThreads();
        SWC_ThreadMgr::ThreadRunner::SetSWCPool(&swcPool);
        return OK;
    }

    Status ClientIf::RegisterSWC(SWC_Types::SWC* swc)
    {
        swcPool.push_back(swc);
        return OK;
    }
}