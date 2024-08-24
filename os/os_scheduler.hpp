#ifndef OS_SCHEDULER_H
#define OS_SCHEDULER_H

namespace os_scheduler {
    enum OS_Scheduler_Status_T {
        OS_SCHDLR_UNINITIALIZED = 0,
        OS_SCHDLR_INITIALIZED,
        OS_SCHDLR_INIT_FAILED
    };

    OS_Scheduler_Status_T Init(void);
    void Run(void);
}

#endif /* OS_SCHEDULER_H */