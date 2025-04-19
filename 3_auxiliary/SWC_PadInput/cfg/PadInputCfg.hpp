#ifndef PAD_INPUT_CFG_H
#define PAD_INPUT_CFG_H
#include <stdint.h>
#include "SwcTypes.hpp"

namespace SWC::PadInput::Cfg
{
    using namespace GlobalTypes;
    
    constexpr char SWC_NAME[] = "PadInput";
    constexpr SystemType  SWC_SYSTEM_TYPE = AUXILIARY;

    /* Joystick */
    const uint8_t PAD_BTN_X         = 3;
    const uint8_t PAD_BTN_Y         = 4;
    const uint8_t PAD_BTN_A         = 0;
    const uint8_t PAD_BTN_B         = 1;
    const uint8_t PAD_BTN_R1        = 7;
    const uint8_t PAD_BTN_R2        = 9;
    const uint8_t PAD_BTN_L1        = 6;
    const uint8_t PAD_BTN_L2        = 8;
    const uint8_t PAD_BTN_LSTICK    = 13;
    const uint8_t PAD_BTN_RSTICK    = 14;
    const uint8_t PAD_BTN_SELECT    = 10;
    const uint8_t PAD_BTN_START     = 11;
    const uint8_t PAD_AXIS_LSTICK_H = 0;
    const uint8_t PAD_AXIS_LSTICK_V = 1;
    const uint8_t PAD_AXIS_RSTICK_H = 2;
    const uint8_t PAD_AXIS_RSTICK_V = 3;
    const uint8_t PAD_AXIS_DPAD_H   = 6;
    const uint8_t PAD_AXIS_DPAD_V   = 7;
    const int16_t PAD_AXIS_MIN      = -32767;
    const int16_t PAD_AXIS_MAX      = 32767;
    const char    DEVICE_PATH[]     = "/dev/input/js0";

    const uint8_t BUTTON_PRESSED    = 1;
    const uint8_t BUTTON_RELEASED   = 0;

    constexpr uint8_t MON_WIN_HEIGHT =  21u;
    constexpr uint8_t MON_WIN_WIDTH  =  24u;
    constexpr uint8_t MON_WIN_Y      =  11u;
    constexpr uint8_t MON_WIN_X      =  165u;
}

#endif
