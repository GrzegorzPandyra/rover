#ifndef FAN_CTRL_H
#define FAN_CTRL_H

#include <vector>
#include "../../common/pwm_channel/pwm_channel.hpp"

namespace fan_ctrl{

    void init(void);
    void run(void);
    PWM_Channel& pwm(void);
}

#endif