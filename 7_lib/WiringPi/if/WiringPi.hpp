#ifndef LIB_WIRINGPI_H
#define LIB_WIRINGPI_H


namespace WiringPi{
    enum PinState
    {
        PIN_LOW = 0,
        PIN_HIGH = 1
    };

    enum PinMode
    {
        PM_INPUT = 0,
        PM_OUTPUT = 1,
        PM_PWM_OUTPUT = 2
    };

    void Init(void);
    void SetPin(int pin, PinState state);
    PinState GetPin(int pin);
    void SetPinMode(int pin, PinMode mode);
    void CreateSoftPWM(int pin, int min, int max);
    void WriteSoftPWM(int pin, int val);
}

#endif /* LIB_WIRINGPI_H */