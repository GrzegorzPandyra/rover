#include <iostream>
#include <vector>
#include "pwtr.hpp"
#include <wiringPi.h>
#include "../../app/ui/ui_logging.hpp"
#include "../../cfg/calib.hpp"
#include "../veh/veh.hpp"
#include "../tacho/tacho.hpp"
#include "../fan_ctrl/fan_ctrl.hpp"

static void motor_rotation(void);

using namespace pwtr;

static struct {
    PWM_Channel motor_pwm = PWM_Channel(
        PT_DRV_DC_MOTOR_PWM,
        PT_DRV_PWM_MIN_VAL,
        PT_DRV_PWM_MAX_VAL,
        PT_DRV_PWM_DEF_VAL,
        PT_DRV_PWM_INC_STEP
    );
    bool hardstart;
    uint16_t hardstart_timer;
    bool pwm_auto_dec;
} mgr;

void pwtr::init(void){
    pinMode(PT_DRV_DC_MOTOR_A, OUTPUT);
    pinMode(PT_DRV_DC_MOTOR_B, OUTPUT);

    digitalWrite(PT_DRV_DC_MOTOR_A, LOW);
    digitalWrite(PT_DRV_DC_MOTOR_B, LOW);

    mgr.motor_pwm.Init();

    mgr.hardstart = FALSE;
    mgr.pwm_auto_dec = TRUE;

    LOG("SWC [pwtr] init\n");
}

void pwtr::run(void){
    motor_rotation();
    mgr.motor_pwm.Run();
    // if(mgr.hardstart && (mgr.hardstart_timer > 0u)){
    //     softPwmWrite(PT_DRV_DC_MOTOR_PWM, PT_HARDSTART_PWM);
    //     mgr.hardstart_timer -= PT_TASK_PERIOD_MS;
    // } else {
    //     softPwmWrite(PT_DRV_DC_MOTOR_PWM, mgr.motor_pwm);
    // }
    // if(tacho::get_speed() < PT_HARDSTART_RPS_THRESHOLD){
    //     mgr.hardstart_timer = PT_HARDSTART_PERIOD_MS;
    // }

}

void pwtr::expire_pwm(void){
    if(mgr.pwm_auto_dec){
        mgr.motor_pwm.Dec();
    }
}

PWM_Channel& pwtr::pwm(void){
    return mgr.motor_pwm;
}

void pwtr::toggle_pwm_dec(void){
    mgr.pwm_auto_dec = !mgr.pwm_auto_dec;
}

void pwtr::toggle_hardstart(void){
    mgr.hardstart = !mgr.hardstart;
}

std::vector<std::string> pwtr::export_data(void){
    std::vector<std::string> result;
    /* Result has to be property-value pair */
    result.push_back("Motor PWM");
    result.push_back(std::to_string(mgr.motor_pwm.Get()));
    result.push_back("PWM auto decrementation");
    result.push_back(std::to_string(mgr.pwm_auto_dec));
    result.push_back("Hardstart");
    result.push_back(std::to_string(mgr.hardstart));
    result.push_back("Fan PWM");
    result.push_back(std::to_string(fan_ctrl::pwm().Get()));
    return result;
}

static void motor_rotation(void){
    switch (veh::get_gear()){
        case veh::PRND_D1:
        case veh::PRND_D2:
        case veh::PRND_D3:
            digitalWrite(PT_DRV_DC_MOTOR_A, HIGH);
            digitalWrite(PT_DRV_DC_MOTOR_B, LOW);
            break;
        case veh::PRND_R:
            digitalWrite(PT_DRV_DC_MOTOR_A, LOW);
            digitalWrite(PT_DRV_DC_MOTOR_B, HIGH);
            break;
        case veh::PRND_N:
        default:
            digitalWrite(PT_DRV_DC_MOTOR_A, LOW);
            digitalWrite(PT_DRV_DC_MOTOR_B, LOW);
            mgr.motor_pwm.Set(PT_DRV_PWM_DEF_VAL);
            break;
            break;
    }
}