#ifndef AM1805_I2C_H
#define AM1805_I2C_H

#include <stdint.h>

typedef struct
{
    void (*i2c_write)(uint8_t reg, uint8_t *data, uint8_t size);
    int (*i2c_read)(uint8_t reg, uint8_t *data, uint8_t size);
} am1805_i2c_ops_t;

void am1805_set_i2c_spec(am1805_i2c_ops_t *ops);

int am1805_i2c_read_reg(uint8_t reg, uint8_t *data, uint8_t size);
int am1805_i2c_write_reg(uint8_t reg, uint8_t *data, uint8_t size);

#endif // AM1805_I2C_H