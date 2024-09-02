#include <iostream>
#include <vector>
#include <wiringPi.h>
#include <softPwm.h> 
#include "pwtr_drv.hpp"
#include "../ui/ui_logging.hpp"
#include "../../mcal/calib.hpp"
#include "../veh/veh.hpp"

static void update_pwm_range(void);

using namespace pwtr_drv;

static struct {
    uint8_t motor_pwm;
    uint8_t max_allowed_pwm;
    uint8_t min_allowed_pwm;
} pwtr_drv_mgr;

void pwtr_drv::init(void){
    pinMode(PT_DRV_DC_MOTOR_A, OUTPUT);
    pinMode(PT_DRV_DC_MOTOR_B, OUTPUT);
    pinMode(PT_DRV_DC_MOTOR_PWM, PWM_OUTPUT);
    pinMode(PT_DRV_FAN_PWM, PWM_OUTPUT);

    digitalWrite(PT_DRV_DC_MOTOR_A, LOW);
    digitalWrite(PT_DRV_DC_MOTOR_B, LOW);

    softPwmCreate(PT_DRV_DC_MOTOR_PWM, PT_DRV_PWM_MIN_VAL, PT_DRV_PWM_MAX_VAL);
    softPwmCreate(PT_DRV_FAN_PWM, PT_DRV_PWM_MIN_VAL, PT_DRV_PWM_MAX_VAL);
    
    

    LOG("SWC [pwtr_drv] init\n");
}

void pwtr_drv::run(void){
    update_pwm_range();
    softPwmWrite(PT_DRV_DC_MOTOR_PWM, pwtr_drv_mgr.motor_pwm);
    softPwmWrite(PT_DRV_FAN_PWM, PT_DRV_PWM_MAX_VAL);
}

void pwtr_drv::set_pwm(uint8_t pwm){
    /* Check PWM range */
    if(pwtr_drv_mgr.min_allowed_pwm > pwm) {
        pwtr_drv_mgr.motor_pwm = pwtr_drv_mgr.min_allowed_pwm;
    } else if(pwtr_drv_mgr.max_allowed_pwm < pwm) {
        pwtr_drv_mgr.motor_pwm = pwtr_drv_mgr.max_allowed_pwm;
    } else {
        pwtr_drv_mgr.motor_pwm = pwm;
    }
}

void pwtr_drv::inc_pwm(int8_t pwm){
    /* Invert PWM value when moving backward */
    veh::PRND_T gear = veh::get_gear();
    if((gear == veh::R1) || (gear == veh::R2) || (gear == veh::R3)){
        pwm = -pwm;
    }

    /* Check PWM range */
    if(pwtr_drv_mgr.min_allowed_pwm > (int8_t)(pwtr_drv_mgr.motor_pwm + pwm)){
        pwtr_drv_mgr.motor_pwm = pwtr_drv_mgr.min_allowed_pwm;
    } else if(pwtr_drv_mgr.max_allowed_pwm < (int8_t)(pwtr_drv_mgr.motor_pwm + pwm)) {
        pwtr_drv_mgr.motor_pwm = pwtr_drv_mgr.max_allowed_pwm;
    } else {
        pwtr_drv_mgr.motor_pwm += pwm;
    }
}

uint8_t pwtr_drv::get_pwm(void){
    return pwtr_drv_mgr.motor_pwm;
}

void pwtr_drv::motor_ctrl(Motor_Dir_T dir){
    switch (dir){
        case FORWARD:
            digitalWrite(PT_DRV_DC_MOTOR_A, HIGH);
            digitalWrite(PT_DRV_DC_MOTOR_B, LOW);
            break;
        case REVERSE:
            digitalWrite(PT_DRV_DC_MOTOR_A, LOW);
            digitalWrite(PT_DRV_DC_MOTOR_B, HIGH);
            break;
        case STOP:
            digitalWrite(PT_DRV_DC_MOTOR_A, LOW);
            digitalWrite(PT_DRV_DC_MOTOR_B, LOW);
            break;
        default:
            break;
    }
}

std::vector<std::string> pwtr_drv::export_data(void){
    std::vector<std::string> result;
    /* Result has to be property-value pair */
    result.push_back("Motor PWM");
    result.push_back(std::to_string(pwtr_drv_mgr.motor_pwm));
    return result;
}

static void update_pwm_range(void){
    veh::PRND_T gear = veh::get_gear();
    switch (gear){
    case veh::R3 :
        pwtr_drv_mgr.min_allowed_pwm = PT_DRV_GEAR_R3_PWM_MIN;
        pwtr_drv_mgr.max_allowed_pwm = PT_DRV_GEAR_R3_PWM_MAX;
        break;
    case veh::R2 :
        pwtr_drv_mgr.min_allowed_pwm = PT_DRV_GEAR_R2_PWM_MIN;
        pwtr_drv_mgr.max_allowed_pwm = PT_DRV_GEAR_R2_PWM_MAX;
        break;
    case veh::R1 :
        pwtr_drv_mgr.min_allowed_pwm = PT_DRV_GEAR_R1_PWM_MIN;
        pwtr_drv_mgr.max_allowed_pwm = PT_DRV_GEAR_R1_PWM_MAX;
        break;
    case veh::N :
        pwtr_drv_mgr.min_allowed_pwm = PT_DRV_GEAR_N_PWM;
        pwtr_drv_mgr.max_allowed_pwm = PT_DRV_GEAR_N_PWM;
        break;
    case veh::D1 :
        pwtr_drv_mgr.min_allowed_pwm = PT_DRV_GEAR_D1_PWM_MIN;
        pwtr_drv_mgr.max_allowed_pwm = PT_DRV_GEAR_D1_PWM_MAX;
        break;
    case veh::D2 :
        pwtr_drv_mgr.min_allowed_pwm = PT_DRV_GEAR_D2_PWM_MIN;
        pwtr_drv_mgr.max_allowed_pwm = PT_DRV_GEAR_D2_PWM_MAX;
        break;
    case veh::D3 :
        pwtr_drv_mgr.min_allowed_pwm = PT_DRV_GEAR_D3_PWM_MIN;
        pwtr_drv_mgr.max_allowed_pwm = PT_DRV_GEAR_D3_PWM_MAX;
        break;
    default:
        pwtr_drv_mgr.min_allowed_pwm = PT_DRV_GEAR_N_PWM;
        pwtr_drv_mgr.max_allowed_pwm = PT_DRV_GEAR_N_PWM;
        break;
    }
    /* Update PWM based on current gear */
    inc_pwm(0);
}