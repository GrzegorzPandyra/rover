#include <iostream>
#include <unistd.h>
#include "ThreadMgr_SysIf.hpp"
#include "NCurses.hpp"
#include "WiringPi.hpp"
#include "Logger_SysIf.hpp"
#include "StatMon_SysIf.hpp"
#include "Veh_SysIf.hpp"
#include "Pwtr_SysIf.hpp"
#include "StSys_SysIf.hpp"
#include "Input_SysIf.hpp"
#include "Buzzer_SysIf.hpp"
#include "Tacho_SysIf.hpp"
#include "Fan_SysIf.hpp"
#include "PadInput_SysIf.hpp"
#include "Lights_SysIf.hpp"

#if __cplusplus < 201703L
#error Invalid C++ version - expecting C++17 or higher
#endif

int main()
{
    NCurses::Init();
    WiringPi::Init();
    SWC::Logger::SysIf::Init();
    SWC::StatMon::SysIf::Init();
    SWC::Veh::SysIf::Init();
    SWC::Pwtr::SysIf::Init();
    SWC::StSys::SysIf::Init();
    SWC::Input::SysIf::Init();
    SWC::Buzzer::SysIf::Init();
    SWC::Tacho::SysIf::Init();
    SWC::Fan::SysIf::Init();
    SWC::PadInput::SysIf::Init();
    SWC::Lights::SysIf::Init();
    SWC::ThreadMgr::SysIf::Init(); /* Must be last */

    return 0;
}

