#include <iostream>
#include <vector>
#include "steer_sys.hpp"
#include "ui_logging.hpp"
#include "cfg/calib.hpp"

using namespace steer_sys;

static struct {
    PWM_Channel left_servo_pwm = PWM_Channel(
        SS_DRV_LEFT_WHEEL_PWM,
        SS_DRV_MIN_PWM_VAL,
        SS_DRV_MAX_PWM_VAL,
        SS_DRV_PWM_DEF_VAL,
        SS_DRV_PWM_INC_STEP
    );
    PWM_Channel right_servo_pwm = PWM_Channel(
        SS_DRV_RIGHT_WHEEL_PWM,
        SS_DRV_MIN_PWM_VAL,
        SS_DRV_MAX_PWM_VAL,
        SS_DRV_PWM_DEF_VAL,
        SS_DRV_PWM_INC_STEP
    );
} mgr;

/**************************************************************************
 *** Interface functions
 *************************************************************************/

void steer_sys::init(void){
    mgr.left_servo_pwm.Init();
    mgr.right_servo_pwm.Init();
    LOG("SWC [steer_sys] init\n");
}

void steer_sys::run(void){
    mgr.left_servo_pwm.Run();
    mgr.right_servo_pwm.Run();
}

PWM_Channel& steer_sys::left_servo_pwm(void){
    return mgr.left_servo_pwm;
}

PWM_Channel& steer_sys::right_servo_pwm(void){
    return mgr.right_servo_pwm;
}

std::vector<std::string> steer_sys::export_data(void){
    std::vector<std::string> result;
    /* Result has to be property-value pair */
    result.push_back("Left servo PWM");
    result.push_back(std::to_string(mgr.left_servo_pwm.Get()));
    result.push_back("Right servo PWM");
    result.push_back(std::to_string(mgr.right_servo_pwm.Get()));
    return result;
}