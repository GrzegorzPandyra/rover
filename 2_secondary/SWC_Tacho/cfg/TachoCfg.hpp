#ifndef TACHO_CFG_H
#define TACHO_CFG_H
#include <chrono>
#include "SwcTypes.hpp"

namespace SWC::Tacho::Cfg
{
    using namespace GlobalTypes;
    
    constexpr char SWC_NAME[] = "Tacho";
    constexpr SystemType  SWC_SYSTEM_TYPE = SECONDARY;
     
    /* Tachometer */
     constexpr uint8_t TACHO_PIN = 15u;
     constexpr std::chrono::milliseconds TRIGGER_PERIOD(10);
     constexpr std::chrono::milliseconds CALCULATION_PERIOD(1000);
     constexpr uint8_t NUM_BOARD_SLOTS = 40u;
}

#endif
