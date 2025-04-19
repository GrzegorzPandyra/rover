#ifndef INPUT_CFG_H
#define INPUT_CFG_H

#include "SwcTypes.hpp"

namespace SWC::Input::Cfg
{
    using namespace GlobalTypes;

    constexpr char SWC_NAME[]  = "Input";
    constexpr SystemType SWC_SYSTEM_TYPE = PRIMARY;

    /* Monitor */
    constexpr uint8_t MON_WIN_HEIGHT = 21u;
    constexpr uint8_t MON_WIN_WIDTH  = 24u;
    constexpr uint8_t MON_WIN_Y      = 11u;
    constexpr uint8_t MON_WIN_X      = 140u;

    /* User interface key binding */
    constexpr char KEY_FORWARD      = 'w'; /* KEY_UP */
    constexpr char KEY_BACKWARD     = 's'; /* KEY_DOWN */
    constexpr char KEY_TURN_RIGHT   = 'd'; /* KEY_LEFT */
    constexpr char KEY_TURN_LEFT    = 'a'; /* KEY_RIGHT */
    constexpr char KEY_STOP         = 'q';
    constexpr char KEY_PWM_AUTO_DEC = 't';
    constexpr char KEY_HARDSTART    = 'g';

    constexpr char KEY_SHIFT_UP   = 'r';
    constexpr char KEY_SHIFT_DOWN = 'f';
    
    constexpr char KEY_FAN_SPEED_INC = ']';
    constexpr char KEY_FAN_SPEED_DEC = '[';
    
    constexpr char KEY_HEADLIGHT_PWM_INC = '1';
    constexpr char KEY_HEADLIGHT_PWM_DEC = '2';
    constexpr char KEY_ROOFLIGHT_PWM_INC = '3';
    constexpr char KEY_ROOFLIGHT_PWM_DEC = '4';
    constexpr char KEY_REARLIGHT_PWM_INC = '5';
    constexpr char KEY_REARLIGHT_PWM_DEC = '6';
    
    constexpr char KEY_SHUTDOWN = '.';
    
    constexpr char KEY_BUZZER = 'b';
}
#endif
