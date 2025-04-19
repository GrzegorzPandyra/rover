#ifndef SWC_THREAD_MANAGER_CLIENT_IF_H
#define SWC_THREAD_MANAGER_CLIENT_IF_H
#include "SwcTypes.hpp"
#include "GlobalTypes.hpp"

namespace SWC::ThreadMgr::ClientIf
{
    GlobalTypes::CallResult RegisterSWC(SWC::Types::SwcContext* ctx);
}

#endif