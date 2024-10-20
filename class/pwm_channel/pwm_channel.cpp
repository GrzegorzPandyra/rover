#include "pwm_channel.hpp"
#include <wiringPi.h>
#include <softPwm.h>

PWM_Channel::PWM_Channel(const uint8_t pin,
                         const uint8_t min,
                         const uint8_t max,
                         const uint8_t def_val,
                         const uint8_t step)
                         /* Initialization list */ :
                        PWM_PIN(pin),
                        PWM_MIN(min),
                        PWM_MAX(max),
                        PWM_DEFAULT(def_val),
                        PWM_STEP(step)              
{ 
    this->pwm = def_val;
}

PWM_Channel::~PWM_Channel(){
    /* Destructor body */
}

void PWM_Channel::Init(){
    pinMode(this->PWM_PIN, PWM_OUTPUT);
    softPwmCreate(this->PWM_PIN, this->PWM_MIN, this->PWM_MAX);
}

uint8_t PWM_Channel::Inc(void){
    Set(this->pwm + this->PWM_STEP);
    return this->pwm;
}

uint8_t PWM_Channel::Dec(void){
    uint8_t value = (this->pwm >= this->PWM_STEP) ? (this->pwm - this->PWM_STEP) : this->pwm;
    Set(value);
    return this->pwm;
}

uint8_t PWM_Channel::Set(uint8_t value){
    /* Check PWM range */
    if(this->PWM_MIN > value){
        this->pwm = this->PWM_MIN;
    } else if(this->PWM_MAX < value){
        this->pwm = this->PWM_MAX;
    } else {
        this->pwm = value;
    }
    return this->pwm;
}

uint8_t PWM_Channel::Get(){
    return this->pwm;
}

void PWM_Channel::Run(void){
    softPwmWrite(this->PWM_PIN, this->pwm);
}

