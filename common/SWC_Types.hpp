#ifndef SWC_TYPES_H
#define SWC_TYPES_H
#include <string>

namespace SWC_Types
{
    enum Status
    {
        OK,
        ERROR
    };

    typedef void (*RunCallbackPtr)(void);

    enum SystemType
    {
        ST_PRIMARY,  
        ST_SECONDARY,  
        ST_AUXILIARY,  
        ST_DIAGNOSTIC  
    };

    struct SWC 
    {
        RunCallbackPtr run;
        SystemType systemType; 
        std::string name; 
    };
}

#endif