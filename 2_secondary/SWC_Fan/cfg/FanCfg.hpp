#ifndef FAN_CFG_H
#define FAN_CFG_H
#include "SwcTypes.hpp"

namespace SWC::Fan::Cfg
{
    using namespace GlobalTypes;
    
    constexpr char SWC_NAME[] = "Fan";
    constexpr SystemType  SWC_SYSTEM_TYPE = SECONDARY;

    /* Fan controller */
    const uint8_t FAN_PWM_PIN   = 26u; /* Common pin for 2 physical fans */
    const uint8_t PWM_MAX       = 100u;
    const uint8_t PWM_MIN       = 50u;
    const uint8_t PWM_INC_STEP  = 10u;
    const uint8_t PWM_DEF_VAL   = PWM_MIN;
}

#endif
