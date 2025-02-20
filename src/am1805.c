#include "../inc/am1805.h"
#include "../inc/am1805_i2c.h"
#include "../inc/am1805_reg.h"

/*======================== HANDY FUNCTIONS ===========================*/

uint8_t am1805_get_datetime(datetime_t *t)
{
    am1805_get_time(t);
    am1805_get_date(t);
    return 0;
}

uint8_t am1805_get_time(datetime_t *t)
{
    uint8_t size = 4;
    uint8_t val[size];

    am1805_i2c_read_reg(REG_HUNDREDTHS, val, size);

    t->time.hundredths = bcd2dec(val[0]);
    t->time.seconds = bcd2dec(val[1]);
    t->time.minutes = bcd2dec(val[2]);
    t->time.hours = bcd2dec(val[3]);

    return 0;
}

uint8_t am1805_get_date(datetime_t *t)
{
    uint8_t size = 4;
    uint8_t val[size];

    am1805_i2c_read_reg(REG_DATE, val, size);

    t->date.date = bcd2dec(val[0]);
    t->date.months = bcd2dec(val[1]);
    t->date.years = bcd2dec(val[2]);
    t->date.weekdays = bcd2dec(val[3]);

    return 0;
}

/*======================== GET DATA FUNCTIONS ===========================*/

/* REG 0x00 */
uint8_t am1805_get_hundredths(void)
{
    uint8_t size = 1;
    uint8_t val[size];

    am1805_i2c_read_reg(REG_HUNDREDTHS, val, size);

    return bcd2dec(val[0]);
}

/* REG 0x01 */
uint8_t am1805_get_seconds(void)
{
    uint8_t size = 1;
    uint8_t val[size];

    am1805_i2c_read_reg(REG_SECONDS, val, size);

    return bcd2dec(val[0]);
}
/* REG 0x02 */
uint8_t am1805_get_minutes(void)
{
    uint8_t size = 1;
    uint8_t val[size];

    am1805_i2c_read_reg(REG_MINUTES, val, size);

    return bcd2dec(val[0]);
}

/* REG 0x03*/
uint8_t am1805_get_hours_24(void)
{
    uint8_t size = 1;
    uint8_t val[size];

    am1805_i2c_read_reg(REG_HOURS_24, val, size);

    return bcd2dec(val[0]);
}

/* REG 0x28 */
int am1805_get_chip_id(chip_id_t *chip_id)
{
    uint8_t read_data[7];

    am1805_i2c_read_reg(REG_ID0, read_data, 7);
    chip_id->id = (((uint16_t)read_data[0]) << 8) | (read_data[1]);
    chip_id->rev_major = (read_data[2] >> 3 & 0x1F);
    chip_id->rev_minor = read_data[2] & 0x07;
    chip_id->lot = ((read_data[4] & 0x80) << 2) | ((read_data[6] & 0x80) << 1) | read_data[3];
    chip_id->uid = ((read_data[4] & 0x7F) << 8) | read_data[5];
    chip_id->wafer = (read_data[6] >> 2) & 0x7C;
    return 0;
}

/*======================== COMMON FUNCTIONS ===========================*/

uint8_t bcd2dec(uint8_t val)
{
    return ((val >> 4) & 0x0F) * 10 + (val & 0x0F);
}