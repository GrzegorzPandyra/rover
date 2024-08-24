#include "os_task.hpp"
#include "os_cfg.hpp"

void os_task::Task_Init(void){
    OS_TASK_INIT_LIST()
}

void os_task::Task_1ms(void){
    OS_TASK_1_MS_LIST()
}

void os_task::Task_5ms(void){
    OS_TASK_5_MS_LIST()
}

void os_task::Task_10ms(void){
    OS_TASK_10_MS_LIST()
}

void os_task::Task_100ms(void){
    OS_TASK_100_MS_LIST()
}

void os_task::Task_250ms(void){
    OS_TASK_250_MS_LIST()
}

void os_task::Task_1000ms(void){
    OS_TASK_1000_MS_LIST()
}

