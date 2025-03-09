#include "if/PWMChannel.hpp"
#include "if/WiringPi.hpp"

PWMChannel::PWMChannel( const uint8_t pin,
                        const PWMValue min,
                        const PWMValue max,
                        const PWMValue defVal,
                        const PWMValue step)
                         /* Initialization list */ :
                        M_PWM_PIN(pin),
                        M_PWM_MIN(min),
                        M_PWM_MAX(max),
                        M_PWM_DEFAULT(defVal),
                        M_PWM_STEP(step)              
{ 
    m_pwmValue = defVal;
}

PWMChannel::~PWMChannel(){
    /* Destructor body */
}

void PWMChannel::Init(){
    WiringPi::SetPinMode(M_PWM_PIN, WiringPi::PM_OUTPUT);
    WiringPi::CreateSoftPWM(M_PWM_PIN, M_PWM_MIN, M_PWM_MAX);
}

PWMChannel::PWMValue PWMChannel::Inc(void){
    SetVal(m_pwmValue + M_PWM_STEP);
    return m_pwmValue;
}

PWMChannel::PWMValue PWMChannel::Dec(void){
    SetVal(m_pwmValue - M_PWM_STEP);
    return m_pwmValue;
}

PWMChannel::PWMValue PWMChannel::SetVal(PWMChannel::PWMValue value){
    /* Check PWM range */
    if(M_PWM_MIN > value){
        m_pwmValue = M_PWM_MIN;
    } else if(M_PWM_MAX < value){
        m_pwmValue = M_PWM_MAX;
    } else {
        m_pwmValue = value;
    }
    return m_pwmValue;
}

PWMChannel::PWMValue PWMChannel::GetVal(){
    return m_pwmValue;
}

void PWMChannel::Run(void){
    WiringPi::WriteSoftPWM(M_PWM_PIN, m_pwmValue);
}

