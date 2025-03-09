#include <iostream>
#include <string>
#include <vector>
#include <mutex>
#include "if/SWC_Veh_ClientIf.hpp"
#include "if/SWC_Veh_SysIf.hpp"
#include "if/SWC_Logger_ClientIf.hpp"
#include "if/SWC_ThreadMgr_ClientIf.hpp"
#include "if/SWC_StatMon_ClientIf.hpp"
#include "cfg/VehCfg.hpp"


namespace SWC_Veh
{
    namespace 
    {
        void Run(void);
        SWC_Types::SWC swcData = {Run, PwtrCfg::SYSTEM_TYPE, PwtrCfg::SWC_NAME};

        void Run(void)
        {
        }

        std::vector<std::string> MonitorData(void)
        {
            std::vector<std::string> result;
            const char PRND_STR[][3] = {"R", "N", "D1", "D2", "D3"};
            result.push_back("PRND : ");
            // result.push_back(PRND_STR[mgr.prnd]);
            result.push_back("RPS : ");
            result.push_back("RPS22: ");
            // result.push_back(std::to_string(mgr.rps).substr(0, 4));
            return result;
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
            SWC_StatMon::ClientIf::RegisterMonitor({
                VehCfg::MON_WIN_X,
                VehCfg::MON_WIN_Y,
                VehCfg::MON_WIN_WIDTH,
                VehCfg::MON_WIN_HEIGHT,
                MonitorData,
                VehCfg::SWC_NAME
            });
            INFO("Vehicle SWC init complete");
            return SWC_Types::STATUS_OK;
        }
    }

    namespace ClientIf
    {

    }
}