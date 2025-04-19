#include "PeriodicCall.hpp"

PeriodicCall::PeriodicCall(GenericCbk cbk, std::chrono::milliseconds period) : M_CBK(cbk), M_PERIOD(period)
{ 

}

PeriodicCall::~PeriodicCall(){
    /* Destructor body */
}

void PeriodicCall::Init(){
    m_time_expired = std::chrono::system_clock::now();
    m_enabled = true;
}

void PeriodicCall::Run(){
    using namespace std::chrono;

    if(!m_enabled) return;

    time_point<system_clock> now = system_clock::now();
    if((now - M_PERIOD) > m_time_expired){
        M_CBK();
        m_time_expired = now;
    }
}

void PeriodicCall::Reset(void){
    m_time_expired = std::chrono::system_clock::now();
}

void PeriodicCall::Enable(void){
    m_enabled = true;
}

void PeriodicCall::Disable(void){
    m_enabled = false;
}

bool PeriodicCall::IsEnabled(void){
    return m_enabled;
}