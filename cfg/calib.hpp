#ifndef CALIB_H
#define CALIB_H

#include <iostream>
#include <cstdint>

/* Steering System Driver */
const uint8_t SS_DRV_LEFT_WHEEL_PWM = 27u;
const uint8_t SS_DRV_RIGHT_WHEEL_PWM = 22u;
const uint8_t SS_DRV_MIN_PWM_VAL = 4;
const uint8_t SS_DRV_MAX_PWM_VAL = 12u;
const uint8_t SS_DRV_PWM_INC_STEP = 1u;
const uint8_t SS_DRV_PWM_DEF_VAL = (SS_DRV_MAX_PWM_VAL - SS_DRV_MIN_PWM_VAL)/2u + SS_DRV_MIN_PWM_VAL;
const uint8_t SS_NEUTRAL_WHEEL_PWM = 8;

/* Powertrain Driver */
const uint8_t PT_DRV_DC_MOTOR_A = 6u;
const uint8_t PT_DRV_DC_MOTOR_B = 13u;
const uint8_t PT_DRV_DC_MOTOR_PWM = 19u;
const uint8_t PT_DRV_PWM_INC_STEP = 5u;
const uint8_t PT_DRV_PWM_DEF_VAL = 0u;
const uint8_t PT_DRV_PWM_MIN_VAL = 0u;
const uint8_t PT_DRV_PWM_MAX_VAL = 100u;

const uint8_t PT_DRV_GEAR_R_PWM_MAX = 30u;
const uint8_t PT_DRV_GEAR_R_PWM_MIN = 1u;
const uint8_t PT_DRV_GEAR_N_PWM      = 0u;
const uint8_t PT_DRV_GEAR_D1_PWM_MIN = 1u;
const uint8_t PT_DRV_GEAR_D1_PWM_MAX = 30u;
const uint8_t PT_DRV_GEAR_D2_PWM_MIN = 31u;
const uint8_t PT_DRV_GEAR_D2_PWM_MAX = 70u;
const uint8_t PT_DRV_GEAR_D3_PWM_MIN = 71u;
const uint8_t PT_DRV_GEAR_D3_PWM_MAX = 100u;

const uint8_t  PT_TASK_PERIOD_MS = 10u;
const uint16_t PT_HARDSTART_PERIOD_MS = 500u;
const uint16_t PT_HARDSTART_PWM = 80u;
const float    PT_HARDSTART_RPS_THRESHOLD = 0.2f;

/* Fan controller */
const uint8_t FAN_CTRL_FAN_PWM = 26u; /* Common pin for 2 physical fans */
const uint8_t FAN_CTRL_PWM_MAX = 100u;
const uint8_t FAN_CTRL_PWM_MIN = 70u;
const uint8_t FAN_CTRL_PWM_INC_STEP = 5u;
const uint8_t FAN_CTRL_PWM_DEF_VAL = FAN_CTRL_PWM_MIN;


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
const char UI_KEY_STOP       = 'q';
const char UI_KEY_PWM_AUTO_DEC = 't';
const char UI_KEY_HARDSTART = 'g';

/* Buzzer */
const char BUZZ_PIN = 14u;
const char BUZZ_TASK_PERIOD_MS = 100u;

/* Tachometer */
const uint8_t TACHO_PIN = 15u;
const uint8_t TACHO_TASK_PERIOD_MS = 1u;
const uint8_t TACHO_NUM_BOARD_SLOTS = 40u;

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

const uint8_t POWER_WIN_HEIGHT =  10u;
const uint8_t POWER_WIN_WIDTH =  40u;
const uint8_t POWER_WIN_Y = 1u;
const uint8_t POWER_WIN_X =  142u;

const uint8_t INPUT_WIN_HEIGHT =  10u;
const uint8_t INPUT_WIN_WIDTH =  40u;
const uint8_t INPUT_WIN_Y = 11u;
const uint8_t INPUT_WIN_X =  142u;

const uint8_t DIAGNOSTIC_WIN_HEIGHT =  21u;
const uint8_t DIAGNOSTIC_WIN_WIDTH =  40u;
const uint8_t DIAGNOSTIC_WIN_Y = 22u;
const uint8_t DIAGNOSTIC_WIN_X =  142u;

/* Logging */

/* Joystick */
const uint8_t JS_BTN_X = 3;
const uint8_t JS_BTN_Y = 4;
const uint8_t JS_BTN_A = 0;
const uint8_t JS_BTN_B = 1;
const uint8_t JS_BTN_R1 = 7;
const uint8_t JS_BTN_R2 = 9;
const uint8_t JS_BTN_L1 = 6;
const uint8_t JS_BTN_L2 = 8;
const uint8_t JS_BTN_LSTICK = 13;
const uint8_t JS_BTN_RSTICK = 14;
const uint8_t JS_BTN_SELECT = 10;
const uint8_t JS_BTN_START = 11;
const uint8_t JS_AXIS_LSTICK_H = 0;
const uint8_t JS_AXIS_LSTICK_V = 1;
const uint8_t JS_AXIS_RSTICK_H = 2;
const uint8_t JS_AXIS_RSTICK_V = 3;
const uint8_t JS_AXIS_DPAD_H = 6;
const uint8_t JS_AXIS_DPAD_V = 7;
const int16_t JS_AXIS_MIN = -32767;
const int16_t JS_AXIS_MAX = 32767;
const char    JS_DEV_PATH[] = "/dev/input/js0";

#endif /* CALIB_H */