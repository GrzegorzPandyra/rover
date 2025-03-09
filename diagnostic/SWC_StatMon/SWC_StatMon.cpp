#include <iostream>
#include <string>
#include <vector>
#include "if/SWC_StatMon_ClientIf.hpp"
#include "if/SWC_StatMon_SysIf.hpp"
#include "if/SWC_Logger_ClientIf.hpp"
#include "if/SWC_ThreadMgr_ClientIf.hpp"
#include "cfg/StatMonCfg.hpp"
#include "if/NCurses.hpp"
#include "calib.hpp"


namespace SWC_StatMon
{
    namespace 
    {
        struct Monitor;
        void Run(void);
        void UpdateMonitor(Monitor mon);

        enum MonitorId{
            LIGHT_CONTROLLER = 0,
            POWERTRAIN,
            STEERING_SYSTEM,
            VEHICLE,
            POWER,
            INPUT,
            DIAGNOSTIC
        };
        
        struct Monitor {
            MonitorId id;
            std::string name;
            mutable NCWindow* win;
            std::vector<std::string> (*get_app_data)();
        };


        SWC_Types::SWC statMon = {Run, STATMON_CFG_SWC_SYS_TYPE, STATMON_CFG_SWC_NAME};
        static const Monitor monitors[] = {
            {LIGHT_CONTROLLER,  "LIGHT_CONTROLLER", NULL,  nullptr},
            {POWERTRAIN,        "POWERTRAIN",       NULL,  nullptr},
            {STEERING_SYSTEM,   "STEERING_SYSTEM",  NULL,  nullptr},
            {VEHICLE,           "VEHICLE",          NULL,  nullptr},
            {POWER,             "POWER",            NULL,  nullptr},
            {INPUT,             "INPUT",            NULL,  nullptr},
            {DIAGNOSTIC,        "DIAGNOSTIC",       NULL,  nullptr},
        
        };
        const uint8_t NUM_MONITORS = sizeof(monitors)/sizeof(monitors[0]);

        void Run(void)
        {
            for(uint8_t i=0; i<NUM_MONITORS; i++){
                UpdateMonitor(monitors[i]);
                monitors[i].win->Refresh();
            }
        }

        void UpdateMonitor(Monitor mon){
            if(nullptr != mon.get_app_data)
            {
                std::vector<std::string> app_data = mon.get_app_data();
                for(uint8_t i=0u; i<app_data.size(); i+=2u){
                    // mvwprintw(mon.win, (i/2u)+1, 1, "%s", app_data[i].c_str());
                    // wprintw(mon.win, " : ");
                    // wprintw(mon.win, "%s", app_data[i+1u].c_str());
                    // wprintw(mon.win, "   "); /* Clear previously used fields */
                }
            }
        }
    }
    
    namespace SysIf
    {
        SWC_Types::Status Stop()
        {
            return SWC_Types::STATUS_OK;
        }
    
        SWC_Types::Status Init()
        {
            monitors[LIGHT_CONTROLLER].win =    NCurses::CreateWindow(LIGHT_CONTROLLER_WIN_X, LIGHT_CONTROLLER_WIN_Y, LIGHT_CONTROLLER_WIN_WIDTH,  LIGHT_CONTROLLER_WIN_HEIGHT, monitors[LIGHT_CONTROLLER].name );
            monitors[POWERTRAIN].win =          NCurses::CreateWindow(POWERTRAIN_WIN_X,       POWERTRAIN_WIN_Y,       POWERTRAIN_WIN_WIDTH,        POWERTRAIN_WIN_HEIGHT,       monitors[POWERTRAIN].name       );
            monitors[STEERING_SYSTEM].win =     NCurses::CreateWindow(STEERING_SYSTEM_WIN_X,  STEERING_SYSTEM_WIN_Y,  STEERING_SYSTEM_WIN_WIDTH,   STEERING_SYSTEM_WIN_HEIGHT,  monitors[STEERING_SYSTEM].name  );
            monitors[VEHICLE].win =             NCurses::CreateWindow(VEHICLE_WIN_X,          VEHICLE_WIN_Y,          VEHICLE_WIN_WIDTH,           VEHICLE_WIN_HEIGHT,          monitors[VEHICLE].name          );
            monitors[POWER].win =               NCurses::CreateWindow(POWER_WIN_X,            POWER_WIN_Y,            POWER_WIN_WIDTH,             POWER_WIN_HEIGHT,            monitors[POWER].name            );
            monitors[INPUT].win =               NCurses::CreateWindow(INPUT_WIN_X,            INPUT_WIN_Y,            INPUT_WIN_WIDTH,             INPUT_WIN_HEIGHT,            monitors[INPUT].name            );
            monitors[DIAGNOSTIC].win =          NCurses::CreateWindow(DIAGNOSTIC_WIN_X,       DIAGNOSTIC_WIN_Y,       DIAGNOSTIC_WIN_WIDTH,        DIAGNOSTIC_WIN_HEIGHT,       monitors[DIAGNOSTIC].name       );
            SWC_ThreadMgr::ClientIf::RegisterSWC(&statMon);
            INFO(STATMON_CFG_SWC_NAME "SWC init complete");
            return SWC_Types::STATUS_OK;
        }
    }

    namespace ClientIf
    {
    }
}