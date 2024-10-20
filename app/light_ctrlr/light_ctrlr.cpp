#include <iostream>
#include <vector>
#include "light_ctrlr.hpp"
#include "../ui/ui_logging.hpp"
#include "../../mcal/calib.hpp"
#include <wiringPi.h>
#include <softPwm.h>

using namespace light_ctrlr;

static struct {
    uint8_t headlights_pwm;
    uint8_t rooflights_pwm;
    uint8_t rearlights_pwm;
} mgr;

void light_ctrlr::init(void){
    LOG("SWC [light_ctrlr] init\n");
    pinMode(LIGHT_CTRLR_ROOF_LIGHT_PWM, PWM_OUTPUT);
    pinMode(LIGHT_CTRLR_HEAD_LIGHT_PWM, PWM_OUTPUT);

    digitalWrite(LIGHT_CTRLR_ROOF_LIGHT_PWM, LOW);
    digitalWrite(LIGHT_CTRLR_HEAD_LIGHT_PWM, LOW);

    softPwmCreate(LIGHT_CTRLR_ROOF_LIGHT_PWM, LIGHT_CTRLR_PWM_MIN_VAL, LIGHT_CTRLR_PWM_MAX_VAL);
    softPwmCreate(LIGHT_CTRLR_HEAD_LIGHT_PWM, LIGHT_CTRLR_PWM_MIN_VAL, LIGHT_CTRLR_PWM_MAX_VAL);
}

void light_ctrlr::run(void){
    softPwmWrite(LIGHT_CTRLR_ROOF_LIGHT_PWM, mgr.rooflights_pwm);
    softPwmWrite(LIGHT_CTRLR_HEAD_LIGHT_PWM, mgr.headlights_pwm);
}

void light_ctrlr::set_pwm(uint8_t pwm, Light_T light){
    uint8_t * pwm_ptr = NULL;
    switch (light){
    case HEADLIGHT :
        pwm_ptr = &mgr.headlights_pwm;
        break;
    case ROOFLIGHT :
        pwm_ptr = &mgr.rooflights_pwm;
        break;
    case REARLIGHT :
        pwm_ptr = &mgr.rearlights_pwm;
        break;
    default:
        /* pwm_ptr == NULL */
        return;
        break;
    };

    if(LIGHT_CTRLR_PWM_MIN_VAL > (*pwm_ptr)){
        (*pwm_ptr) = LIGHT_CTRLR_PWM_MIN_VAL;
    } else if(LIGHT_CTRLR_PWM_MAX_VAL < (*pwm_ptr)) {
        (*pwm_ptr) = LIGHT_CTRLR_PWM_MAX_VAL;
    } else {
        (*pwm_ptr) = pwm;
    }
}

void light_ctrlr::inc_pwm(int8_t pwm, Light_T light){
    uint8_t * pwm_ptr = NULL;
    switch (light){
    case HEADLIGHT :
        pwm_ptr = &mgr.headlights_pwm;
        break;
    case ROOFLIGHT :
        pwm_ptr = &mgr.rooflights_pwm;
        break;
    case REARLIGHT :
        pwm_ptr = &mgr.rearlights_pwm;
        break;
    default:
        /* pwm_ptr == NULL */
        return;
        break;
    };

    if(LIGHT_CTRLR_PWM_MIN_VAL > ((*pwm_ptr)+pwm)){
        (*pwm_ptr) = LIGHT_CTRLR_PWM_MIN_VAL;
    } else if(LIGHT_CTRLR_PWM_MAX_VAL < ((*pwm_ptr)+pwm)) {
        (*pwm_ptr) = LIGHT_CTRLR_PWM_MAX_VAL;
    } else {
        (*pwm_ptr) += pwm;
    }
}

uint8_t light_ctrlr::get_pwm(Light_T light){
    uint8_t result = 0;
    switch (light){
    case HEADLIGHT :
        result = mgr.headlights_pwm;
        break;
    case ROOFLIGHT :
        result = mgr.rooflights_pwm;
        break;
    case REARLIGHT :
        result = mgr.rearlights_pwm;
        break;
    
    default:
        break;
    };
    return result;
}

std::vector<std::string> light_ctrlr::export_data(void){
    std::vector<std::string> result;
    /* Result has to be property-value pair */
    result.push_back("Headlights PWM");
    result.push_back(std::to_string(mgr.headlights_pwm));
    result.push_back("Roadlights PWM");
    result.push_back(std::to_string(mgr.rooflights_pwm));
    result.push_back("Rearlights PWM");
    result.push_back(std::to_string(mgr.rearlights_pwm));
    return result;
}