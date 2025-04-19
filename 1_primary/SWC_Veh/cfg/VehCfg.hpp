#ifndef VEH_CFG_H
#define VEH_CFG_H

#include <chrono>
#include "SwcTypes.hpp"

namespace SWC::Veh::Cfg
{
    using namespace GlobalTypes;
    constexpr uint8_t MON_WIN_HEIGHT = 10u;
    constexpr uint8_t MON_WIN_WIDTH  = 40u;
    constexpr uint8_t MON_WIN_Y      = 1u;
    constexpr uint8_t MON_WIN_X      = 100u;
    constexpr char    SWC_NAME[]     = "Vehicle";
    constexpr SystemType SWC_SYSTEM_TYPE = SECONDARY;

    const uint8_t GEAR_R_PWM_MAX = 30u;
    const uint8_t GEAR_R_PWM_MIN = 1u;
    const uint8_t GEAR_N_PWM      = 0u;
    const uint8_t GEAR_D1_PWM_MIN = 1u;
    const uint8_t GEAR_D1_PWM_MAX = 30u;
    const uint8_t GEAR_D2_PWM_MIN = 31u;
    const uint8_t GEAR_D2_PWM_MAX = 70u;
    const uint8_t GEAR_D3_PWM_MIN = 71u;
    const uint8_t GEAR_D3_PWM_MAX = 100u;

    const std::chrono::milliseconds AUTO_DECELERATE_PERIOD_MS(1000);
}
#endif
