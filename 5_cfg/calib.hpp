#ifndef CALIB_H
#define CALIB_H

#include <iostream>
#include <cstdint>


    

    const uint8_t  PT_TASK_PERIOD_MS = 10u;
    const uint16_t PT_HARDSTART_PERIOD_MS = 500u;
    const uint16_t PT_HARDSTART_PWM = 80u;
    const float    PT_HARDSTART_RPS_THRESHOLD = 0.2f;




   

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