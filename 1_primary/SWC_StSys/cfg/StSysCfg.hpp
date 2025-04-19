#ifndef STEERING_SYSTEM_CFG_H
#define STEERING_SYSTEM_CFG_H
#include "SwcTypes.hpp"

namespace SWC::StSys::Cfg
{
    using namespace GlobalTypes;
    
    constexpr char SWC_NAME[] = "Steering System";
    constexpr SystemType  SWC_SYSTEM_TYPE = PRIMARY;

     /* Steering System Driver */
     const uint8_t LEFT_WHEEL_PWM_PIN  = 27u;
     const uint8_t RIGHT_WHEEL_PWM_PIN = 22u;
     const uint8_t PWM_MIN_VAL         = 5;
     const uint8_t PWM_MAX_VAL         = 11u;
     const uint8_t PWM_INC_STEP        = 1u;
     const uint8_t PWM_DEF_VAL         = (PWM_MAX_VAL - PWM_MIN_VAL)/2u + PWM_MIN_VAL;
     const uint8_t NEUTRAL_WHEEL_PWM   = 8;

     
    /* Monitor data */
    const uint8_t MON_WIN_HEIGHT =  10u;
    const uint8_t MON_WIN_WIDTH  =  40u;
    const uint8_t MON_WIN_Y      = 22u;
    const uint8_t MON_WIN_X      = 100u;
}

#endif
