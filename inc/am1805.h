#ifndef AM1805_H
#define AM1805_H

#include <stdint.h>
#include <stddef.h>

/* Helper macros to fill in datetime info */
#define DATETIME_INIT(hund, sec, min, hr, date, month, year, weekday) \
    ((datetime_t){                                                    \
        {hund, sec, min, hr},                                         \
        {date, month, year, weekday}})

/* Helper macros to fill in alarm datetime info */
#define ALARM_DATETIME_INIT(hund, sec, min, hr, date, month, weekday) \
    ((alarm_datetime_t){                                              \
        {hund, sec, min, hr},                                         \
        {date, month, weekday}})

#define TIMER_INIT(tfs, irq_mode, irq_rpt, init_val, cd) \
    ((am_timer_t){                                       \
        tfs, irq_mode, irq_rpt, init_val, cd})

typedef struct
{
    uint16_t id;       // part number
    uint8_t rev_major; // revision major
    uint8_t rev_minor; // revision minor
    uint16_t lot;      // manufacture lot
    uint16_t uid;      // unique id
    uint8_t wafer;     // wafer?
} chip_id_t;

typedef struct
{
    struct
    {
        uint8_t hundredths;
        uint8_t seconds;
        uint8_t minutes;
        uint8_t hours;
    } time;

    struct
    {
        uint8_t date;
        uint8_t months;
        uint8_t years;
        uint8_t weekdays;
    } date;
} datetime_t;

typedef struct
{
    struct
    {
        uint8_t hundredths;
        uint8_t seconds;
        uint8_t minutes;
        uint8_t hours;
    } time;

    struct
    {
        uint8_t date;
        uint8_t months;
        uint8_t weekdays;
    } date;
} alarm_datetime_t;

typedef struct
{
    uint8_t tfs; // timer function select
    uint8_t irq_mode;
    uint8_t irq_rpt;
    uint8_t init_val;
    uint8_t cd;
} am_timer_t;

typedef struct
{

} osc_t;

typedef enum
{
    STS_EX1 = 0x01,  // Set when external trigger is detected on EXT1 pin
    STS_EX2 = 0x02,  // Set when external trigger is detected on WDI pin
    STS_ALAM = 0x04, // Set when enabled AND match with counters
    STS_TIM = 0x08,  // Timer is enabled AND reach zero
    STS_BL = 0x10,   // Battery low
    STS_WDT = 0x20,  // Set when Watchdog timer is enabled AND is triggered
    STS_BAT = 0x40,  // Set when the system switches to the VBAT Power state
    STS_CB = 0x80,   // Century. For leap year calculation, set 1.
    STS_NUM = 8
} sts_e;

/*======================== HANDY FUNCTIONS ===========================*/
int am1805_init_reg(void);
int am1805_set_lp(void);
int am1805_set_alarm(alarm_datetime_t *set_time);
int am1805_set_datetime(datetime_t *t);
int am1805_init_timer(am_timer_t *timer);

/*======================== ALARM FUNCTIONS ===========================*/

/* REG 0x08 */
uint8_t am1805_set_alarm_time(alarm_datetime_t *set_time);
uint8_t am1805_get_alarm(alarm_datetime_t *t);

/*======================== CONFIGURATION FUNCTIONS ===========================*/

/* REG 0x0F*/
uint8_t am1805_get_sts(sts_e sts_reg);
/* REG 0x10 */
uint8_t am1805_cfg_ctrl1(uint8_t val);
/* REG 0x11 */
uint8_t am1805_cfg_ctrl2(uint8_t val);
/* REG 0x12 */
uint8_t am1805_cfg_int_msk(uint8_t val);

/* REG 0x13 */
uint8_t am1805_cfg_sqw(uint8_t val);

/*======================== TIMER FUNCTIONS ===========================*/
/* REG 0x18 */
uint8_t am1805_cfg_tim_ctrl(uint8_t val);
/* REG 0x19 */
void am1805_get_tim_cd(am_timer_t *timer);
void am1805_reset_tim_cd(am_timer_t *timer);
/* REG 0x1A */
void am1805_set_tim_initval(am_timer_t *timer);

/*========================  SLEEP FUNCTIONS ===========================*/
/* REG 0x17 */
int am1805_cfg_sleep_ctrl(uint8_t val);

/*======================== CONFIGURATION KEY FUNCTIONS ===========================*/

/* REG 0x1F */
int am1805_set_cfg_key(uint8_t key);
/* REG 0x30 */
int am1805_cfg_ctrl_output(uint8_t val);
/*======================== OSCILLATOR FUNCTIONS ===========================*/

/* REG 0x1C */
int am1805_cfg_osc_ctrl(uint8_t val);
/*======================== GET DATA FUNCTIONS ===========================*/
/* REG 0x00 */
uint8_t am1805_get_hundredths(void);
/* REG 0x01 */
uint8_t am1805_get_seconds(void);
int am1805_get_chip_id(chip_id_t *chip_id);

uint8_t am1805_get_datetime(datetime_t *t);
uint8_t am1805_get_time(datetime_t *t);
uint8_t am1805_get_date(datetime_t *t);

uint8_t bcd2dec(uint8_t val);
uint8_t dec2bcd(uint8_t val);

#endif // AM1805_H