#include "../inc/am1805.h"

/*======================== HANDY FUNCTIONS ===========================*/

int am1805_init_reg(void)
{
    am1805_clear_reg(REG_OSC_STS); // cant clear them all
    am1805_clear_reg(REG_CTRL1);
    am1805_cfg_ctrl1(OSC_OUTB_EN | CTRL1_OUT_EN); // SET OUTB bit (pull PSW up)

    return 0;
}

int am1805_set_lp(void)
{
    am1805_clear_reg(REG_CTRL2); // clear all interrupt pin out
    am1805_cfg_int_msk(0x60);    // set interrupt mode to 1/4 seconds
    am1805_cfg_sqw(0x7F);        // disable sqw
    am1805_cfg_tim_ctrl(0x03);   // disable timer
    am1805_cfg_osc_ctrl(OSC_RC);
    return 0;
}

int am1805_init_alarm(alarm_datetime_t *set_time, uint8_t rpt)
{
    am1805_cfg_int_msk(INT_MSK_AL);
    am1805_cfg_ctrl2(FOUT_ALL_IRQ);
    am1805_cfg_tim_ctrl(rpt);
    am1805_set_alarm_time(set_time);
    return 0;
}

int am1805_init_timer(am_timer_t *timer)
{
    am1805_cfg_int_msk(INT_MSK_TIM);
    am1805_cfg_ctrl2(FOUT_ALL_IRQ);
    am1805_clear_reg(REG_TIM_CTRL);
    am1805_cfg_tim_ctrl(TIM_EN | timer->irq_mode | timer->trpt | timer->tfs);
    am1805_set_tim_initval(timer);

    return 0;
}

int am1805_clear_reg(uint8_t reg)
{
    switch (reg)
    {
    case REG_OSC_STS:
    case REG_OSC_CTRL:
        am1805_set_cfg_key(CFGKEY_OSC);
        break;
    case REG_TRICKLE:
        am1805_set_cfg_key(CFGKEY_TRICKLE);
        break;
    case REG_BREF:
        am1805_set_cfg_key(CFGKEY_BREF);
        break;
    case REG_AFCTRL:
        am1805_set_cfg_key(CFGKEY_AFCTRL);
        break;
    case REG_BAT_IOREG:
        am1805_set_cfg_key(CFGKEY_BAT_IOREG);
        break;
    case REG_OUTPUT_CTRL:
        am1805_set_cfg_key(CFGKEY_OUTPUT_CTRL);
        break;
    default:
        break;
    }
    uint8_t rst[1] = {0x00};
    am1805_i2c_write_reg(reg, rst, 1);
    return 0;
}
/*======================== GET DATETIME FUNCTIONS ===========================*/

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

/*======================== ALARM FUNCTIONS ===========================*/

/* REG 0x08 */
uint8_t am1805_set_alarm_time(alarm_datetime_t *set_time)
{
    uint8_t size = 7;
    uint8_t wr_val[size];
    uint8_t *ptr = (uint8_t *)set_time;
    for (int i = 0; i < size; i++)
    {
        wr_val[i] = dec2bcd(ptr[i]);
    }

    am1805_i2c_write_reg(REG_AL_HUNDREDTHS, wr_val, size); // Directly use ptr

    return 0;
}

/* REG 0x08 */
uint8_t am1805_get_alarm(alarm_datetime_t *t)
{
    uint8_t size = 7;
    uint8_t val[size];

    am1805_i2c_read_reg(REG_AL_HUNDREDTHS, val, size); // Directly use ptr
    t->time.hundredths = bcd2dec(val[0]);
    t->time.seconds = bcd2dec(val[1]);
    t->time.minutes = bcd2dec(val[2]);
    t->time.hours = bcd2dec(val[3]);
    t->date.date = bcd2dec(val[4]);
    t->date.months = bcd2dec(val[5]);
    t->date.weekdays = bcd2dec(val[6]);
    return 0;
}

/*======================== CONFIGURATION FUNCTIONS ===========================*/

/* REG 0x0F*/
uint8_t am1805_get_sts(sts_e sts_bit)
{
    uint8_t size = 1;
    uint8_t val[size];
    am1805_i2c_read_reg(REG_STS, val, size);
    if (val[0] & sts_bit)
    {
        // clear the sts bit
        val[0] &= ~sts_bit;
        am1805_i2c_write_reg(REG_STS, val, size);
        return 1;
    }
    return 0;
}

/* REG 0x10 */
uint8_t am1805_cfg_ctrl1(uint8_t val)
{
    uint8_t size = 1;
    uint8_t buffer[size];
    am1805_i2c_read_reg(REG_CTRL1, buffer, size);
    buffer[0] |= val;
    am1805_i2c_write_reg(REG_CTRL1, buffer, size);
    return 0;
}
/* REG 0x11 */
uint8_t am1805_cfg_ctrl2(uint8_t val)
{
    uint8_t size = 1;
    uint8_t buffer[size];
    am1805_i2c_read_reg(REG_CTRL2, buffer, size);
    buffer[0] |= val;
    am1805_i2c_write_reg(REG_CTRL2, buffer, size);
    return 0;
}

