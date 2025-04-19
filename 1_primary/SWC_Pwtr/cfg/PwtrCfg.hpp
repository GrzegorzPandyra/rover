#ifndef PWTR_CFG_H
#define PWTR_CFG_H

#include "SwcTypes.hpp"

namespace SWC::Pwtr::Cfg
{
    using namespace GlobalTypes;
    
    constexpr char SWC_NAME[] = "Powertrain";
    constexpr SystemType  SWC_SYSTEM_TYPE = SECONDARY;

    /* Monitor */
    constexpr uint8_t MON_WIN_HEIGHT = 10u;
    constexpr uint8_t MON_WIN_WIDTH  = 40u;
    constexpr uint8_t MON_WIN_Y      = 11u;
    constexpr uint8_t MON_WIN_X      = 100u;

    /* Functional */
    constexpr uint8_t DC_MOTOR_A        = 6u;
    constexpr uint8_t DC_MOTOR_B        = 13u;
    constexpr uint8_t DC_MOTOR_PWM_PIN  = 19u;
    constexpr uint8_t PWM_INC_STEP      = 5u;
    constexpr uint8_t PWM_DEF_VAL       = 0u;
    constexpr uint8_t PWM_MIN_VAL       = 0u;
    constexpr uint8_t PWM_MAX_VAL       = 100u;

    constexpr uint8_t GEAR_R_PWM_MAX  = 30u;
    constexpr uint8_t GEAR_R_PWM_MIN  = 1u;
    constexpr uint8_t GEAR_N_PWM      = 0u;
    constexpr uint8_t GEAR_D1_PWM_MIN = 1u;
    constexpr uint8_t GEAR_D1_PWM_MAX = 30u;
    constexpr uint8_t GEAR_D2_PWM_MIN = 31u;
    constexpr uint8_t GEAR_D2_PWM_MAX = 70u;
    constexpr uint8_t GEAR_D3_PWM_MIN = 71u;
    constexpr uint8_t GEAR_D3_PWM_MAX = 100u;

    constexpr uint8_t  TASK_PERIOD_MS = 10u;
}

#endif
