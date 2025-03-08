#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include "threadpool.hpp"
#include "threadrunner.hpp"
#include "SWC_Logger_ClientIf.hpp"

using namespace SWC_Logger::ClientIf;

extern "C"
{
    void* primary_thread(void * data);
    void* secondary_thread(void * data);
    void* auxiliary_thread(void * data);
    void* diagnostic_thread(void * data);
}

namespace SWC_ThreadMgr::ThreadPool {
    ThreadPoolArray threadPoolArray = {THREAD_MGR_CFG_THREAD_LIST};
    
    void CreateThreads(void)
    {
        pthread_t pid = 0;
        int status;
        for(auto& th : threadPoolArray)
        {
            status = pthread_create(&pid, NULL, th, NULL);
            if(0 != status)
            {
                ERROR("Failed to create thread - Init failed");
            } 
            else
            {
                INFO("Created thread");
            }
        }
        INFO("Created all threads");
    }

    ThreadPoolArray& GetThreadPool(void)
    {
        return threadPoolArray;
    }

}

extern "C"
{
    void* primary_thread(void * data){
        INFO("Primary thread started");
        SWC_ThreadMgr::ThreadRunner::RunThread(SWC_Types::ST_PRIMARY);
        while(1);
        return NULL;
    }

    void* secondary_thread(void * data){
        INFO("Secondary thread started");
        SWC_ThreadMgr::ThreadRunner::RunThread(SWC_Types::ST_SECONDARY);
        while(1);
        return NULL;
    }

    void* auxiliary_thread(void * data){
        INFO("Auxiliary thread started");
        SWC_ThreadMgr::ThreadRunner::RunThread(SWC_Types::ST_AUXILIARY);
        while(1);
        return NULL;
    }

    void* diagnostic_thread(void * data){
        INFO("Diagnostic thread started");
        SWC_ThreadMgr::ThreadRunner::RunThread(SWC_Types::ST_DIAGNOSTIC);
        while(1);
        return NULL;
    }
}