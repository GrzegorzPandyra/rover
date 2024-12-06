#include "ina3221.hpp"
#include "../../drv/i2c/i2c_if.hpp"

INA3221::INA3221(const int8_t addr)
                 /* Initialization list */ :
                I2C_Device(addr)
{ 

}

INA3221::~INA3221(){
    /* Destructor body */
}

void INA3221::init(){
    I2C_Device::init();
}

uint16_t INA3221::read_voltage(INA3221::Channel ch){
    uint16_t result = UINT16_MAX;
    switch (ch)
    {
    case CHANNEL_1:
        i2c::write_reg16(m_fd, m_SHUNT_REGISTER_ID_1, 0x0000);
        result = i2c::read_reg16(m_fd, m_SHUNT_REGISTER_ID_1);
        break;
    case CHANNEL_2:
        i2c::write_reg16(m_fd, m_SHUNT_REGISTER_ID_2, 0x0000);
        result = i2c::read_reg16(m_fd, m_SHUNT_REGISTER_ID_2);
        break;
    case CHANNEL_3:
        i2c::write_reg16(m_fd, m_SHUNT_REGISTER_ID_3, 0x0000);
        result = i2c::read_reg16(m_fd, m_SHUNT_REGISTER_ID_3);
        break;
    default:
        break;
    }
    return result;
}