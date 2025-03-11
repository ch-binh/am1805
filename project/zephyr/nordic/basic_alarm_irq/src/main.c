/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>

#include <zephyr/sys/printk.h>

#include "am1805_i2c.h"
#include "am1805.h"
#include "am1805_reg.h"
#include "hal_i2c.h"

#define SLEEP_TIME_MS 1000

extern struct i2c_dt_spec dev_i2c;

void am1805_com_init(void)
{
	am1805_i2c_ops_t ops = {
		.i2c_write = hal_i2c_write_reg,
		.i2c_read = hal_i2c_read_reg};
	am1805_set_i2c_spec(&ops);
}

void am1805_print_chip_id(void)
{
	chip_id_t chip_id; // should be 6149 (0x1805)
	am1805_get_chip_id(&chip_id);
	printk("_______________________________\n");
	printk("id:\t %04X\ 
		\nrev_major:\t %d\
		\nrev_minor:\t %d\
		\nlot:\t %04X\
		\nuid:\t %04X\
		\nwafer:\t %d\n",
		   chip_id.id, chip_id.rev_major, chip_id.rev_minor,
		   chip_id.lot, chip_id.uid, chip_id.wafer);
}

int main(void)
{
	datetime_t time;

	hal_i2c_init();
	am1805_com_init();
	am1805_init_reg();
	am1805_print_chip_id();

	// ring an alarm every 1 minutes @ 5 seconds mark
	am1805_init_alarm(&ALARM_DATETIME_INIT(0x00, 0x05, 0x80, 0x80, 0x80, 0x80, 0x80), RPT_MIN);

	while (1)
	{
		am1805_get_datetime(&time);
		printk("%d:%d:%d:%d\n",
			   time.time.hours, time.time.minutes,
			   time.time.seconds, time.time.hundredths);

		if (am1805_get_sts(STS_ALAM))
		{
			printk("Alarm is triggered \n");
		}

		k_msleep(SLEEP_TIME_MS);
	}
}