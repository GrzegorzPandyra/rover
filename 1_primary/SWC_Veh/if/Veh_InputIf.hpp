#ifndef SWC_VEH_INPUT_IF_H
#define SWC_VEH_INPUT_IF_H
#include "SwcTypes.hpp"

namespace SWC::Veh::InputIf
{
    void Forward(void);
    void Backward(void);
    void TurnLeft(void);
    void TurnRight(void);
    void Stop(void);
    void ShiftUp(void);
    void ShiftDown(void);
    void TogglePWMAutoDecrement(void);
    void FanSpeedUp(void);
    void FanSlowDown(void);
}

#endif