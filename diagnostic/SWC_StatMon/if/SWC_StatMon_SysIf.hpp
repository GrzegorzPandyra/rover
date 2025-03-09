#ifndef SWC_STATMON_SYSIF_H
#define SWC_STATMON_SYSIF_H
#include "SWC_Types.hpp"

namespace SWC_StatMon::SysIf
{
    SWC_Types::Status Init();
    SWC_Types::Status Stop();
}

#endif