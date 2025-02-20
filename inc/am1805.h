#ifndef AM1805_H
#define AM1805_H

#include <stdint.h>
#include <stddef.h>

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

/*======================== HANDY FUNCTIONS ===========================*/
uint8_t am1805_get_datetime(datetime_t *t);
uint8_t am1805_get_time(datetime_t *t);
uint8_t am1805_get_date(datetime_t *t);

/*======================== GET DATA FUNCTIONS ===========================*/
/* REG 0x00 */
uint8_t am1805_get_hundredths(void);
/* REG 0x01 */
uint8_t am1805_get_seconds(void);
int am1805_get_chip_id(chip_id_t *chip_id);

uint8_t bcd2dec(uint8_t val);

#endif // AM1805_H