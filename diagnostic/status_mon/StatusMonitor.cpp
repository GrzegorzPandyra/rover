#include <iostream>
#include "StatusMonitor.hpp"
#include "ThreadManager.hpp"

StatusMonitor* StatusMonitor::m_statusMonitorPtr = nullptr;

StatusMonitor::StatusMonitor(SystemType st, std::string name) : IComponent(st, name)
{ 
    SetState(STATE_UNINIT);
    std::cout<<"StatusMonitor created\n";
}

StatusMonitor::~StatusMonitor()
{
    delete m_statusMonitorPtr;
}

int StatusMonitor::Init()
{
    if(STATE_INIT != GetState())
    {
        ThreadManager::RegComp(this);
        SetState(STATE_INIT);
    }
    return 0;
}

int StatusMonitor::DeInit()
{
    delete m_statusMonitorPtr;
    SetState(STATE_UNINIT);
    return 0;
}

int StatusMonitor::Run()
{
    return 0;
}

int StatusMonitor::Stop()
{
    SetState(STATE_STOP);
    return 0;
}

/*static*/ StatusMonitor& StatusMonitor::GetInstance(void)
{
    PreInit();
    return *m_statusMonitorPtr;
}

/*static*/ int StatusMonitor::PreInit()
{
    if(nullptr == m_statusMonitorPtr)
    {
        m_statusMonitorPtr = new StatusMonitor(IComponent::ST_DIAGNOSTIC, "StatusMonitor");
    }
    return 0;
}