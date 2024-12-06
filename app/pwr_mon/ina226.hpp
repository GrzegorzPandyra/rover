#ifndef CLASS_INA226_H
#define CLASS_INA226_H

#include <stdint.h>
#include "i2c_device.hpp"

class INA226 : public I2C_Device{
    public:
        INA226(const int8_t addr);
        ~INA226();
        void init() override;
        int16_t read_shunt_voltage();
        int16_t read_bus_voltage();
        enum DataStatus {
            ERROR = -1
        };
        enum RegisterID {
            m_SHUNT_REGISTER_ID = 0x01,
            m_BUS_REGISTER_ID = 0x02
        };
    private:
        int16_t read_register(RegisterID reg);
        const float m_BUS_VOLTAGE_PRECISION_V = 0.00125f;
};

#endif