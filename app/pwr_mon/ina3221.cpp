#include "ina3221.hpp"
#include "../../drv/i2c/i2c_if.hpp"
#include "../ui/ui_logging.hpp"

/************************************************
 *             PUBLIC CLASS MEMBERS
 ************************************************/

INA3221::INA3221(const int8_t addr)
                 /* Initialization list */ :
                I2C_Device(addr)
{ 

}

INA3221::~INA3221(){
    /* Destructor body */
}

INA3221::Status INA3221::init(uint16_t cfg = 0xFFFF){
    if(cfg == 0xFFFF)
        cfg = m_DEFAULT_CONFIG;
    I2C_Device::init();
    set_config(cfg);
    return selfcheck();
}

float INA3221::read_bus_voltage(INA3221::RegisterID reg){
    uint16_t voltage = INA3221::read_register(reg);
    /* 3 LSB are reserved and irrelevant, see INA3221 datasheet */
    voltage >>= 3;
    float result = (float) voltage;
    return (result * m_BUS_VOLTAGE_PRECISION_V);
}

int16_t INA3221::read_shunt_voltage(INA3221::RegisterID reg){
    return INA3221::read_register(reg);
}

uint16_t INA3221::read_die_id(){
    return INA3221::read_register(REG_ID_DIE_ID);
}

uint16_t INA3221::read_mfg_id(){
    return INA3221::read_register(REG_ID_MFG_ID);
}

void INA3221::reset(){
    I2C_Device::m_status = I2C_Device::Status::INIT;
    i2c::write_reg16(m_fd, REG_ID_CONFIG, ((1<<CFG_RESET)>>8));
    init();
}

void INA3221::set_config(uint16_t cfg){
    /* Data is received in reversed order */
    cfg = (cfg<<8) | (cfg>>8);
    i2c::write_reg16(m_fd, REG_ID_CONFIG, cfg);
}

/************************************************
 *             PRIVATE CLASS MEMBERS
 ************************************************/

uint16_t INA3221::read_register(INA3221::RegisterID reg){
    uint16_t result = UINT16_MAX;
    result = (uint16_t) i2c::read_reg16(m_fd, reg);
    /* Data is received in reversed order */
    result = (result<<8) | (result>>8);
    return result;
}

INA3221::Status INA3221::selfcheck(){
    if(read_die_id() != m_INA3221_DIE_ID)
        return STATUS_DIE_ID_ERROR;
    if(read_mfg_id() != m_INA3221_MFG_ID)
        return STATUS_MFG_ID_ERROR;
    return STATUS_OK;
}