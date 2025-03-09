#include <iostream>
#include <string>
#include <vector>
#include <mutex>
#include "if/SWC_Veh_ClientIf.hpp"
#include "if/SWC_Veh_SysIf.hpp"
#include "if/SWC_Logger_ClientIf.hpp"
#include "if/SWC_ThreadMgr_ClientIf.hpp"
#include "cfg/VehCfg.hpp"


namespace SWC_Veh
{
    namespace 
    {
        void Run(void);
        SWC_Types::SWC swcData = {Run, VEH_CFG_SWC_SYS_TYPE, VEH_CFG_SWC_NAME};

        void Run(void)
        {
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
            INFO(VEH_CFG_SWC_NAME "SWC init complete");
            return SWC_Types::STATUS_OK;
        }
    }

    namespace ClientIf
    {

    }
}