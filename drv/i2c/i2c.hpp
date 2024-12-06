/**
 * @file i2c.hpp
 * @author Grzegorz Pandyra
 * @brief This component is a wrapper for underlaying i2c library.
 * @date 2024-11-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#ifndef I2C_HPP
#define I2C_HPP
#include <stdint.h>

namespace i2c{
    const int8_t FILE_DESCRIPTOR_ERROR = -1;

    void init(void);
    void run(void);
    int8_t register_node(uint8_t addr);
    uint16_t read_reg16(int32_t fd, int16_t reg);
    uint8_t read_reg8(int32_t fd, int16_t reg);
    void write_reg8(int32_t fd, int16_t reg, uint8_t data);
    void write_reg16(int32_t fd, int16_t reg, uint16_t data);
}
#endif