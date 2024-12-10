#include "ina226.hpp"
#include "../../drv/i2c/i2c_if.hpp"
#include "../ui/ui_logging.hpp"

/************************************************
 *             PUBLIC CLASS MEMBERS
 ************************************************/

INA226::INA226(const int8_t addr)
                 /* Initialization list */ :
                I2C_Device(addr)
{ 
}

INA226::~INA226(){
    /* Destructor body */
}

INA226::Status INA226::init(uint16_t cfg = 0xFFFF){
    if(cfg == 0xFFFF)
        cfg = m_DEFAULT_CONFIG;
    I2C_Device::init();
    set_config(cfg);
    return selfcheck();
}

float INA226::read_bus_voltage(){
    float result = (float) INA226::read_register(REG_ID_BUS);
    return (result * m_BUS_VOLTAGE_PRECISION_V);
}

uint16_t INA226::read_shunt_voltage(){
    return INA226::read_register(REG_ID_SHUNT);
}

uint16_t INA226::read_die_id(){
    return INA226::read_register(REG_ID_DIE_ID);
}

uint16_t INA226::read_mfg_id(){
    return INA226::read_register(REG_ID_MFG_ID);
}

void INA226::reset(){
    I2C_Device::m_status = I2C_Device::Status::INIT;
    i2c::write_reg16(m_fd, REG_ID_CONFIG, ((1<<CFG_RESET)>>8));
    init();
}

void INA226::set_config(uint16_t cfg){
    /* Data is received in reversed order */
    cfg = (cfg<<8) | (cfg>>8);
    i2c::write_reg16(m_fd, REG_ID_CONFIG, cfg);
}

/************************************************
 *             PRIVATE CLASS MEMBERS
 ************************************************/

uint16_t INA226::read_register(INA226::RegisterID reg){
    uint16_t result = (uint16_t) i2c::read_reg16(m_fd, reg);
    /* Data comes in reversed order */
    result = (result<<8) | (result>>8);
    return result;
}

INA226::Status INA226::selfcheck(){
    if(read_die_id() != m_INA226_DIE_ID)
        return STATUS_DIE_ID_ERROR;
    if(read_mfg_id() != m_INA226_MFG_ID)
        return STATUS_MFG_ID_ERROR;
    return STATUS_OK;
}