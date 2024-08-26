#include <iostream>
#include <vector>
#include "pwtr_drv.hpp"
#include "../ui/ui_logging.hpp"
#include "../../mcal/calib.hpp"

using namespace pwtr_drv;

static struct {
    uint8_t motor_pwm;
} pwtr_drv_mgr;

void pwtr_drv::init(void){
    LOG("SWC [pwtr_drv] init\n");
}

void pwtr_drv::run(void){

}

void pwtr_drv::set_pwm(uint8_t pwm){
    if(PT_DRV_PWM_MIN_VAL > pwm){
        pwtr_drv_mgr.motor_pwm = PT_DRV_PWM_MIN_VAL;
    } else if(PT_DRV_PWM_MAX_VAL < pwm) {
        pwtr_drv_mgr.motor_pwm = PT_DRV_PWM_MAX_VAL;
    } else {
        pwtr_drv_mgr.motor_pwm = pwm;
    }
}

void pwtr_drv::inc_pwm(int8_t pwm){
    if(PT_DRV_PWM_MIN_VAL > (int8_t)(pwtr_drv_mgr.motor_pwm + pwm)){
        pwtr_drv_mgr.motor_pwm = PT_DRV_PWM_MIN_VAL;
    } else if(PT_DRV_PWM_MAX_VAL < (int8_t)(pwtr_drv_mgr.motor_pwm + pwm)) {
        pwtr_drv_mgr.motor_pwm = PT_DRV_PWM_MAX_VAL;
    } else {
        pwtr_drv_mgr.motor_pwm += pwm;
    }
}

uint8_t pwtr_drv::get_pwm(void){
    return pwtr_drv_mgr.motor_pwm;
}

std::vector<std::string> pwtr_drv::export_data(void){
    std::vector<std::string> result;
    /* Result has to be property-value pair */
    result.push_back("Motor PWM");
    result.push_back(std::to_string(pwtr_drv_mgr.motor_pwm));
    return result;
}