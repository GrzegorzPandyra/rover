#ifndef SWC_PWTR_CLIENTIF_H
#define SWC_PWTR_CLIENTIF_H
#include "SwcTypes.hpp"

namespace SWC::Pwtr::MotorControlIf
{
    enum MotorRotation{
        FORWARD,
        BACKWARD,
        STOP
    };

    unsigned GetMotorPWM(void);
    void SetMotorDirection(MotorRotation direction);
    void Accelerate(void);
    void Decelerate(void);
    void Stop(void);
}

#endif