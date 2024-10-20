#ifndef CLASS_PWM_H
#define CLASS_PWM_H

#include <stdint.h>

class PWM_Channel {
    public:
        PWM_Channel(const uint8_t pin,
                    const uint8_t min,
                    const uint8_t max,
                    const uint8_t def_val,
                    const uint8_t step);
        ~PWM_Channel();
        void Init();
        uint8_t Inc(void);
        uint8_t Dec(void);
        uint8_t Set(uint8_t value);
        uint8_t Get();
        void Run(void);
    private:
        const uint8_t PWM_PIN;
        const uint8_t PWM_MIN;
        const uint8_t PWM_MAX;
        const uint8_t PWM_DEFAULT;
        const uint8_t PWM_STEP;
        uint8_t pwm;
};

#endif