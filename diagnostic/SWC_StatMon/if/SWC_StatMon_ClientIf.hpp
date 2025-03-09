#ifndef SWC_STATMON_CLIENTIF_H
#define SWC_STATMON_CLIENTIF_H
#include <sstream>
#include "SWC_Types.hpp"

namespace SWC_StatMon::ClientIf
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

    SWC_Types::Status RegisterMonitor(MonitorProperties prop);
}

#endif