#ifndef STEER_SYS_H
#define STEER_SYS_H

#include <vector>
#include "../../common/pwm_channel/pwm_channel.hpp"

namespace steer_sys{
    struct Servo_Pwm_T {
        uint8_t left_servo;
        uint8_t right_servo;
    };

    void init(void);
    void run(void);
    PWM_Channel& left_servo_pwm(void);
    PWM_Channel& right_servo_pwm(void);
    std::vector<std::string> export_data(void);
}

#endif /* STEER_SYS_H */
