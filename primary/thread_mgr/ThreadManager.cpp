#include "ThreadManager.hpp"
#include <iostream>

ThreadManager* ThreadManager::m_threadManagerPtr = nullptr;

ThreadManager::ThreadManager(SystemType st, std::string name) : IComponent(st, name)
{ 
    SetState(STATE_UNINIT);
    std::cout<<"Thread Manager created\n";
}

ThreadManager::~ThreadManager()
{
    delete m_threadManagerPtr;
}

int ThreadManager::Init()
{
    SetState(STATE_INIT);
    return 0;
}

int ThreadManager::DeInit()
{
    SetState(STATE_UNINIT);
    delete m_threadManagerPtr;
    return 0;
}

int ThreadManager::Run()
{
    return 0;
}

int ThreadManager::Stop()
{
    SetState(STATE_STOP);
    return 0;
}

/*static*/ void ThreadManager::RegComp(IComponent* comp)
{
    m_threadManagerPtr->m_compVect.push_back(comp);
    std::cout<<"Thread Manager RegComp()\n";
}

/*static*/ ThreadManager& ThreadManager::GetInstance(void)
{
    PreInit();
    return *m_threadManagerPtr;
}

/*static*/ int ThreadManager::PreInit()
{
    if(nullptr == m_threadManagerPtr)
    {
        m_threadManagerPtr = new ThreadManager(IComponent::ST_PRIMARY, "ThreadManager");
    }
    return 0;
}