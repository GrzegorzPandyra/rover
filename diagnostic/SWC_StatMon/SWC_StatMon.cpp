#include <iostream>
#include <string>
#include <vector>
#include <mutex>
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

        struct Monitor {
            std::string name;
            ClientIf::MonitorCallback cbk;
            mutable NCWindow* win;
        };


        SWC_Types::SWC swcData = {Run, STATMON_CFG_SWC_SYS_TYPE, STATMON_CFG_SWC_NAME};
        std::vector<Monitor> monitors;
        std::mutex registration_mtx;

        void Run(void)
        {
            for(auto& mon : monitors){
                UpdateMonitor(mon);
                mon.win->Refresh();
            }
        }

        void UpdateMonitor(Monitor mon){
            if(nullptr != mon.cbk)
            {
                int i=1;
                std::vector<std::string> monData = mon.cbk();
                for(auto& str : monData)
                {
                    mon.win->Print(1, i++, str);
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
            SWC_ThreadMgr::ClientIf::RegisterSWC(&swcData);
            INFO(STATMON_CFG_SWC_NAME "SWC init complete");
            return SWC_Types::STATUS_OK;
        }
    }

    namespace ClientIf
    {
        SWC_Types::Status RegisterMonitor(MonitorProperties prop)
        {
            std::lock_guard<std::mutex> lock(registration_mtx);
            Monitor mon = 
            {
                prop.name,
                prop.cbk,
                NCurses::CreateWindow(prop.x, prop.y, prop.width, prop.height, prop.name)
            };
            monitors.push_back(mon);
            return SWC_Types::STATUS_OK;
        }
    }
}