#ifndef STATUS_MON_H
#define STATUS_MON_H

#include <mutex>
#include <vector>
#include "IComponent.hpp"
#include "IMonitor.hpp"

class StatusMonitor : public IComponent {
    public:
        StatusMonitor(const StatusMonitor&) = delete;
        ~StatusMonitor();
        int Init();
        int DeInit();
        int Run();
        int Stop();
        static StatusMonitor& GetInstance(void);
        static void RegisterMonitor(IMonitor* mon);
        static int PreInit();

    private:
        StatusMonitor(SystemType st, std::string name);
        static StatusMonitor* m_statusMonitorPtr;
        std::mutex m_registerMutex;
        std::vector<IMonitor*> m_monitorPtrVector;
        void InitNCurses(void);
};

#endif