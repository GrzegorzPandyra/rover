#include <iostream>
#include <string>
#include <vector>
#include <array>
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
        SWC_Types::SWC swcData = {Run, VehCfg::SYSTEM_TYPE, VehCfg::SWC_NAME};
        ClientIf::PRND currentGear = ClientIf::PRND_N;

        void Run(void)
        {
        }

        std::vector<std::string> MonitorData(void)
        {
            std::vector<std::string> result;
            std::array<std::string, 5> gears = {"R", "N", "D1", "D2", "D3"};
            result.push_back("PRND : "+gears[currentGear]);
            result.push_back("RPS: OFFLINE");
            // result.push_back(std::to_string(mgr.rps).substr(0, 4));
            return result;
        }

        /* Overload increment/decrement operators to perfoerm these ops on PRND enums */
        ClientIf::PRND& operator++(ClientIf::PRND& val)
        {
            const int i = static_cast<int>(val);
            val = static_cast<ClientIf::PRND>(i+1);
            return val;
        }

        ClientIf::PRND& operator--(ClientIf::PRND& val)
        {
            const int i = static_cast<int>(val);
            val = static_cast<ClientIf::PRND>(i-1);
            return val;
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
        PRND ShiftUp(void)
        {
            if(currentGear < ClientIf::PRND_D3) ++currentGear;
            return currentGear;
        }

        PRND ShiftDown(void)
        {
            if(currentGear > ClientIf::PRND_R) --currentGear;
            return currentGear;
        }

        PRND GetGear(void)
        {
            return currentGear;
        }

        PRND SetGear(PRND gear)
        {
            currentGear = gear;
            return currentGear;
        }

    }
}