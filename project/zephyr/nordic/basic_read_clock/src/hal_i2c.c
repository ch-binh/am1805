#include "hal_i2c.h"

struct i2c_dt_spec dev_i2c = I2C_DT_SPEC_GET(I2C_NODE);

int hal_i2c_init(void)
{
    if (!device_is_ready(dev_i2c.bus))
    {
        return -1;
    }
    return 0;
}

int hal_i2c_deinit(void)
{
    return 0;
}
void hal_i2c_write_reg(uint8_t reg, uint8_t *data, uint8_t size)
{
    i2c_write_dt(&dev_i2c, data, size);
}


int hal_i2c_read_reg(uint8_t reg, uint8_t *data, uint8_t size)
{
    return i2c_burst_read_dt(&dev_i2c, reg, data, size);
}
