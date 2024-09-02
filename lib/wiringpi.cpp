#include <wiringPi.h>
#include "../app/ui/ui_logging.hpp"
#include "wiringpi.hpp"

void wiringpi::init(void){
    wiringPiSetupGpio();
    /* PWM setup
     * pwmSetClock - clock at 50kHz (20us tick)
     * pwmSetRange - range at 2000 ticks (20ms)
     * */
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock(192);
    pwmSetRange(1024);
    LOG("LIB [wiringpi] init\n");
}
