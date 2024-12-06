#ifndef CLASS_INA3221_H
#define CLASS_INA3221_H

#include <stdint.h>
#include "i2c_device.hpp"

class INA3221 : public I2C_Device {
    public:
        enum Channel {
            CHANNEL_1,
            CHANNEL_2,
            CHANNEL_3
        };

        INA3221(const int8_t addr);
        ~INA3221();
        void init() override;
        uint16_t read_voltage(Channel ch);

    private:
        const int8_t m_SHUNT_REGISTER_ID_1 = 0x01;
        const int8_t m_SHUNT_REGISTER_ID_2 = 0x03;
        const int8_t m_SHUNT_REGISTER_ID_3 = 0x05;
};

#endif