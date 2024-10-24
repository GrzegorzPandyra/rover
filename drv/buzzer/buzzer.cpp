/*
    SWC implements basic buzzer functionality used for events such as init, errors etc.
    Buzzer module implements inverted logic: LOW -> Buzzer ON, HIGH -> Buzzer OFF.
*/
#include <iostream>
#include <vector>
#include "buzzer.hpp"
#include "../../app/ui/ui_logging.hpp"
#include "../../cfg/calib.hpp"
#include <wiringPi.h>
#include <softPwm.h>

using namespace buzzer;

static struct {
    uint16_t counter;
} mgr;

void buzzer::init(void){
    LOG("SWC [buzzer] init\n");
    pinMode(BUZZ_PIN, OUTPUT);
    digitalWrite(BUZZ_PIN, HIGH);
}

void buzzer::buzz(uint16_t time_ms){
    mgr.counter = time_ms;
}

void buzzer::run(void){
    if(mgr.counter > 0){
        digitalWrite(BUZZ_PIN, LOW);
        if(mgr.counter >= BUZZ_TASK_PERIOD_MS){
            mgr.counter -= BUZZ_TASK_PERIOD_MS;
        } else {
            mgr.counter = 0u;
        }
    } else {
        digitalWrite(BUZZ_PIN, HIGH);
    }
}