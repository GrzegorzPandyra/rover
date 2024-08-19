#include <iostream>
#include <unistd.h>  
#include "../pwm/pwm.h"
#include <wiringPi.h>
#include <softPwm.h> 

const uint8_t LEFT_WHEEL_PWM_PIN = 13u; //CALIB
const uint8_t RIGHT_WHEEL_PWM_PIN = 12u; //CALIB

const uint8_t DC_MOTOR_DRV_1_A = 27u; //CALIB
const uint8_t DC_MOTOR_DRV_1_B = 22u; //CALIB
const uint8_t DC_MOTOR_DRV_1_PWM = 17u; //CALIB

const uint8_t DC_MOTOR_DRV_2_A = 20u; //CALIB
const uint8_t DC_MOTOR_DRV_2_B = 16u; //CALIB
const uint8_t DC_MOTOR_DRV_2_PWM = 21u; //CALIB

const uint8_t MIN_PWM_VALUE = 135u; //CALIB
const uint8_t MAX_PWM_VALUE = 205u; //CALIB
const uint8_t PWM_INCREMENT_STEP = 5u;
const uint8_t PWM_DEFAULT_VALUE = (MAX_PWM_VALUE - MIN_PWM_VALUE)/2 + MIN_PWM_VALUE;
 
const char SYSTEM_TERMINATE_CHAR = '.'; //CALIB

const char HEAD_LIGHT_PIN = 26u; //CALIB



 

int main()
{
    std::cout << "Rover control program started" << std::endl;

    wiringPiSetupGpio();

    pinMode(LEFT_WHEEL_PWM_PIN, PWM_OUTPUT);
    pinMode(RIGHT_WHEEL_PWM_PIN, PWM_OUTPUT);
    pinMode(DC_MOTOR_DRV_1_A, OUTPUT);
    pinMode(DC_MOTOR_DRV_1_B, OUTPUT);
    pinMode(DC_MOTOR_DRV_1_PWM, OUTPUT);
    pinMode(DC_MOTOR_DRV_2_A, OUTPUT);
    pinMode(DC_MOTOR_DRV_2_B, OUTPUT);
    pinMode(DC_MOTOR_DRV_2_PWM, OUTPUT);
    pinMode(HEAD_LIGHT_PIN, OUTPUT);

    digitalWrite(DC_MOTOR_DRV_1_PWM, LOW);
    digitalWrite(DC_MOTOR_DRV_2_PWM, LOW);
    digitalWrite(HEAD_LIGHT_PIN, LOW);
    
    /* PWM setup
     * pwmSetClock - clock at 50kHz (20us tick)
     * pwmSetRange - range at 2000 ticks (20ms)
     * */
    pwmSetMode(PWM_MODE_MS);
    pwmSetClock(192);
    pwmSetRange(1024);
    pwmWrite(LEFT_WHEEL_PWM_PIN,  PWM_DEFAULT_VALUE);
    pwmWrite(RIGHT_WHEEL_PWM_PIN, PWM_DEFAULT_VALUE);
    pwmWrite(HEAD_LIGHT_PIN, 0);
    
    softPwmCreate(DC_MOTOR_DRV_1_PWM, MIN_PWM_VALUE, MAX_PWM_VALUE);
    softPwmCreate(HEAD_LIGHT_PIN, 0, 100);

    uint8_t steering_system_pwm = PWM_DEFAULT_VALUE;
    uint8_t motor_speed_pwm = 0;
    uint8_t head_light_pwm = 0;
    char input_char;

    system("stty raw -echo");

    while(1)
    {
        std::cin  >> input_char;
        std::cout << std::endl;

        switch (input_char)
        {
        case 'a':
        case 'A':
            if(steering_system_pwm + PWM_INCREMENT_STEP <= MAX_PWM_VALUE)
            {
                steering_system_pwm += PWM_INCREMENT_STEP;
            }
            else
            {
                steering_system_pwm = MAX_PWM_VALUE;
            }
            break;
        case 'd':
        case 'D':
            if(steering_system_pwm - PWM_INCREMENT_STEP >= MIN_PWM_VALUE)
            {
                steering_system_pwm -= PWM_INCREMENT_STEP;
            }
            else
            {
                steering_system_pwm = MIN_PWM_VALUE;
            }
            break;
        case 'w':
        case 'W':
            digitalWrite(DC_MOTOR_DRV_1_A, HIGH);
            digitalWrite(DC_MOTOR_DRV_1_B, LOW);
            digitalWrite(DC_MOTOR_DRV_2_A, HIGH);
            digitalWrite(DC_MOTOR_DRV_2_B, LOW);
            break;
        case 's':
        case 'S':
            digitalWrite(DC_MOTOR_DRV_1_A, LOW);
            digitalWrite(DC_MOTOR_DRV_1_B, HIGH);
            digitalWrite(DC_MOTOR_DRV_2_A, LOW);
            digitalWrite(DC_MOTOR_DRV_2_B, HIGH);
            break;
        case '1':
            if(motor_speed_pwm + PWM_INCREMENT_STEP <= MAX_PWM_VALUE)
            {
                motor_speed_pwm += PWM_INCREMENT_STEP;
            }
            else
            {
                motor_speed_pwm = MAX_PWM_VALUE;
            }
            break;
        case '2':
            if(motor_speed_pwm - PWM_INCREMENT_STEP >= MIN_PWM_VALUE)
            {
                motor_speed_pwm -= PWM_INCREMENT_STEP;
            }
            else
            {
                motor_speed_pwm = MIN_PWM_VALUE;
            }
            break;
        case 'o':
        case 'O':
            if(head_light_pwm + PWM_INCREMENT_STEP <= 100)
            {
                head_light_pwm += PWM_INCREMENT_STEP;
            }
            else
            {
                head_light_pwm = 100;
            }
            break;
        case 'p':
        case 'P':
            if(head_light_pwm - PWM_INCREMENT_STEP >= 0)
            {
                head_light_pwm -= PWM_INCREMENT_STEP;
            }
            else
            {
                head_light_pwm = 0;
            }
            break;
        default:
            digitalWrite(DC_MOTOR_DRV_1_A, LOW);
            digitalWrite(DC_MOTOR_DRV_1_B, LOW);
            digitalWrite(DC_MOTOR_DRV_2_A, LOW);
            digitalWrite(DC_MOTOR_DRV_2_B, LOW);
            break;
        }

        pwmWrite(LEFT_WHEEL_PWM_PIN, steering_system_pwm);
        pwmWrite(RIGHT_WHEEL_PWM_PIN, steering_system_pwm);
        softPwmWrite(DC_MOTOR_DRV_1_PWM, motor_speed_pwm);
        softPwmWrite(DC_MOTOR_DRV_2_PWM, motor_speed_pwm);
        softPwmWrite(HEAD_LIGHT_PIN, head_light_pwm);

        // std::cout << "\r";
        // std::cout << "SS PWM: " << (unsigned int)steering_system_pwm;
        // std::cout << std::endl;
        // std::cout << "Motor speed PWM " << (unsigned int)motor_speed_pwm;
        std::cout << "headlight PWM: "<< (unsigned int)head_light_pwm <<std::endl;

        if(input_char == SYSTEM_TERMINATE_CHAR) {
            system("stty cooked");
            exit(0);
        }
    }
    return 0;
}   