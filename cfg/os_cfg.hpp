#ifndef OS_CFG_H
#define OS_CFG_H
#include <string>
#include "../app/os/os_task.hpp"

/* Add relevant includes here */
#include "../lib/ncurses.hpp"
#include "../lib/wiringpi.hpp"
#include "../app/ui/ui_input.hpp"
#include "../app/ui/ui_monitor.hpp"
#include "../app/dummy_app/dummy_app.hpp"
#include "../app/veh/veh.hpp"
#include "../drv/light_ctrl/light_ctrl.hpp"
#include "../drv/steer_sys/steer_sys.hpp"
#include "../drv/pwtr/pwtr.hpp"
#include "../drv/fan_ctrl/fan_ctrl.hpp"
#include "../drv/buzzer/buzzer.hpp"
#include "../drv/tacho/tacho.hpp"

#define OS_TASK_INIT_LIST() /* Add relevant function calls below */\
                            ncurses::init(); \
                            wiringpi::init(); \
                            ui_input::init(); \
                            ui_monitor::init(); \
                            light_ctrl::init(); \
                            pwtr::init(); \
                            steer_sys::init(); \
                            dummy_app::dummy_app_init(); \
                            buzzer::init(); \
                            tacho::init(); \
                            veh::init(); \
                            fan_ctrl::init(); \
                            buzzer::buzz(50);

#define OS_TASK_1_MS_LIST() /* Add relevant function calls below */\
                            ui_input::run(); \
                            tacho::run();

#define OS_TASK_5_MS_LIST() /* Add relevant function calls below */\
                            /* Dummy_call() */

#define OS_TASK_10_MS_LIST() /* Add relevant function calls below */\
                            ui_monitor::run(); \
                            pwtr::run(); \
                            fan_ctrl::run(); \
                            steer_sys::run(); \
                            buzzer::run(); \
                            veh::run();
                            // dummy_app::dummy_app_run2();

#define OS_TASK_100_MS_LIST() /* Add relevant function calls below */\
                            light_ctrl::run();
                            

#define OS_TASK_250_MS_LIST() /* Add relevant function calls below */\

#define OS_TASK_500_MS_LIST() /* Add relevant function calls below */\
                            pwtr::expire_pwm();

#define OS_TASK_1000_MS_LIST() /* Add relevant function calls below */\

#define OS_TASK_2000_MS_LIST() /* Add relevant function calls below */\

#define OS_TASK_5000_MS_LIST() /* Add relevant function calls below */\
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
        {"OS_TASK_500_MS",  CYCLIC,   500u,  os_task::Task_500ms   },
        {"OS_TASK_1000_MS", CYCLIC,   1000u, os_task::Task_1000ms  },
        {"OS_TASK_2000_MS", CYCLIC,   2000u, os_task::Task_2000ms  },
        {"OS_TASK_5000_MS", CYCLIC,   5000u, os_task::Task_5000ms  }
    };

    const uint8_t NUM_TASKS = sizeof(OS_TASKS)/sizeof(OS_TASKS[0u]);
}


#endif /* OS_CFG_H */