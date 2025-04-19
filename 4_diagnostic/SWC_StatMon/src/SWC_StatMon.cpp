#include <iostream>
#include <string>
#include <vector>
#include <mutex>
#include "StatMon_ClientIf.hpp"
#include "StatMon_SysIf.hpp"
#include "Logger_ClientIf.hpp"
#include "ThreadMgr_ClientIf.hpp"
#include "StatMonCfg.hpp"
#include "NCurses.hpp"
#include "calib.hpp"

namespace SWC::StatMon
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

        struct {
            SWC::Types::SwcContext statMonCtx =
            {
                SWC::StatMon::Cfg::SWC_NAME, 
                SWC::StatMon::Cfg::SWC_SYSTEM_TYPE,
                SWC::Types::INIT,
                Run
            };
            std::vector<Monitor> monitors;
            std::mutex registration_mtx;
        } ccb; /* Component Control Block */

        void Run(void)
        {
            for(auto& mon : ccb.monitors){
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
}

namespace SWC::StatMon::SysIf
{
    GlobalTypes::CallResult Stop()
    {
        return GlobalTypes::CALL_OK;
    }

    GlobalTypes::CallResult Init()
    {
        SWC::ThreadMgr::ClientIf::RegisterSWC(&ccb.statMonCtx);
        std::string log(SWC::StatMon::Cfg::SWC_NAME);
        log += "SWC init complete";
        INFO(log);
        return GlobalTypes::CALL_OK;
    }
}

namespace SWC::StatMon::ClientIf
{
    GlobalTypes::CallResult RegisterMonitor(MonitorProperties prop)
    {
        std::lock_guard<std::mutex> lock(ccb.registration_mtx);
        Monitor mon = 
        {
            prop.name,
            prop.cbk,
            NCurses::CreateWindow(prop.x, prop.y, prop.width, prop.height, prop.name)
        };
        ccb.monitors.push_back(mon);
        return GlobalTypes::CALL_OK;
    }
}