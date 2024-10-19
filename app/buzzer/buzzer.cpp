/*
    SWC implements basic buzzer functionality used for events such as init, errors etc.
    Buzzer module implements inverted logic: LOW -> Buzzer ON, HIGH -> Buzzer OFF.
*/
#include <iostream>
#include <vector>
#include "buzzer.hpp"
#include "../ui/ui_logging.hpp"
#include "../../mcal/calib.hpp"
#include <wiringPi.h>
#include <softPwm.h>

using namespace buzzer;

static struct {
    uint16_t counter;
} buzzer_mgr;

void buzzer::init(void){
    LOG("SWC [buzzer] init\n");
    pinMode(BUZZ_PIN, OUTPUT);
    digitalWrite(BUZZ_PIN, HIGH);
}

void buzzer::buzz(uint16_t time_ms){
    buzzer_mgr.counter = time_ms;
}

void buzzer::run(void){
    if(buzzer_mgr.counter > 0){
        digitalWrite(BUZZ_PIN, LOW);
        if(buzzer_mgr.counter >= BUZZ_TASK_PERIOD_MS){
            buzzer_mgr.counter -= BUZZ_TASK_PERIOD_MS;
        } else {
            buzzer_mgr.counter = 0u;
        }
    } else {
        digitalWrite(BUZZ_PIN, HIGH);
    }
}