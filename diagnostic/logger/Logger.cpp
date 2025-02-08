#include "Logger.hpp"
#include <iostream>

Logger* Logger::m_loggerPtr = nullptr;

Logger::Logger(SystemType st, std::string name) : IComponent(st, name)
{ 
    SetState(STATE_UNINIT);
    std::cout<<"Logger created\n";
}

Logger::~Logger()
{
    delete m_loggerPtr;
}

int Logger::Init()
{
    SetState(STATE_INIT);
    return 0;
}

int Logger::DeInit()
{
    SetState(STATE_UNINIT);
    delete m_loggerPtr;
    return 0;
}

int Logger::Run()
{
    if(!m_dataBuffer.empty())
    {
        Message msg = m_dataBuffer.front();
        m_dataBuffer.pop_front();
        std::cout<<msg.origin<<" : "<<msg.content<<"\n";
    }
    return 0;
}

int Logger::Stop()
{
    SetState(STATE_STOP);
    return 0;
}

/*static*/ Logger& Logger::GetInstance(void)
{
    PreInit();
    return *m_loggerPtr;
}

/*static*/ void Logger::Log(Message msg)
{
    m_loggerPtr->m_dataBuffer.push_back(msg);
}

/*static*/ void Logger::Log(std::string origin, std::string content)
{
    Message msg = {origin, content};
    m_loggerPtr->m_dataBuffer.push_back(msg);
}

/*static*/ void Logger::Log(std::string content)
{
    Message msg = {"", content};
    m_loggerPtr->m_dataBuffer.push_back(msg);
}


/*static*/ int Logger::PreInit()
{
    if(nullptr == m_loggerPtr)
    {
        m_loggerPtr = new Logger(IComponent::ST_DIAGNOSTIC, "Logger");
    }
    return 0;
}