#ifndef SWC_LIGHTS_CLIENTIF_H
#define SWC_LIGHTS_CLIENTIF_H
#include "SwcTypes.hpp"
#include "PWMChannel.hpp"

namespace SWC::Lights::LightControl {
    enum LightType {
        HEADLIGHT,
        ROOFLIGHT,
        REARLIGHT
    };

    PWMChannel::PWMValue GetLightPWM(LightType type);
    PWMChannel::PWMValue IncLightPWM(LightType type);
    PWMChannel::PWMValue DecLightPWM(LightType type);
}
#endif