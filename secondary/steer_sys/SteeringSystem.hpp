#ifndef STEER_SYS_H
#define STEER_SYS_H

#include "IComponent.hpp"
#include "IMonitor.hpp"

class SteeringSystem : public IComponent, public IMonitor {
    public:
        SteeringSystem(SystemType st, std::string name);
        ~SteeringSystem();
        int Init();
        int DeInit();
        int Run();
        int Stop();
        virtual std::vector<std::string> GetMonitorData(void);

    private:
};

#endif