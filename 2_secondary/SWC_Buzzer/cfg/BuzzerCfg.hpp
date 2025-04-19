#ifndef BUZZER_CFG_H
#define BUZZER_CFG_H
#include <chrono>
#include "SwcTypes.hpp"

namespace SWC::Buzzer::Cfg
{
    using namespace GlobalTypes;
    
    constexpr char SWC_NAME[] = "Buzzer";
    constexpr SystemType  SWC_SYSTEM_TYPE = SECONDARY;

    /* Buzzer */
    const char BUZZ_PIN = 14u;
    const std::chrono::milliseconds BUZZ_TIMEOUT_MS(100);
}

#endif
