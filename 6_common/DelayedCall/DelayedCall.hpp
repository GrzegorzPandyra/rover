#ifndef CLASS_DELAYED_CALL_H
#define CLASS_DELAYED_CALL_H

#include <stdint.h>
#include <chrono>
#include "GlobalTypes.hpp"

using namespace GlobalTypes;
using namespace std::chrono;

class DelayedCall {
    public:
    DelayedCall(GenericCbk cbk, milliseconds timeout);
    ~DelayedCall();
    void Init();
    void Run(void);
    void Set(void);
    void Reset(void);
    void Enable(void);
    void Disable(void);
    bool IsEnabled(void);
    private:
        const GenericCbk M_CBK;
        const milliseconds M_TIMEOUT;
        bool m_enabled;
        time_point<system_clock> m_start_time;
        
};

#endif /* CLASS_DELAYED_CALL_H */