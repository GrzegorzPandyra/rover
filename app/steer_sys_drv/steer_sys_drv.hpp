#ifndef STEER_SYS_DRV_H
#define STEER_SYS_DRV_H

#include <vector>

namespace steer_sys_drv{
    struct Servo_Pwm_T {
        uint8_t left_servo;
        uint8_t right_servo;
    };

    void init(void);
    void run(void);
    void set_pwm(uint8_t pwm);
    void inc_pwm(int8_t pwm);
    Servo_Pwm_T get_pwm(void);
    std::vector<std::string> export_data(void);
}

#endif /* STEER_SYS_DRV_H */
