#include "SteeringSystem.hpp"
#include "ThreadManager.hpp"
#include "SteeringSystem.hpp"
#include "Logger.hpp"
#include "calib.hpp"


SteeringSystem::SteeringSystem(SystemType st, std::string name) : 
IComponent(st, name), 
IMonitor(
    IMonitor::MonitorDimensions
    {
        cfg::STEERING_SYSTEM_WIN_HEIGHT,
        cfg::STEERING_SYSTEM_WIN_WIDTH,
        cfg::STEERING_SYSTEM_WIN_Y,
        cfg::STEERING_SYSTEM_WIN_X
    }
)
{ 
    SetState(STATE_UNINIT);
    Logger::Log(name, "Component created");
}

SteeringSystem::~SteeringSystem()
{
}

int SteeringSystem::Init()
{
    if(STATE_INIT != GetState())
    {
        ThreadManager::RegisterComponent(this);
        SetState(STATE_INIT);
    }
    return 0;
}

int SteeringSystem::DeInit()
{
    SetState(STATE_UNINIT);
    return 0;
}

int SteeringSystem::Run()
{
    if(STATE_INIT == GetState())
    {

    }
    return 0;
}

int SteeringSystem::Stop()
{
    SetState(STATE_STOP);
    return 0;
}

std::vector<std::string> SteeringSystem::GetMonitorData(void){
    std::vector<std::string> result;
    /* Result has to be property-value pair */
    result.push_back("Left servo PWM");
    result.push_back("N/A");
    result.push_back("Right servo PWM");
    result.push_back("N/A");
    return result;
}