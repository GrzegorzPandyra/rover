#ifndef CLASS_INA226_H
#define CLASS_INA226_H

#include <stdint.h>
#include "i2c_device.hpp"

class INA226 : public I2C_Device{
    public:
        enum RegisterID {
            REG_ID_CONFIG = 0x00,
            REG_ID_SHUNT = 0x01,
            REG_ID_BUS = 0x02,
            REG_ID_POWER = 0x03,
            REG_ID_CURRENT = 0x04,
            REG_ID_CALIB = 0x05,
            REG_ID_MASK_EN = 0x06,
            REG_ID_ALERT_LIMIT = 0x07,
            REG_ID_MFG_ID = 0xFE,
            REG_ID_DIE_ID = 0xFF
        };
        enum ConfigRegBits {
            CFG_MODE1 = 0,
            CFG_MODE2 = 1,
            CFG_MODE3 = 2,
            CFG_SHUNT_CT0 = 3,
            CFG_SHUNT_CT1 = 4,
            CFG_SHUNT_CT2 = 5,
            CFG_VBUS_CT0 = 6,
            CFG_VBUS_CT1 = 7,
            CFG_VBUS_CT2 = 8,
            CFG_AVG0 = 9,
            CFG_AVG1 = 10,
            CFG_AVG2 = 11,
            CFG_RESET = 15
        };
        enum Status{
            STATUS_OK = 0x00,
            STATUS_DIE_ID_ERROR = 0x01,
            STATUS_MFG_ID_ERROR = 0x02
        };
        INA226(const int8_t addr);
        ~INA226();
        Status init(uint16_t cfg);
        uint16_t read_shunt_voltage();
        float read_bus_voltage();
        uint16_t read_die_id();
        uint16_t read_mfg_id();
        void reset();
        void set_config(uint16_t cfg);
    private:
        uint16_t read_register(RegisterID reg);
        Status selfcheck();
        const float m_BUS_VOLTAGE_PRECISION_V = 0.00125f;
        const int16_t m_INA226_DIE_ID = 0x2260;
        const int16_t m_INA226_MFG_ID = 0x5449;
        const uint16_t m_DEFAULT_CONFIG = 0x4127;
};

#endif