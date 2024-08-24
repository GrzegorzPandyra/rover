#ifndef CALIB_H
#define CALIB_H

#include <iostream>

/* Steering System Driver */

const uint8_t SS_DRV_LEFT_WHEEL_PWM_PIN = 13u;
const uint8_t SS_DRV_RIGHT_WHEEL_PWM_PIN = 12u;
const uint8_t SS_DRV_MIN_PWM_VAL = 135u;
const uint8_t SS_DRV_MAX_PWM_VAL = 205u;
const uint8_t SS_DRV_PWM_INC_STEP = 5u;
const uint8_t SS_DRV_PWM_DEF_VAL = (SS_DRV_MAX_PWM_VAL - SS_DRV_MIN_PWM_VAL)/2u + SS_DRV_MIN_PWM_VAL;

/* Powertrain Driver */

const uint8_t PT_DRV_DC_MOTOR_1_A = 27u;
const uint8_t PT_DRV_DC_MOTOR_1_B = 22u;
const uint8_t PT_DRV_DC_MOTOR_1_PWM = 17u;
const uint8_t PT_DRV_DC_MOTOR_2_A = 20u;
const uint8_t PT_DRV_DC_MOTOR_2_B = 16u;
const uint8_t PT_DRV_DC_MOTOR_2_PWM = 21u;
const uint8_t PT_DRV_PWM_INC_STEP = 5u;
const uint8_t PT_DRV_PWM_DEF_VAL = 0u;

/* Headlight Driver*/
const char HL_DRV_PWM_PIN = 26u;

/* RPI System */
const char SYSTEM_TERMINATE_CHAR = '.';

/* User interface key binding */
const char UI_KEY_HEADLIGHT_PWM_INC = '+';
const char UI_KEY_HEADLIGHT_PWM_DEC = '-';
const char UI_KEY_ROOFLIGHT_PWM_INC = '*';
const char UI_KEY_ROOFLIGHT_PWM_DEC = '/';

#endif /* CALIB_H */