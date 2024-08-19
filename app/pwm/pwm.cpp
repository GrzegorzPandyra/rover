#include <iostream>
#include <wiringPi.h>

using namespace std;

 

 

int pwm_init(){
    cout << "PWM module init" << endl;
    return 0;

}

void pwm_on(){
    pwmWrite(5, HIGH);
}
void pwm_off(){
    pwmWrite(5, LOW);
}