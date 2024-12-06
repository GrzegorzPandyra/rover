#ifndef LIGHT_CTRL_H
#define LIGHT_CTRL_H

#include <vector>
#include "../../common/pwm_channel/pwm_channel.hpp"

namespace light_ctrl{
    enum Light_T {
        HEADLIGHT,
        ROOFLIGHT,
        REARLIGHT
    };

    void init(void);
    void run(void);
    PWM_Channel& get_headlight_pwm(void);
    PWM_Channel& get_rooflight_pwm(void);
    PWM_Channel& get_rearlight_pwm(void);
    std::vector<std::string> export_data(void);
}

#endif