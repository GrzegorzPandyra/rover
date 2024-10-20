#include <iostream>
#include <vector>
#include "light_ctrlr.hpp"
#include "../ui/ui_logging.hpp"
#include "../../mcal/calib.hpp"

using namespace light_ctrlr;

static struct {
    PWM_Channel headlight_pwm = PWM_Channel(
        LIGHT_CTRLR_HEAD_LIGHT_PWM,
        LIGHT_CTRLR_PWM_MIN_VAL,
        LIGHT_CTRLR_PWM_MAX_VAL,
        LIGHT_CTRLR_PWM_DEF_VAL,
        LIGHT_CTRLR_PWM_STEP
    );
    PWM_Channel rooflight_pwm = PWM_Channel(
        LIGHT_CTRLR_ROOF_LIGHT_PWM,
        LIGHT_CTRLR_PWM_MIN_VAL,
        LIGHT_CTRLR_PWM_MAX_VAL,
        LIGHT_CTRLR_PWM_DEF_VAL,
        LIGHT_CTRLR_PWM_STEP
    );
    PWM_Channel rearlight_pwm = PWM_Channel(
        LIGHT_CTRLR_REAR_LIGHT_PWM,
        LIGHT_CTRLR_PWM_MIN_VAL,
        LIGHT_CTRLR_PWM_MAX_VAL,
        LIGHT_CTRLR_PWM_DEF_VAL,
        LIGHT_CTRLR_PWM_STEP
    );
} mgr;

void light_ctrlr::init(void){
    mgr.headlight_pwm.Init();
    mgr.rooflight_pwm.Init();
    mgr.rearlight_pwm.Init();
    LOG("SWC [light_ctrlr] init\n");
}

void light_ctrlr::run(void){
    mgr.headlight_pwm.Run();
    mgr.rooflight_pwm.Run();
    mgr.rearlight_pwm.Run();
}

PWM_Channel& light_ctrlr::headlight_pwm(void){
    return mgr.headlight_pwm;
}
PWM_Channel& light_ctrlr::rooflight_pwm(void){
    return mgr.rooflight_pwm;
}
PWM_Channel& light_ctrlr::rearlight_pwm(void){
    return mgr.rearlight_pwm;
}

std::vector<std::string> light_ctrlr::export_data(void){
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