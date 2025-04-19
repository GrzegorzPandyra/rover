#ifndef SWC_LOGGER_SYSIF_H
#define SWC_LOGGER_SYSIF_H
#include "SwcTypes.hpp"
#include "GlobalTypes.hpp"

namespace SWC::Logger::SysIf
{
    GlobalTypes::CallResult Init(void);
    GlobalTypes::CallResult Stop(void);
}

#endif