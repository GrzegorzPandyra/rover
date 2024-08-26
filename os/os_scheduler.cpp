#include <iostream>
#include "os_scheduler.hpp"
#include "os_cfg.hpp"
#include <chrono>
#include "../app/ui/ui_logging.hpp"

using namespace os_scheduler;

static unsigned long long os_init_time = 0u;
static unsigned long long os_time = 0u;
static unsigned long long os_time_prev = 0u;

OS_Scheduler_Status_T os_scheduler::Init(void){
    using namespace std::chrono;
    os_init_time = (uint64_t)duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();

    for(uint8_t i = 0u; i<os_cfg::NUM_TASKS; i++){
        if(os_cfg::OS_TASKS[i].TYPE == os_cfg::INIT){
            os_cfg::OS_TASKS[i].function();
        }
    }
    LOG("OS scheduler initialization successful\n");
    return OS_SCHDLR_INITIALIZED;
}

void os_scheduler::Run(void){
    using namespace std::chrono;
    os_time = (uint64_t)duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() - os_init_time;

    /* Check if loop was executed this cycle */
    if(os_time_prev < os_time){
        using namespace os_cfg;
        /* Execute scheduled tasks */
        for(uint8_t i = 0u; i<NUM_TASKS; i++){
            if((OS_TASKS[i].TYPE == CYCLIC) && ((os_time % (unsigned long long)(OS_TASKS[i].CYCLE_TIME_MS)) == 0uLL)) {
                OS_TASKS[i].function();
            }
        }
        os_time_prev = os_time;
    }
}

