#ifndef SWC_THREAD_MANAGER_IF_H
#define SWC_THREAD_MANAGER_IF_H

#include "ISWC.hpp"

namespace SWC_ThreadMgr
{
    bool RegisterSwC(ISWC* swc);
    bool Init();
}

#endif