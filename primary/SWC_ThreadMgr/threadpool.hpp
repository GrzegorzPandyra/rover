#ifndef THREAD_MGR_THREADPOOL_H
#define THREAD_MGR_THREADPOOL_H
#include <array>
#include "cfg/ThreadMgrCfg.hpp"

namespace SWC_ThreadMgr::ThreadPool
{
    typedef void* (*threadPtr)(void * args);
    typedef const std::array<const threadPtr, THREAD_MGR_CFG_NUM_THREADS> ThreadPoolArray;

    void CreateThreads(void);
    ThreadPoolArray& GetThreadPool(void);
}

#endif