#include <vector>
#include <mutex>
#include "if/SWC_ThreadMgr_ClientIf.hpp"
#include "if/SWC_ThreadMgr_SysIf.hpp"
#include "threadpool.hpp"
#include "threadrunner.hpp"

namespace SWC_ThreadMgr
{
    using namespace SWC_Types;

    SWC_ThreadMgr::ThreadRunner::SwcPool swcPool;

    Status Init()
    {
        SWC_ThreadMgr::ThreadPool::CreateThreads();
        SWC_ThreadMgr::ThreadRunner::SetSWCPool(&swcPool);
        return SWC_Types::STATUS_OK;
    }

    Status ClientIf::RegisterSWC(SWC_Types::SWC* swc)
    {
        std::lock_guard<std::mutex> lock(swcPool.mtx);
        swcPool.swcs.push_back(swc);
        return SWC_Types::STATUS_OK;
    }
}