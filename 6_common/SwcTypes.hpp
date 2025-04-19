#ifndef SWC_TYPES_H
#define SWC_TYPES_H
#include <string>
#include "GlobalTypes.hpp"

namespace SWC::Types
{
    typedef void (*RunCallbackPtr)(void);

    enum SwcStatus
    {
        INIT,
        RUN,
        STOP,
        ERROR
    };

    struct SwcContext 
    {
        const std::string name; 
        const GlobalTypes::SystemType systemType; 
        SwcStatus status;
        const RunCallbackPtr run;
    };
}

#endif