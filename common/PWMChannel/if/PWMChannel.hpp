#ifndef CLASS_PWM_CHANNEL_H
#define CLASS_PWM_CHANNEL_H

#include <stdint.h>

class PWMChannel {
    public:
        typedef uint8_t PWMValue;
        PWMChannel(const uint8_t pin,
                    const PWMValue min,
                    const PWMValue max,
                    const PWMValue defVal,
                    const PWMValue step);
        ~PWMChannel();
        void Init();
        PWMValue Inc(void);
        PWMValue Dec(void);
        PWMValue SetVal(PWMValue value);
        PWMValue GetVal();
        void Run(void);
    private:
        const uint8_t  M_PWM_PIN;
        const PWMValue M_PWM_MIN;
        const PWMValue M_PWM_MAX;
        const PWMValue M_PWM_DEFAULT;
        const PWMValue M_PWM_STEP;
        PWMValue m_pwmValue;
};

#endif /* CLASS_PWM_CHANNEL_H */