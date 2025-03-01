#include <stdlib.h>

/* .cpp file included in SWC_ThreadMgr */

extern "C"
{
    void* primary_thread(void * data){
        // Logger::Log("Init", "Primary thread started");
        threadRunner->RunThread(ISWC::ST_PRIMARY);
        while(1);
        return NULL;
    }

    void* secondary_thread(void * data){
        // Logger::Log("Init", "Secondary thread started");
        threadRunner->RunThread(ISWC::ST_SECONDARY);;
        while(1);
        return NULL;
    }

    void* auxiliary_thread(void * data){
        // Logger::Log("Init", "Auxiliary thread started");
        threadRunner->RunThread(ISWC::ST_AUXILIARY);
        while(1);
        return NULL;
    }

    void* diagnostic_thread(void * data){
        // Logger::Log("Init", "Diagnostic thread started");
        threadRunner->RunThread(ISWC::ST_DIAGNOSTIC);
        while(1);
        return NULL;
    }
}