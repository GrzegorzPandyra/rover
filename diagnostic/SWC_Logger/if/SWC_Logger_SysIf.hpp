#ifndef SWC_LOGGER_SYSIF_H
#define SWC_LOGGER_SYSIF_H
#include "SWC_Types.hpp"

namespace SWC_Logger::SysIf
{
    SWC_Types::Status Init();
    SWC_Types::Status Stop();
}

#endif