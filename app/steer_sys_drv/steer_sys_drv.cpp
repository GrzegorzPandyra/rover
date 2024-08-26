#include <iostream>
#include <vector>
#include "steer_sys_drv.hpp"
#include "../ui/ui_logging.hpp"
#include "../../mcal/calib.hpp"

using namespace steer_sys_drv;

static struct {
    uint8_t left_servo_pwm;
    uint8_t right_servo_pwm;
} steer_sys_drv_mgr;

void steer_sys_drv::init(void){
    steer_sys_drv_mgr.left_servo_pwm = SS_DRV_PWM_DEF_VAL;
    steer_sys_drv_mgr.right_servo_pwm = SS_DRV_PWM_DEF_VAL;

    LOG("SWC [steer_sys_drv] init\n");
}

void steer_sys_drv::run(void){

}

void steer_sys_drv::set_pwm(uint8_t pwm){
    /* TODO: PWM scaling*/
    if(SS_DRV_MIN_PWM_VAL > pwm){
        steer_sys_drv_mgr.left_servo_pwm = SS_DRV_MIN_PWM_VAL;
        steer_sys_drv_mgr.right_servo_pwm = SS_DRV_MIN_PWM_VAL;
    } else if(SS_DRV_MAX_PWM_VAL < pwm) {
        steer_sys_drv_mgr.left_servo_pwm = SS_DRV_MAX_PWM_VAL;
        steer_sys_drv_mgr.right_servo_pwm = SS_DRV_MAX_PWM_VAL;
    } else {
        steer_sys_drv_mgr.left_servo_pwm = pwm;
        steer_sys_drv_mgr.right_servo_pwm = pwm;
    }
}

void steer_sys_drv::inc_pwm(int8_t pwm){
    /* TODO: PWM scaling*/
    if(SS_DRV_MIN_PWM_VAL > (int16_t)(steer_sys_drv_mgr.left_servo_pwm + pwm)){
        steer_sys_drv_mgr.left_servo_pwm = SS_DRV_MIN_PWM_VAL;
        steer_sys_drv_mgr.right_servo_pwm = SS_DRV_MIN_PWM_VAL;
    } else if(SS_DRV_MAX_PWM_VAL < (int16_t)(steer_sys_drv_mgr.left_servo_pwm + pwm)) {
        steer_sys_drv_mgr.left_servo_pwm = SS_DRV_MAX_PWM_VAL;
        steer_sys_drv_mgr.right_servo_pwm = SS_DRV_MAX_PWM_VAL;
    } else {
        steer_sys_drv_mgr.left_servo_pwm += pwm;
        steer_sys_drv_mgr.right_servo_pwm += pwm;
    }
}

Servo_Pwm_T steer_sys_drv::get_pwm(void){
    return (Servo_Pwm_T){steer_sys_drv_mgr.left_servo_pwm, steer_sys_drv_mgr.right_servo_pwm};
}

std::vector<std::string> steer_sys_drv::export_data(void){
    std::vector<std::string> result;
    /* Result has to be property-value pair */
    result.push_back("Left servo PWM");
    result.push_back(std::to_string(steer_sys_drv_mgr.left_servo_pwm));
    result.push_back("Right servo PWM");
    result.push_back(std::to_string(steer_sys_drv_mgr.left_servo_pwm));
    return result;
}