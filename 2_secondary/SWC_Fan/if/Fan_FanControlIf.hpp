#ifndef SWC_FAN_FANCONTROL_IF_H
#define SWC_FAN_FANCONTROL_IF_H
#include "SwcTypes.hpp"

namespace SWC::Fan::FanControl {
    enum FanSpeed {
        OFF,
        LOW,
        MEDIUM,
        HIGH,
        MAX
    };
    FanSpeed GetFanSpeed(void);
    void SetFanSpeed(FanSpeed speed);
    void IncFanSpeed(void);
    void DecFanSpeed(void);
}
#endif