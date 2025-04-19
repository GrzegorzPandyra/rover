#include <wiringPi.h>
#include <softPwm.h>
#include "WiringPi.hpp" 
#include "Logger_ClientIf.hpp"

namespace WiringPi
{
    void Init(void){
        wiringPiSetupGpio();
        /* PWM setup
         * pwmSetClock - clock at 50kHz (20us tick)
         * pwmSetRange - range at 2000 ticks (20ms)
         * */
        pwmSetMode(PWM_MODE_MS);
        pwmSetClock(192);
        pwmSetRange(1024);
        INFO("WiringPi lib init");
    }

    void SetPin(int pin, PinState state)
    {
        digitalWrite(pin, state);
    }
    
    PinState GetPin(int pin)
    {
        return (digitalRead(pin) ? PIN_HIGH : PIN_LOW);
    }
    
    void SetPinMode(int pin, PinMode mode)
    {
        pinMode(pin, mode);
    }

    void CreateSoftPWM(int pin, int min, int max)
    {
        softPwmCreate(pin, min, max);
    }

    void WriteSoftPWM(int pin, int val)
    {
        softPwmWrite(pin, val);
    }
    
}