/* REG 0x12 */
uint8_t am1805_cfg_int_msk(uint8_t val)
{
    /* Read the current value and add val bit to the reg*/
    uint8_t size = 1;
    uint8_t buffer[size];
    am1805_i2c_read_reg(REG_INT_MSK, buffer, size);
    buffer[0] |= val;
    am1805_i2c_write_reg(REG_INT_MSK, buffer, size);
    return 0;
}

/* REG 0x13 */
uint8_t am1805_cfg_sqw(uint8_t val)
{
    /* Read the current value and add val bit to the reg*/
    uint8_t size = 1;
    uint8_t buffer[size];
    am1805_i2c_read_reg(REG_SQW, buffer, size);
    buffer[0] |= val;
    am1805_i2c_write_reg(REG_SQW, buffer, size);
    return 0;
}

/*========================  SLEEP FUNCTIONS ===========================*/

/* REG 0x17 */
int am1805_cfg_sleep_ctrl(uint8_t val)
{
    uint8_t size = 1;
    uint8_t buffer[size];
    am1805_i2c_read_reg(REG_SLEEP_CTRL, buffer, size);
    buffer[0] |= val;
    am1805_i2c_write_reg(REG_SLEEP_CTRL, buffer, size);

    return 0;
}

/*======================== CONFIGURATION KEY FUNCTIONS ===========================*/

/* REG 0x1F */
int am1805_set_cfg_key(uint8_t key)
{
    am1805_i2c_write_reg(REG_CFG_KEY, &key, 1);
    return 0;
}

/* REG 0x30 */
int am1805_cfg_ctrl_output(uint8_t val)
{
    uint8_t size = 1;
    uint8_t buffer[size];
    am1805_set_cfg_key(CFGKEY_OUTPUT_CTRL);
    am1805_i2c_read_reg(REG_OUTPUT_CTRL, buffer, size);
    buffer[0] |= val;
    am1805_i2c_write_reg(REG_OUTPUT_CTRL, buffer, size);

    return 0;
}

/*======================== OSCILLATOR FUNCTIONS ===========================*/

/* REG 0x1C */
int am1805_cfg_osc_ctrl(uint8_t val)
{
    uint8_t size = 1;
    uint8_t buffer[size];
    am1805_set_cfg_key(CFGKEY_OSC);
    am1805_i2c_read_reg(REG_OSC_CTRL, buffer, size);
    buffer[0] |= val;
    am1805_i2c_write_reg(REG_OSC_CTRL, buffer, size);

    return 0;
}
/* REG 0x1D */
int am1805_cfg_osc_sts(uint8_t val)
{
    uint8_t size = 1;
    uint8_t buffer[size];
    am1805_set_cfg_key(CFGKEY_OSC);
    am1805_i2c_read_reg(REG_OSC_STS, buffer, size);
    buffer[0] |= val;
    am1805_i2c_write_reg(REG_OSC_STS, buffer, size);

    return 0;
}

/*======================== TIMER FUNCTIONS ===========================*/
/* REG 0x18 */
uint8_t am1805_cfg_tim_ctrl(uint8_t val)
{
    uint8_t size = 1;
    uint8_t buffer[size];
    am1805_i2c_read_reg(REG_TIM_CTRL, buffer, size);
    buffer[0] |= val;
    am1805_i2c_write_reg(REG_TIM_CTRL, buffer, size);
    return 0;
}

/* REG 0x19 */
void am1805_get_tim_cd(am_timer_t *timer)
{
    uint8_t size = 1;
    uint8_t buffer[size];
    am1805_i2c_read_reg(REG_TIM_CD, buffer, size);
    timer->cd = buffer[0];
}

/* REG 0x19 */
void am1805_reset_tim_cd(am_timer_t *timer)
{
    uint8_t size = 1;
    uint8_t buffer[size];
    buffer[0] = timer->init_val;
    am1805_i2c_write_reg(REG_TIM_CD, buffer, size);
}

/* REG 0x1A */
void am1805_set_tim_initval(am_timer_t *timer)
{
    uint8_t size = 1;
    uint8_t buffer[size];
    buffer[0] = timer->init_val;
    am1805_i2c_write_reg(REG_TIM_INITVAL, buffer, size);
    am1805_i2c_read_reg(REG_TIM_CD, buffer, size);
    if (buffer[0] == 0)
    {
        am1805_reset_tim_cd(timer);
    }
}

/*======================== GET DATA FUNCTIONS ===========================*/
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

uint8_t am1805_get_datetime(datetime_t *t)
{
    am1805_get_time(t);
    am1805_get_date(t);
    return 0;
}

int am1805_set_datetime(datetime_t *t)
{
    uint8_t size = 7;
    uint8_t wr_val[size];
    uint8_t *ptr = (uint8_t *)t;
    for (int i = 0; i < size; i++)
    {
        wr_val[i] = dec2bcd(ptr[i]);
    }

    am1805_i2c_write_reg(REG_HUNDREDTHS, wr_val, size); // Directly use ptr

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

/*======================== COMMON FUNCTIONS ===========================*/

uint8_t bcd2dec(uint8_t val)
{
    return ((val >> 4) & 0x0F) * 10 + (val & 0x0F);
}

uint8_t dec2bcd(uint8_t val)
{
    uint8_t tens = (val * 205) >> 11; // 11 bit = 2048 -> 205/2024 almost but larger than 1, make it ~1/10
    uint8_t ones = val - (tens * 10);

    return (tens << 4) | ones;
}