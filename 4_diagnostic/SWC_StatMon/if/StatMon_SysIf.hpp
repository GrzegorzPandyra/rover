#ifndef SWC_STATMON_SYSIF_H
#define SWC_STATMON_SYSIF_H
#include "SwcTypes.hpp"

namespace SWC::StatMon::SysIf
{
    GlobalTypes::CallResult Init();
    GlobalTypes::CallResult Stop();
}

#endif