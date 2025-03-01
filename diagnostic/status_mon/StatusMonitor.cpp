#include <iostream>
#include "StatusMonitor.hpp"
#include "ThreadManager.hpp"
#include "Logger.hpp"
#include <ncurses.h>

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
        ThreadManager::RegisterComponent(this);
        InitNCurses();
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

void StatusMonitor::InitNCurses(void)
{
    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    scrollok(stdscr, TRUE);
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

/*static*/ void StatusMonitor::RegisterMonitor(IMonitor* mon)
{
    m_statusMonitorPtr->m_registerMutex.lock();
    m_statusMonitorPtr->m_monitorPtrVector.push_back(mon);
    m_statusMonitorPtr->m_registerMutex.unlock();
}