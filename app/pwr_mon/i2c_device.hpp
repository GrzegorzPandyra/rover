#ifndef I2C_DEVICE_H
#define I2C_DEVICE_H

#include <stdint.h>

class I2C_Device {
    public:
        I2C_Device(const int8_t addr);
        ~I2C_Device();
        void init();
        virtual void run(void);
    protected:
        int32_t m_fd;
        enum Status {
            INIT,
            CONNECTED,
            ERROR
        } m_status;
        const int8_t m_I2C_ADDR;
};

#endif