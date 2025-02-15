#ifndef FAN_CTRL_H
#define FAN_CTRL_H

#include <vector>
#include "pwm_channel.hpp"

namespace fan_ctrl{

    void init(void);
    void run(void);
    PWM_Channel& pwm(void);
}

#endif