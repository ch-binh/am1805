#ifndef HAL_I2C_H
#define HAL_I2C_H

#include <stdint.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/pm/device.h>

#define I2C_NODE DT_NODELABEL(am1805)
extern struct i2c_dt_spec dev_i2c;

int hal_i2c_init(void);
int hal_i2c_deinit(void);

void hal_i2c_write_reg(uint8_t reg, uint8_t *data, uint8_t size);
int hal_i2c_read_reg(uint8_t reg, uint8_t *data, uint8_t size);

#endif // HAL_I2C_H