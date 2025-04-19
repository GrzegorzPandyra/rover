#ifndef LOGGER_CFG_H
#define LOGGER_CFG_H
#include <string>
#include "SwcTypes.hpp"

namespace SWC::Logger::Cfg
{
    using namespace GlobalTypes;
    
    constexpr char SWC_NAME[] = "Logger";
    constexpr SystemType  SWC_SYSTEM_TYPE = DIAGNOSTIC;
    
    #define LOGGER_CFG_SWC_MAX_LOGS 30
    #define LOGGER_CFG_MESSAGE_MARGIN 25
}

#endif
