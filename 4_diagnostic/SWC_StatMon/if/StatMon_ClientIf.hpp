#ifndef SWC_STATMON_CLIENTIF_H
#define SWC_STATMON_CLIENTIF_H
#include <sstream>
#include "SwcTypes.hpp"

namespace SWC::StatMon::ClientIf
{
    typedef std::vector<std::string> (*MonitorCallback)();
    struct MonitorProperties
    {
        int x;
        int y;
        int width;
        int height;
        MonitorCallback cbk;
        std::string name;
    };

    GlobalTypes::CallResult RegisterMonitor(MonitorProperties prop);
}

#endif