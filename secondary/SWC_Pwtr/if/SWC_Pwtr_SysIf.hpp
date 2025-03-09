#ifndef SWC_PWTR_SYSIF_H
#define SWC_PWTR_SYSIF_H
#include "SWC_Types.hpp"

namespace SWC_Pwtr::SysIf
{
    SWC_Types::Status Init();
    SWC_Types::Status Stop();
}

#endif