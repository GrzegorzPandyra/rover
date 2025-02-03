#ifndef PWTR_H
#define PWTR_H

#include <vector>
#include "../../common/pwm_channel/pwm_channel.hpp"

namespace pwtr{

    enum Motor_Dir_T{
        FORWARD = 0,
        REVERSE,
        STOP
    };

    void init(void);
    void run(void);
    void expire_pwm(void);
    void toggle_pwm_dec(void);
    void toggle_hardstart(void);
    PWM_Channel& pwm(void);
    std::vector<std::string> export_data(void);
    
}

#endif /* PWTR_H */