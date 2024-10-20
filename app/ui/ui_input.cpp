#include <iostream>
#include "ui_input.hpp" 
#include "calib.hpp"
#include <ncurses.h>
#include "../ui/ui_logging.hpp"
#include "../app/light_ctrlr/light_ctrlr.hpp"
#include "../app/pwtr_drv/pwtr_drv.hpp"
#include "../app/steer_sys_drv/steer_sys_drv.hpp"
#include "../app/veh/veh.hpp"
#include "../app/fan_ctrl/fan_ctrl.hpp"

static void process_input(char input);
static void Handler_UI_KEY_BACKWARD(void);
static void Handler_UI_KEY_FORWARD(void);

/**************************************************************************
 *** Interface functions
 *************************************************************************/

void ui_input::init(void){
    LOG("SWC [ui_input] init\n");
}

void ui_input::run(void){
    int input = getch();
    if(input != ERR){ /* ncurses: ERR = -1 */
        process_input((char)input);
    }
}

/**************************************************************************
 *** Static functions
 *************************************************************************/

static void process_input(char input){
    switch (input){
    /* LIGHT CONTROLLER*/
    case UI_KEY_HEADLIGHT_PWM_INC:
        light_ctrlr::inc_pwm(LIGHT_CTRLR_PWM_STEP, light_ctrlr::HEADLIGHT);
        break;
    case UI_KEY_HEADLIGHT_PWM_DEC:
        light_ctrlr::inc_pwm(-LIGHT_CTRLR_PWM_STEP, light_ctrlr::HEADLIGHT);
        break;
    case UI_KEY_ROOFLIGHT_PWM_INC:
        light_ctrlr::inc_pwm(LIGHT_CTRLR_PWM_STEP, light_ctrlr::ROOFLIGHT);
        break;
    case UI_KEY_ROOFLIGHT_PWM_DEC:
        light_ctrlr::inc_pwm(-LIGHT_CTRLR_PWM_STEP, light_ctrlr::ROOFLIGHT);
        break;
    case UI_KEY_REARLIGHT_PWM_INC:
        light_ctrlr::inc_pwm(LIGHT_CTRLR_PWM_STEP, light_ctrlr::REARLIGHT);
        break;
    case UI_KEY_REARLIGHT_PWM_DEC:
        light_ctrlr::inc_pwm(-LIGHT_CTRLR_PWM_STEP, light_ctrlr::REARLIGHT);
        break;

    /* POWERTRAIN DRIVER */
    case UI_KEY_FORWARD:
        Handler_UI_KEY_FORWARD();
        break;
    case UI_KEY_BACKWARD:
        Handler_UI_KEY_BACKWARD();
        break;
    case UI_KEY_STOP:
        pwtr_drv::pwm().Set(PT_DRV_PWM_DEF_VAL);
        veh::set_gear(veh::PRND_N);
        break;
    case UI_KEY_PWM_AUTO_DEC:
        pwtr_drv::toggle_pwm_dec();
        break;

    /* VEHICLE*/
    case UI_KEY_SHIFT_UP:
        veh::shift_up();
        break;
    case UI_KEY_SHIFT_DOWN:
        veh::shift_down();
        break;

    /* STEERING SYSTEM */
    case UI_KEY_TURN_RIGHT:
        steer_sys_drv::left_servo_pwm().Inc();
        steer_sys_drv::right_servo_pwm().Inc();
        break;
    case UI_KEY_TURN_LEFT:
        steer_sys_drv::left_servo_pwm().Dec();
        steer_sys_drv::right_servo_pwm().Dec();

    /* FAN CTRL */
    case UI_KEY_FAN_PWM_INC:
        fan_ctrl::pwm().Inc();
        break;
    case UI_KEY_FAN_PWM_DEC:
        fan_ctrl::pwm().Dec();

        break;
    default:
        break;
    }

    if(input == SYSTEM_TERMINATE_CHAR) {
        endwin(); /* ncurses */
        std::cout << " Rover control program - shutdown complete\n\r";
        exit(0);
    }
}

/**************************************************************************
 *** Handlers for complex inputs
 *************************************************************************/

static void Handler_UI_KEY_BACKWARD(void){
    switch (veh::get_gear()){
    case veh::PRND_D1:
    case veh::PRND_D2:
    case veh::PRND_D3:
        pwtr_drv::pwm().Dec();
        break;
    case veh::PRND_R:
        pwtr_drv::pwm().Inc();
    default:
        break;
    }
}

static void Handler_UI_KEY_FORWARD(void){
    switch (veh::get_gear()){
    case veh::PRND_D1:
    case veh::PRND_D2:
    case veh::PRND_D3:
        pwtr_drv::pwm().Inc();
        break;
    case veh::PRND_R:
        pwtr_drv::pwm().Dec();
    default:
        break;
    }
}