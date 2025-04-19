#include "DelayedCall.hpp"

DelayedCall::DelayedCall(GenericCbk cbk, std::chrono::milliseconds timeout) : M_CBK(cbk), M_TIMEOUT(timeout)
{ 

}

DelayedCall::~DelayedCall(){
    /* Destructor body */
}

void DelayedCall::Init(){
    m_enabled = false;
}

void DelayedCall::Run(){
    using namespace std::chrono;

    if(!m_enabled) return;

    time_point<system_clock> now = system_clock::now();
    if((now - M_TIMEOUT) > m_start_time){
        M_CBK();
        DelayedCall::Disable();
    }
}

void DelayedCall::Set(void){
    m_start_time = std::chrono::system_clock::now();
    DelayedCall::Enable();
}

void DelayedCall::Reset(void){
    m_start_time = std::chrono::system_clock::now();
}

void DelayedCall::Enable(void){
    m_enabled = true;
}

void DelayedCall::Disable(void){
    m_enabled = false;
}

bool DelayedCall::IsEnabled(void){
    return m_enabled;
}