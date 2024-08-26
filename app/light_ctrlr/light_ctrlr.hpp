#ifndef LIGHT_CTRLR_H
#define LIGHT_CTRLR_H

#include <vector>

namespace light_ctrlr{
    enum Light_T {
        HEADLIGHT,
        ROOFLIGHT,
        REARLIGHT
    };

    void init(void);
    void run(void);
    void set_pwm(uint8_t pwm, Light_T light);
    void inc_pwm(int8_t pwm, Light_T light);
    uint8_t get_pwm(Light_T light);
    std::vector<std::string> export_data(void);
}

#endif