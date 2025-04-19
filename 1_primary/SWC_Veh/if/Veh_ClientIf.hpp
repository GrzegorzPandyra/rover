#ifndef SWC_VEH_CLIENTIF_H
#define SWC_VEH_CLIENTIF_H
#include "SwcTypes.hpp"

namespace SWC::Veh::ClientIf
{
    enum PRND {
        PRND_R  = 0,
        PRND_N  = 1,
        PRND_D1 = 2,
        PRND_D2 = 3,
        PRND_D3 = 4
    };
    PRND ShiftUp(void);
    PRND ShiftDown(void);
    PRND GetGear(void);
    PRND SetGear(PRND gear);
}

#endif