#include <iostream>
#include <queue>
#include <mutex>
#include "Logger_ClientIf.hpp"
#include "Logger_SysIf.hpp"
#include "ThreadMgr_ClientIf.hpp"
#include "LoggerCfg.hpp"
#include "NCurses.hpp"

namespace SWC::Logger
{
    namespace 
    {
        void Run(void);

        struct LoggingBuffer
        {
            std::queue<std::string> buff;
            std::mutex mtx;
        };
        
        SWC::Types::SwcContext loggerCtx =
        {
            SWC::Logger::Cfg::SWC_NAME, 
            SWC::Logger::Cfg::SWC_SYSTEM_TYPE,
            SWC::Types::INIT,
            Run
        };
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
        using namespace GlobalTypes;

        CallResult Stop(void)
        {
            return CALL_OK;
        }
    
        CallResult Init(void)
        {
            SWC::ThreadMgr::ClientIf::RegisterSWC(&loggerCtx);
            std::string log(SWC::Logger::Cfg::SWC_NAME);
            log += "SWC init complete";
            INFO(log);
            return CALL_OK;
        }
    }

    namespace ClientIf
    {
        void Log(LogType lt, std::string s, std::string filepath, int line)
        {
            if(logBuff.buff.size() <= LOGGER_CFG_SWC_MAX_LOGS)
            {
                std::lock_guard<std::mutex> mtx(logBuff.mtx);
                std::string str = filepath+":"+std::to_string(line);
                while(str.length() < LOGGER_CFG_MESSAGE_MARGIN) str.append(" ");
                logBuff.buff.push(str+s+"\n");
            }
        }
    }
}