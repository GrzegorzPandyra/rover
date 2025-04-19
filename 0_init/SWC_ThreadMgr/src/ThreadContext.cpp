#include "ThreadContext.hpp"
ThreadContext::ThreadContext(GlobalTypes::SystemType sysType, std::chrono::milliseconds period) :
                                                                                                M_SYSTYPE(sysType),
                                                                                                M_PERIOD(period),
                                                                                                m_thread(&ThreadContext::ThreadRunner, this)
{
    m_status = ThreadStatus::INIT;
}

ThreadContext::~ThreadContext(void)
{

}

GlobalTypes::CallResult ThreadContext::AddSwc(SWC::Types::SwcContext* swc)
{
    m_swcs.emplace_back(swc);
    return GlobalTypes::CALL_OK;
}

void ThreadContext::ThreadRunner(void)
{
    while(m_status == ThreadStatus::INIT);

    do
    {
        std::this_thread::sleep_for(M_PERIOD);
        for(auto swc : m_swcs)
        {
            swc->run();
        }
    } while(m_status == ThreadStatus::RUNNING);
}

std::thread& ThreadContext::GetThread(void)
{
    return m_thread;
}

GlobalTypes::CallResult ThreadContext::StopThread(void)
{
    m_status = ThreadStatus::STOPPED;
    return GlobalTypes::CALL_OK;
}

GlobalTypes::CallResult ThreadContext::StartThread(void)
{
    m_status = ThreadStatus::RUNNING;
    return GlobalTypes::CALL_OK;
}