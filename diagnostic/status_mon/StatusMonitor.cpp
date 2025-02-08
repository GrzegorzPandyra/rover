#include <iostream>
#include "StatusMonitor.hpp"
#include "ThreadManager.hpp"


StatusMonitor::StatusMonitor(SystemType st, std::string name) : IComponent(st, name)
{ 
    SetState(STATE_UNINIT);
    std::cout<<"StatusMonitor created\n";
}

StatusMonitor::~StatusMonitor()
{
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