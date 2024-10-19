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
const uint8_t PT_DRV_DC_MOTOR_A = 6u;
const uint8_t PT_DRV_DC_MOTOR_B = 13u;
const uint8_t PT_DRV_DC_MOTOR_PWM = 19u;
const uint8_t PT_DRV_PWM_INC_STEP = 5u;
const uint8_t PT_DRV_PWM_DEF_VAL = 0u;
const uint8_t PT_DRV_PWM_MIN_VAL = 0u;
const uint8_t PT_DRV_PWM_MAX_VAL = 100u;

const uint8_t PT_DRV_GEAR_R3_PWM_MAX = 100u;
const uint8_t PT_DRV_GEAR_R3_PWM_MIN = 71u;
const uint8_t PT_DRV_GEAR_R2_PWM_MAX = 70u;
const uint8_t PT_DRV_GEAR_R2_PWM_MIN = 31u;
const uint8_t PT_DRV_GEAR_R1_PWM_MAX = 30u;
const uint8_t PT_DRV_GEAR_R1_PWM_MIN = 1u;
const uint8_t PT_DRV_GEAR_N_PWM      = 0u;
const uint8_t PT_DRV_GEAR_D1_PWM_MIN = 1u;
const uint8_t PT_DRV_GEAR_D1_PWM_MAX = 30u;
const uint8_t PT_DRV_GEAR_D2_PWM_MIN = 31u;
const uint8_t PT_DRV_GEAR_D2_PWM_MAX = 70u;
const uint8_t PT_DRV_GEAR_D3_PWM_MIN = 71u;
const uint8_t PT_DRV_GEAR_D3_PWM_MAX = 100u;

const uint8_t PT_DRV_FAN_PWM = 26u;

/* Light Driver*/
const uint8_t LIGHT_CTRLR_ROOF_LIGHT_PWM = 16u;
const uint8_t LIGHT_CTRLR_HEAD_LIGHT_PWM = 12u;
const uint8_t LIGHT_CTRLR_PWM_STEP = 10u;
const uint8_t LIGHT_CTRLR_PWM_DEF_VAL = 0u;
const uint8_t LIGHT_CTRLR_PWM_MIN_VAL = 0u;
const uint8_t LIGHT_CTRLR_PWM_MAX_VAL = 100u;

/* RPI System */
const char SYSTEM_TERMINATE_CHAR = '.';

/* User interface key binding */
const char UI_KEY_HEADLIGHT_PWM_INC = '+';
const char UI_KEY_HEADLIGHT_PWM_DEC = '-';
const char UI_KEY_ROOFLIGHT_PWM_INC = '*';
const char UI_KEY_ROOFLIGHT_PWM_DEC = '/';
const char UI_KEY_REARLIGHT_PWM_INC = ',';
const char UI_KEY_REARLIGHT_PWM_DEC = '0';

const char UI_KEY_FAN_PWM_INC = ']';
const char UI_KEY_FAN_PWM_DEC = '[';

const char UI_KEY_SHIFT_UP   = 'r';
const char UI_KEY_SHIFT_DOWN = 'f';

const char UI_KEY_FORWARD    = 'w'; /* KEY_UP */
const char UI_KEY_BACKWARD   = 's'; /* KEY_DOWN */
const char UI_KEY_TURN_RIGHT = 'd'; /* KEY_LEFT */
const char UI_KEY_TURN_LEFT  = 'a'; /* KEY_RIGHT */

/* Buzzer */
const char BUZZ_PIN = 14u;
const char BUZZ_TASK_PERIOD_MS = 100u;

/* Tachometer */
const char TACHO_PIN = 15u;
const char TACHO_TASK_PERIOD_MS = 1u;
const char TACHO_NUM_BOARD_SLOTS = 40u;

/* User interface layout */
const uint8_t LIGHTS_WIN_HEIGHT = 10u;
const uint8_t LIGHTS_WIN_WIDTH = 40u;
const uint8_t LIGHTS_WIN_Y = 1u;
const uint8_t LIGHTS_WIN_X = 100u;

const uint8_t POWERTRAIN_WIN_HEIGHT = 10u; 
const uint8_t POWERTRAIN_WIN_WIDTH =  40u;
const uint8_t POWERTRAIN_WIN_Y = 11u;
const uint8_t POWERTRAIN_WIN_X = 100u;

const uint8_t STEERING_SYSTEM_WIN_HEIGHT =  10u;
const uint8_t STEERING_SYSTEM_WIN_WIDTH =  40u;
const uint8_t STEERING_SYSTEM_WIN_Y = 22u;
const uint8_t STEERING_SYSTEM_WIN_X =  100u;

const uint8_t LIGHT_CONTROLLER_WIN_HEIGHT =  10u;
const uint8_t LIGHT_CONTROLLER_WIN_WIDTH =  40u;
const uint8_t LIGHT_CONTROLLER_WIN_Y = 33u;
const uint8_t LIGHT_CONTROLLER_WIN_X =  100u;

const uint8_t VEHICLE_WIN_HEIGHT =  10u;
const uint8_t VEHICLE_WIN_WIDTH =  40u;
const uint8_t VEHICLE_WIN_Y = 1u;
const uint8_t VEHICLE_WIN_X =  100u;

const uint8_t FAN_WIN_HEIGHT =  10u;
const uint8_t FAN_WIN_WIDTH =  40u;
const uint8_t FAN_WIN_Y = 11u;
const uint8_t FAN_WIN_X =  142u;

const uint8_t POWER_WIN_HEIGHT =  10u;
const uint8_t POWER_WIN_WIDTH =  40u;
const uint8_t POWER_WIN_Y = 1u;
const uint8_t POWER_WIN_X =  142u;

const uint8_t DIAGNOSTIC_WIN_HEIGHT =  21u;
const uint8_t DIAGNOSTIC_WIN_WIDTH =  40u;
const uint8_t DIAGNOSTIC_WIN_Y = 22u;
const uint8_t DIAGNOSTIC_WIN_X =  142u;

#endif /* CALIB_H */