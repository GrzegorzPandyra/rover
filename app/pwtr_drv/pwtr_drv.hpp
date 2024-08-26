#ifndef PWTR_DRV_H
#define PWTR_DRV_H

#include <vector>

namespace pwtr_drv{

    void init(void);
    void run(void);
    void set_pwm(uint8_t pwm);
    void inc_pwm(int8_t pwm);
    uint8_t get_pwm(void);
    std::vector<std::string> export_data(void);
    
}

#endif /* PWTR_DRV_H */