#include <iostream>
#include <queue>
#include <mutex>
#include "if/SWC_Logger_ClientIf.hpp"
#include "if/SWC_Logger_SysIf.hpp"
#include "if/SWC_ThreadMgr_ClientIf.hpp"
#include "cfg/LoggerCfg.hpp"
#include "if/NCurses.hpp"
namespace SWC_Logger
{
    namespace 
    {
        void Run(void);

        struct LoggingBuffer
        {
            std::queue<std::string> buff;
            std::mutex mtx;
        };
        
        SWC_Types::SWC logger = {Run, LOGGER_CFG_SWC_SYS_TYPE, LOGGER_CFG_SWC_NAME};
        LoggingBuffer logBuff;


        
        void Run(void)
        {
            if(!logBuff.buff.empty())
            {
                std::lock_guard<std::mutex> mtx(logBuff.mtx);
                NCurses::StdPrint(logBuff.buff.front());
                logBuff.buff.pop();
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
            SWC_ThreadMgr::ClientIf::RegisterSWC(&logger);
            INFO(LOGGER_CFG_SWC_NAME "SWC init complete");
            return SWC_Types::STATUS_OK;
        }
    }

    namespace ClientIf
    {
        void Log(LogType lt, std::string s, std::string filepath, int line)
        {
            if(logBuff.buff.size() <= LOGGER_CFG_SWC_MAX_LOGS)
            {
                std::lock_guard<std::mutex> mtx(logBuff.mtx);
                logBuff.buff.push(filepath+":"+std::to_string(line)+"\t"+s+"\n");
            }
        }

        void Log(LogType lt, std::stringstream ss, std::string filepath, int line)
        {
            if(logBuff.buff.size() <= LOGGER_CFG_SWC_MAX_LOGS)
            {
                logBuff.buff.push(filepath+":"+std::to_string(line)+"\t"+ss.str()+"\n");
                std::lock_guard<std::mutex> mtx(logBuff.mtx);
            }
        }
    }
}