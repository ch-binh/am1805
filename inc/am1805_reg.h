#ifndef AM1805_REG_H
#define AM1805_REG_H

/* TIME and DATE REGISTERS*/
#define REG_HUNDREDTHS 0x00
#define REG_SECONDS 0x01
#define REG_MINUTES 0x02
#define REG_HOURS_24 0x03
#define REG_HOURS_12 0x03
#define REG_DATE 0x04
#define REG_MONTHS 0x05
#define REG_YEARS 0x06
#define REG_WEEKDAYS 0x07

/* ID REGISTERS */
#define REG_ID0 0x28
#define REG_ID1 0x29
#define REG_ID2 0x2A
#define REG_ID3 0x2B
#define REG_ID4 0x2C
#define REG_ID5 0x2D
#define REG_ID6 0x2E

#endif // AM1805_REG_H