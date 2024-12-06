/**
 * @file i2c_device.cpp
 * @author Grzegorz Pandyra
 * @brief Base class for i2c device
 * @copyright Copyright (c) 2024
 */
#include "i2c_device.hpp"
#include "../../drv/i2c/i2c_if.hpp"

I2C_Device::I2C_Device(const int8_t addr)
                 /* Initialization list */ :
                m_I2C_ADDR(addr)
{ 
    m_status = INIT;
}

I2C_Device::~I2C_Device(){
    /* Destructor body */
}

void I2C_Device::init(){
    m_fd = i2c::register_node(m_I2C_ADDR);
    if(m_fd == i2c::FILE_DESCRIPTOR_ERROR){
        m_status = ERROR;
    } else {
        m_status = CONNECTED;
    }
}

void I2C_Device::run(void){
    switch (m_status){
    case CONNECTED:
        break;
    
    case INIT: /* Fallthrough */
    case ERROR: /* Fallthrough */
    default:
        /* Do nothing */
        break;
    }
}