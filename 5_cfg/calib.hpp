#ifndef CALIB_H
#define CALIB_H

#include <iostream>
#include <cstdint>

    /* System */
    constexpr int SYS_THREAD_SLEEP_NS = 500;
    
   

    /* Powertrain Driver */
    const uint8_t PT_DRV_DC_MOTOR_A = 6u;
    const uint8_t PT_DRV_DC_MOTOR_B = 13u;
    const uint8_t PT_DRV_DC_MOTOR_PWM = 19u;
    const uint8_t PT_DRV_PWM_INC_STEP = 5u;
    const uint8_t PT_DRV_PWM_DEF_VAL = 0u;
    const uint8_t PT_DRV_PWM_MIN_VAL = 0u;
    const uint8_t PT_DRV_PWM_MAX_VAL = 100u;

    

    const uint8_t  PT_TASK_PERIOD_MS = 10u;
    const uint16_t PT_HARDSTART_PERIOD_MS = 500u;
    const uint16_t PT_HARDSTART_PWM = 80u;
    const float    PT_HARDSTART_RPS_THRESHOLD = 0.2f;




    /* Light Driver*/
    const uint8_t LIGHT_CTRL_ROOF_LIGHT_PWM = 16u;
    const uint8_t LIGHT_CTRL_HEAD_LIGHT_PWM = 12u;
    const uint8_t LIGHT_CTRL_REAR_LIGHT_PWM = 0u; /*TBD*/
    const uint8_t LIGHT_CTRL_PWM_STEP = 10u;
    const uint8_t LIGHT_CTRL_PWM_DEF_VAL = 0u;
    const uint8_t LIGHT_CTRL_PWM_MIN_VAL = 0u;
    const uint8_t LIGHT_CTRL_PWM_MAX_VAL = 100u;

    /* RPI System */
    const char SYSTEM_TERMINATE_CHAR = '.';





   

    /* Power Monitoring */

    /* User interface layout */
    const uint8_t LIGHTS_WIN_HEIGHT = 10u;
    const uint8_t LIGHTS_WIN_WIDTH = 40u;
    const uint8_t LIGHTS_WIN_Y = 1u;
    const uint8_t LIGHTS_WIN_X = 100u;

    const uint8_t POWERTRAIN_WIN_HEIGHT = 10u; 
    const uint8_t POWERTRAIN_WIN_WIDTH =  40u;
    const uint8_t POWERTRAIN_WIN_Y = 11u;
    const uint8_t POWERTRAIN_WIN_X = 100u;

    const uint8_t LIGHT_CONTROLLER_WIN_HEIGHT =  10u;
    const uint8_t LIGHT_CONTROLLER_WIN_WIDTH =  40u;
    const uint8_t LIGHT_CONTROLLER_WIN_Y = 33u;
    const uint8_t LIGHT_CONTROLLER_WIN_X =  100u;

    const uint8_t VEHICLE_WIN_HEIGHT =  10u;
    const uint8_t VEHICLE_WIN_WIDTH =  40u;
    const uint8_t VEHICLE_WIN_Y = 1u;
    const uint8_t VEHICLE_WIN_X =  100u;

    const uint8_t POWER_WIN_HEIGHT =  10u;
    const uint8_t POWER_WIN_WIDTH =  40u;
    const uint8_t POWER_WIN_Y = 1u;
    const uint8_t POWER_WIN_X =  142u;



    const uint8_t DIAGNOSTIC_WIN_HEIGHT =  21u;
    const uint8_t DIAGNOSTIC_WIN_WIDTH =  40u;
    const uint8_t DIAGNOSTIC_WIN_Y = 22u;
    const uint8_t DIAGNOSTIC_WIN_X =  142u;

    /* Logging */




#endif /* CALIB_H */