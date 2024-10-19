/*
    SWC implements RPS measurement of main drive shaft.
*/
#include <iostream>
#include <vector>
#include "tacho.hpp"
#include <wiringPi.h>
#include "../ui/ui_logging.hpp"
#include "../../mcal/calib.hpp"

#define PERIOD_1000_MS 1000u

using namespace tacho;

static struct {
    float rps;
    uint16_t tacho_counter;
    uint16_t period;
    bool last_status;
} tacho_mgr;

void tacho::init(void){
    LOG("SWC [tacho] init\n");
    pinMode(TACHO_PIN, INPUT);
}

float tacho::get_speed(void){
    return tacho_mgr.rps;
}

void tacho::run(void){
    bool status = digitalRead(TACHO_PIN);
    if(status != tacho_mgr.last_status){
        tacho_mgr.tacho_counter++;
    }
    tacho_mgr.last_status = status;
    tacho_mgr.period += TACHO_TASK_PERIOD_MS;

    if(tacho_mgr.period == PERIOD_1000_MS){
        tacho_mgr.rps = tacho_mgr.tacho_counter;
        tacho_mgr.tacho_counter = 0u;
        tacho_mgr.period = 0u;
    }
}