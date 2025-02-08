#ifndef STATUS_MON_H
#define STATUS_MON_H

#include <deque>
#include "IComponent.hpp"

class StatusMonitor : public IComponent {
    public:
        StatusMonitor(SystemType st, std::string name);
        ~StatusMonitor();
        int Init();
        int DeInit();
        int Run();
        int Stop();

    private:
};

#endif