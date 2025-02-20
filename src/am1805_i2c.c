#include "../inc/am1805_i2c.h"

static am1805_i2c_ops_t i2c_ops;

void am1805_set_i2c_spec(am1805_i2c_ops_t *ops)
{
    i2c_ops = *ops; // Copy the function pointers
}

int am1805_i2c_read_reg(uint8_t reg, uint8_t *data, uint8_t size)
{
    if (i2c_ops.i2c_read)
    {
        return i2c_ops.i2c_read(reg, data, size);
    }
    return -1; // Error: function not set
}

int am1805_i2c_write_reg(uint8_t reg, uint8_t value)
{
    if (i2c_ops.i2c_write)
    {
        i2c_ops.i2c_write(reg, value);
        return 0;
    }
    return -1; // Error: function not set
}