#ifndef PWTR_DRV_H
#define PWTR_DRV_H

#include <vector>

namespace pwtr_drv{

    enum Motor_Dir_T{
        FORWARD = 0,
        REVERSE,
        STOP
    };

    void init(void);
    void run(void);
    void set_pwm(uint8_t pwm);
    void inc_pwm(int8_t pwm);
    uint8_t get_pwm(void);
    void motor_ctrl(Motor_Dir_T dir);
    std::vector<std::string> export_data(void);
    
}

#endif /* PWTR_DRV_H */