#include <iostream>
#include <vector>
#include "fan_ctrl.hpp"
#include "../../app/ui/ui_logging.hpp"
#include "../../cfg/calib.hpp"

using namespace fan_ctrl;

static struct {
    PWM_Channel fan_pwm = PWM_Channel(
        FAN_CTRL_FAN_PWM,
        FAN_CTRL_PWM_MIN,
        FAN_CTRL_PWM_MAX,
        FAN_CTRL_PWM_DEF_VAL,
        FAN_CTRL_PWM_INC_STEP
    );
} mgr;

/**************************************************************************
 *** Interface functions
 *************************************************************************/

void fan_ctrl::init(void){
    mgr.fan_pwm.Init();
    LOG("SWC [fan_ctrl] init\n");
}

void fan_ctrl::run(void){
    mgr.fan_pwm.Run();
}

PWM_Channel& fan_ctrl::pwm(void){
    return mgr.fan_pwm;
}