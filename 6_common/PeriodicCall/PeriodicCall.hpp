#ifndef CLASS_PERIODIC_CALL_H
#define CLASS_PERIODIC_CALL_H

#include <stdint.h>
#include <chrono>
#include "GlobalTypes.hpp"

using namespace GlobalTypes;
using namespace std::chrono;

class PeriodicCall {
    public:
    PeriodicCall(GenericCbk cbk, milliseconds period_ms);
    ~PeriodicCall();
    void Init();
    void Run(void);
    void Reset(void);
    void Enable(void);
    void Disable(void);
    bool IsEnabled(void);
    private:
        const GenericCbk M_CBK;
        const milliseconds M_PERIOD;
        bool m_enabled;
        time_point<system_clock> m_time_expired;
        
};

#endif /* CLASS_PWM_CHANNEL_H */