#ifndef LIGHT_CTRLR_H
#define LIGHT_CTRLR_H

#include <vector>
#include "../../class/pwm_channel/pwm_channel.hpp"

namespace light_ctrlr{
    enum Light_T {
        HEADLIGHT,
        ROOFLIGHT,
        REARLIGHT
    };

    void init(void);
    void run(void);
    PWM_Channel& headlight_pwm(void);
    PWM_Channel& rooflight_pwm(void);
    PWM_Channel& rearlight_pwm(void);
    std::vector<std::string> export_data(void);
}

#endif