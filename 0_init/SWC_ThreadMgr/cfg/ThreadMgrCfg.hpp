/**
 * @brief Thread configuration
 * Make sure the number of threads matches the defined threads
 */
#ifndef THREAD_MGR_CFG_H
#define THREAD_MGR_CFG_H

#include "SWC_Types.hpp"
#include <chrono>

extern "C"
{
    
    void* primary_thread(void * data);
    void* secondary_thread(void * data);
    void* auxiliary_thread(void * data);
    void* diagnostic_thread(void * data);

    #define THREAD_MGR_CFG_THREAD_LIST                  \
                                    primary_thread,     \
                                    secondary_thread,   \
                                    auxiliary_thread,   \
                                    diagnostic_thread
                                    
    #define THREAD_MGR_CFG_NUM_THREADS 4

}

namespace ThreadMgrCfg
{
    using namespace std::chrono;
    using namespace SWC_Types;

    constexpr char       SWC_NAME[]  = "ThreadMgr";
    constexpr SystemType SYSTEM_TYPE = ST_PRIMARY;
    
    constexpr milliseconds GLOBAL_THREAD_PERIOD = milliseconds(10);
}
#endif /* THREAD_MGR_CFG_H */
