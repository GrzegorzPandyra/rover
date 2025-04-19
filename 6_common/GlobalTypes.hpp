#ifndef GLOBAL_TYPES_H
#define GLOBAL_TYPES_H

namespace GlobalTypes
{
    typedef void (*GenericCbk)(void);
    typedef void (*PadAxisCbk)(int);

    enum CallResult
    {
        CALL_OK,
        CALL_FAILED,
        CALL_ERROR
    };

    enum SystemType
    {
        PRIMARY = 0,  
        SECONDARY,  
        AUXILIARY,  
        DIAGNOSTIC  
    };
}

#endif