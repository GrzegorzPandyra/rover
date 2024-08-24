#ifndef OS_CFG_H
#define OS_CFG_H
#include <string>
#include "os_task.hpp"

/* Add relevant includes here */
#include "../app/dummy_app/dummy_app.hpp"
#include "../app/input_if/input_if.hpp"

#define OS_TASK_INIT_LIST() /* Add relevant function calls below */\
                            dummy_app::dummy_app_init(); \
                            input_if::input_if_init();

#define OS_TASK_1_MS_LIST() /* Add relevant function calls below */\
                            input_if::input_if_run();

#define OS_TASK_5_MS_LIST() /* Add relevant function calls below */\
                            /* Dummy_call() */

#define OS_TASK_10_MS_LIST() /* Add relevant function calls below */\
                            /* Dummy_call() */

#define OS_TASK_100_MS_LIST() /* Add relevant function calls below */\
                            /* Dummy_call() */

#define OS_TASK_250_MS_LIST() /* Add relevant function calls below */\
                            dummy_app::dummy_app_run2();

#define OS_TASK_1000_MS_LIST() /* Add relevant function calls below */\
                            dummy_app::dummy_app_run();

namespace os_cfg{
    enum Task_Type {
        INIT = 0u,
        CYCLIC = 1u,
        STANDARD = 2u
    };

    struct Task_T {
        const std::string NAME;
        const Task_Type TYPE;
        const uint16_t CYCLE_TIME_MS;
        void (*function)(void); 
    };

    const Task_T OS_TASKS[] = {
        {"OS_TASK_INIT",    INIT,     0u,    os_task::Task_Init    },
        {"OS_TASK_1_MS",    CYCLIC,   1u,    os_task::Task_1ms     },
        {"OS_TASK_5_MS",    CYCLIC,   5u,    os_task::Task_5ms     },
        {"OS_TASK_10_MS",   CYCLIC,   10u,   os_task::Task_10ms    },
        {"OS_TASK_100_MS",  CYCLIC,   100u,  os_task::Task_100ms   },
        {"OS_TASK_250_MS",  CYCLIC,   250u,  os_task::Task_250ms   },
        {"OS_TASK_1000_MS", CYCLIC,   1000u, os_task::Task_1000ms  }
    };

    const uint8_t NUM_TASKS = sizeof(OS_TASKS)/sizeof(OS_TASKS[0u]);
}


#endif /* OS_CFG_H */