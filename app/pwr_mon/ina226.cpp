#include "ina226.hpp"
#include "../../drv/i2c/i2c_if.hpp"
#include "../ui/ui_logging.hpp"

INA226::INA226(const int8_t addr)
                 /* Initialization list */ :
                I2C_Device(addr)
{ 
}

INA226::~INA226(){
    /* Destructor body */
}

void INA226::init(){
    I2C_Device::init();
    i2c::write_reg8(m_fd, m_SHUNT_REGISTER_ID, 0x00);
}

int16_t INA226::read_bus_voltage(){
    int16_t result;
    result = (int16_t)(((float)INA226::read_register(m_BUS_REGISTER_ID)) * m_BUS_VOLTAGE_PRECISION_V);
    return result;
}

int16_t INA226::read_shunt_voltage(){
    return INA226::read_register(m_SHUNT_REGISTER_ID);
}

int16_t INA226::read_register(INA226::RegisterID reg){
    int16_t result = INA226::DataStatus::ERROR;
    switch (m_status){
    case I2C_Device::Status::CONNECTED:
        result = (int16_t) i2c::read_reg16(m_fd, reg);
        break;
    case I2C_Device::Status::INIT: /* Fallthrough */
    case I2C_Device::Status::ERROR: /* Fallthrough */
    default:
        /* Do nothing */
        break;
    }
    return result;
}