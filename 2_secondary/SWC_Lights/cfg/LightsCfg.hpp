#ifndef LIGHTS_CFG_H
#define LIGHTS_CFG_H
#include "SwcTypes.hpp"

namespace SWC::Lights::Cfg {
    using namespace GlobalTypes;
    
    constexpr char SWC_NAME[] = "Lights";
    constexpr SystemType  SWC_SYSTEM_TYPE = SECONDARY;

    /* Light Driver*/
    constexpr uint8_t ROOF_LIGHT_PWM_PIN = 16u;
    constexpr uint8_t HEAD_LIGHT_PWM_PIN = 12u;
    constexpr uint8_t REAR_LIGHT_PWM_PIN = 0u; /*TBD*/
    constexpr uint8_t PWM_STEP           = 50u;
    constexpr uint8_t PWM_DEF            = 0u;
    constexpr uint8_t PWM_MIN            = 0u;
    constexpr uint8_t PWM_MAX            = 100u;

    /* Monitor */
    constexpr uint8_t MON_WIN_HEIGHT     = 10u;
    constexpr uint8_t MON_WIN_WIDTH      = 24u;
    constexpr uint8_t MON_WIN_Y          = 1u;
    constexpr uint8_t MON_WIN_X          = 140u;
}

#endif
