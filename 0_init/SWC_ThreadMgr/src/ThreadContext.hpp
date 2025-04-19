#ifndef THREAD_CONTEXT_H
#define THREAD_CONTEXT_H
#include <thread>
#include <vector>
#include <chrono>
#include "GlobalTypes.hpp"
#include "SwcTypes.hpp"

class ThreadContext
{
    public:
        enum ThreadStatus
        {
            INIT,
            RUNNING,
            SLEEP,
            STOPPED
        };
        ThreadContext(GlobalTypes::SystemType sysType, std::chrono::milliseconds period);
        ~ThreadContext(void);
        std::thread& GetThread(void);
        GlobalTypes::CallResult StopThread(void);
        GlobalTypes::CallResult StartThread(void);
        GlobalTypes::CallResult AddSwc(SWC::Types::SwcContext* swc);
    private:
        std::thread m_thread;
        std::vector<SWC::Types::SwcContext*> m_swcs;
        ThreadStatus m_status;
        const GlobalTypes::SystemType M_SYSTYPE;
        const std::chrono::milliseconds M_PERIOD;
        void ThreadRunner(void);
};

#endif