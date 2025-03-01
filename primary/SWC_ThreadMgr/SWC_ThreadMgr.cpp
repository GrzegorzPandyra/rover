#include <iostream>
#include <vector>
#include "cfg/threads.hpp"
#include "subc/ThreadCreator.hpp"
#include "subc/SWCRegistrator.hpp"
#include "subc/ThreadRunner.hpp"

namespace SWC_ThreadMgr
{

std::vector<ISWC*> masterSWCRegister;

ThreadCreator<THREAD_MGR_CFG_NUM_THREADS> *threadCreator;
ThreadRunner *threadRunner;
SWCRegistrator *swcRegistrator;

bool Init()
{
    /* Threads need to be created last to avoid accesing uninitialized pointers */
    threadRunner    = new ThreadRunner(masterSWCRegister);
    swcRegistrator  = new SWCRegistrator(masterSWCRegister);
    threadCreator   = new ThreadCreator<THREAD_MGR_CFG_NUM_THREADS>();
    return true;
}

/* Explicitly include implementation of C-style thread functions to give access to threadRunner object */
#include "threads.cpp"

}