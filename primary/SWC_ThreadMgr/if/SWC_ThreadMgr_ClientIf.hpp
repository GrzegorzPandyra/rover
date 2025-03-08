#ifndef SWC_THREAD_MANAGER_CLIENTIF_H
#define SWC_THREAD_MANAGER_CLIENTIF_H
#include "SWC_Types.hpp"

namespace SWC_ThreadMgr::ClientIf
{
    SWC_Types::Status RegisterSWC(SWC_Types::SWC* swc);
}

#endif