#ifndef IMONITOR_H
#define IMONITOR_H

#include <vector>
#include <string>

class IMonitor
{
    public:
        struct MonitorDimensions
        {
            int x;
            int y;
            int width;
            int height;
        };
        IMonitor(MonitorDimensions mDims) : m_monDims(mDims){};
        virtual ~IMonitor(){};
        virtual std::vector<std::string> GetMonitorData(void) = 0;
        MonitorDimensions GetMonitorDims(void){return m_monDims;};
    private:
        const MonitorDimensions m_monDims;
        IMonitor() = delete;
};

#endif