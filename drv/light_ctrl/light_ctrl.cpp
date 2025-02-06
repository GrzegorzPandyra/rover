#include <iostream>
#include <vector>
#include "light_ctrl.hpp"
#include "ui_logging.hpp"
#include "cfg/calib.hpp"

using namespace light_ctrl;

static struct {
    PWM_Channel headlight_pwm = PWM_Channel(
        LIGHT_CTRL_HEAD_LIGHT_PWM,
        LIGHT_CTRL_PWM_MIN_VAL,
        LIGHT_CTRL_PWM_MAX_VAL,
        LIGHT_CTRL_PWM_DEF_VAL,
        LIGHT_CTRL_PWM_STEP
    );
    PWM_Channel rooflight_pwm = PWM_Channel(
        LIGHT_CTRL_ROOF_LIGHT_PWM,
        LIGHT_CTRL_PWM_MIN_VAL,
        LIGHT_CTRL_PWM_MAX_VAL,
        LIGHT_CTRL_PWM_DEF_VAL,
        LIGHT_CTRL_PWM_STEP
    );
    PWM_Channel rearlight_pwm = PWM_Channel(
        LIGHT_CTRL_REAR_LIGHT_PWM,
        LIGHT_CTRL_PWM_MIN_VAL,
        LIGHT_CTRL_PWM_MAX_VAL,
        LIGHT_CTRL_PWM_DEF_VAL,
        LIGHT_CTRL_PWM_STEP
    );
} mgr;

void light_ctrl::init(void){
    mgr.headlight_pwm.Init();
    mgr.rooflight_pwm.Init();
    mgr.rearlight_pwm.Init();
    LOG("SWC [light_ctrl] init\n");
}

void light_ctrl::run(void){
    mgr.headlight_pwm.Run();
    mgr.rooflight_pwm.Run();
    mgr.rearlight_pwm.Run();
}

PWM_Channel& light_ctrl::get_headlight_pwm(void){
    return mgr.headlight_pwm;
}
PWM_Channel& light_ctrl::get_rooflight_pwm(void){
    return mgr.rooflight_pwm;
}
PWM_Channel& light_ctrl::get_rearlight_pwm(void){
    return mgr.rearlight_pwm;
}

std::vector<std::string> light_ctrl::export_data(void){
    std::vector<std::string> result;
    /* Result has to be property-value pair */
    result.push_back("Headlights PWM");
    result.push_back(std::to_string(mgr.headlight_pwm.Get()));
    result.push_back("Roadlights PWM");
    result.push_back(std::to_string(mgr.rooflight_pwm.Get()));
    result.push_back("Rearlights PWM");
    result.push_back(std::to_string(mgr.rearlight_pwm.Get()));
    return result;
}