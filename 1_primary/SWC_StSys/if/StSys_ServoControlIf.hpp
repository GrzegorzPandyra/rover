#ifndef SWC_STEERING_SYSTEM_CLIENTIF_H
#define SWC_STEERING_SYSTEM_CLIENTIF_H
#include "SwcTypes.hpp"
#include "PWMChannel.hpp"

namespace SWC::StSys::ServoControl {
    void TurnLeft(void);
    void TurnRight(void);
    void Set(PWMChannel::PWMValue target);
}
#endif