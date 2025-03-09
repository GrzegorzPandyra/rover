#ifndef SWC_VEH_SYSIF_H
#define SWC_VEH_SYSIF_H
#include "SWC_Types.hpp"

namespace SWC_Veh::SysIf
{
    SWC_Types::Status Init();
    SWC_Types::Status Stop();
}

#endif