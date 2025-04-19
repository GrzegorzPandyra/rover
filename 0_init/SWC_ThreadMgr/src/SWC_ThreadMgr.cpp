#include <array>
#include <mutex>
#include "ThreadMgr_ClientIf.hpp"
#include "ThreadMgr_SysIf.hpp"
#include "ThreadContext.hpp"
#include "GlobalTypes.hpp"

using namespace SWC::Types;

namespace SWC::ThreadMgr
{
    namespace
    {
        std::array<ThreadContext, 4> threadPool = {
            ThreadContext(GlobalTypes::PRIMARY,     std::chrono::milliseconds(10)),
            ThreadContext(GlobalTypes::SECONDARY,   std::chrono::milliseconds(10)),
            ThreadContext(GlobalTypes::AUXILIARY,   std::chrono::milliseconds(10)),
            ThreadContext(GlobalTypes::DIAGNOSTIC,  std::chrono::milliseconds(10))
        };
        std::mutex threadPoolMtx;
    }
    
    namespace SysIf
    {
        GlobalTypes::CallResult Init()
        {
            for(auto& th : threadPool) th.StartThread();
            for(auto& th : threadPool) th.GetThread().join();
            return GlobalTypes::CALL_OK;
        }
    }


    namespace ClientIf
    {
        GlobalTypes::CallResult RegisterSWC(SwcContext* ctx)
        {
            using namespace GlobalTypes;
            std::lock_guard<std::mutex> lock(threadPoolMtx);
            auto& thread = threadPool[ctx->systemType];
            thread.AddSwc(ctx);
            return GlobalTypes::CALL_OK;
        }
    }
}