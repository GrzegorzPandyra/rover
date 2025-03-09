#ifndef VEH_CFG_H
#define VEH_CFG_H

#include "SWC_Types.hpp"

namespace VehCfg
{
    constexpr uint8_t MON_WIN_HEIGHT = 10u;
    constexpr uint8_t MON_WIN_WIDTH  = 40u;
    constexpr uint8_t MON_WIN_Y      = 1u;
    constexpr uint8_t MON_WIN_X      = 100u;
    constexpr char    SWC_NAME[]     = "Vehicle";
    constexpr SWC_Types::SystemType SYSTEM_TYPE = SWC_Types::ST_SECONDARY;
}
#endif
