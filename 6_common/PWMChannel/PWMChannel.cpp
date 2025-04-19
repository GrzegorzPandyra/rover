#include "PWMChannel.hpp"
#include "WiringPi.hpp"

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
    m_currentValue = defVal;
}

PWMChannel::~PWMChannel(){
    /* Destructor body */
}

void PWMChannel::Init(){
    WiringPi::SetPinMode(M_PWM_PIN, WiringPi::PM_OUTPUT);
    WiringPi::CreateSoftPWM(M_PWM_PIN, M_PWM_MIN, M_PWM_MAX);
}

PWMChannel::PWMValue PWMChannel::Inc(void){
    SetValue(m_currentValue + M_PWM_STEP);
    return m_currentValue;
}

PWMChannel::PWMValue PWMChannel::Dec(void){
    if((m_currentValue - M_PWM_MIN) < M_PWM_STEP)
        SetValue(M_PWM_MIN);
    else
        SetValue(m_currentValue - M_PWM_STEP);
    return m_currentValue;
}

PWMChannel::PWMValue PWMChannel::SetValue(PWMChannel::PWMValue value){
    /* Check PWM range */
    if(value < M_PWM_MIN ){
        m_currentValue = M_PWM_MIN;
    } else if(value > M_PWM_MAX){
        m_currentValue = M_PWM_MAX;
    } else {
        m_currentValue = value;
    }
    return m_currentValue;
}

PWMChannel::PWMValue PWMChannel::GetValue(){
    return m_currentValue;
}

void PWMChannel::Run(void){
    WiringPi::WriteSoftPWM(M_PWM_PIN, m_currentValue);
}

