#include <iostream>
#include "ui_input.hpp" 
#include "calib.hpp"
#include <ncurses.h>
#include "../ui/ui_logging.hpp"
#include "../app/light_ctrlr/light_ctrlr.hpp"
#include "../app/pwtr_drv/pwtr_drv.hpp"
#include "../app/steer_sys_drv/steer_sys_drv.hpp"

static void process_input(char input);

void ui_input::init(void){
    LOG("SWC [ui_input] init\n");
}

void ui_input::run(void){
    int input = getch();
    if(input != ERR){ /* ncurses: ERR = -1 */
        process_input((char)input);
    }
}

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
        pwtr_drv::inc_pwm(PT_DRV_PWM_INC_STEP);
        break;
    case UI_KEY_BACKWARD:
        pwtr_drv::inc_pwm(-PT_DRV_PWM_INC_STEP);
        break;
    /* STEERING SYSTEM */
    case UI_KEY_TURN_RIGHT:
        steer_sys_drv::inc_pwm(PT_DRV_PWM_INC_STEP);
        break;
    case UI_KEY_TURN_LEFT:
        steer_sys_drv::inc_pwm(-PT_DRV_PWM_INC_STEP);

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