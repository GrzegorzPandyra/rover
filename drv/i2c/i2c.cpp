#include <iostream>
#include "i2c.hpp"
#include "../ui/ui_logging.hpp"
#include <wiringPiI2C.h>

void i2c::init(void){
    LOG("SWC [i2c] init\n");
}

void i2c::run(void){
}

int8_t i2c::register_node(uint8_t addr){
    char log_buff[UI_DEFAULT_LOG_BUFFER_SIZE] = {0};
    int8_t fd = wiringPiI2CSetup((int32_t)addr);
    if (fd == i2c::FILE_DESCRIPTOR_ERROR) {
        LOG_FORMATED_1(log_buff, "Failed to init I2C communication for %d\n", addr);
    } else {
        LOG_FORMATED_1(log_buff, "Found I2C node %d\n", addr);
    }
    return fd;
}

uint16_t i2c::read_reg16(int32_t fd, int16_t reg){
    return  wiringPiI2CReadReg16(fd, reg);
}

uint8_t i2c::read_reg8(int32_t fd, int16_t reg){
    return  wiringPiI2CReadReg8(fd, reg);
}

void i2c::write_reg8(int32_t fd, int16_t reg, uint8_t data){
    wiringPiI2CWriteReg8(fd, reg, data);
}

void i2c::write_reg16(int32_t fd, int16_t reg, uint16_t data){
    wiringPiI2CWriteReg16(fd, reg, data);
}