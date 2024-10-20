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
} mgr;

void tacho::init(void){
    LOG("SWC [tacho] init\n");
    pinMode(TACHO_PIN, INPUT);
}

void tacho::run(void){
    bool status = digitalRead(TACHO_PIN);
    if(status != mgr.last_status){
        mgr.tacho_counter++;
    }
    mgr.last_status = status;
    mgr.period += TACHO_TASK_PERIOD_MS;

    if(mgr.period == PERIOD_1000_MS){
        mgr.rps = (float)mgr.tacho_counter/(float)TACHO_NUM_BOARD_SLOTS;
        mgr.tacho_counter = 0u;
        mgr.period = 0u;
    }
}

float tacho::get_speed(void){
    return mgr.rps;
}