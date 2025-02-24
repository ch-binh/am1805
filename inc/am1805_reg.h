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

/* Alarm*/
#define REG_AL_HUNDREDTHS 0x08
#define REG_AL_SECONDS 0x09
#define REG_AL_MINUTES 0x0A
#define REG_AL_HOURS_24 0x0B
#define REG_AL_HOURS_12 0x0B
#define REG_AL_DATE 0x0C
#define REG_AL_MONTHS 0x0D
#define REG_AL_WEEKDAYS 0x0E

/* CONFIGURATION REGISTERS */
#define REG_STS 0x0F
#define REG_CTRL1 0x10
#define REG_CTRL2 0x11
#define REG_INT_MSK 0x12
#define REG_SQW 0x13
/* SLEEP CONTROL REGISTERS */
#define REG_SLEEP_CTRL 0x17

/* OSCILLATOR REGISTERS */
#define REG_OSC_CTRL 0x1C

/* MISCELLANEOUS REGISTERS */
#define REG_CFG_KEY 0x1F

/* Timer REGISTER*/
#define REG_TIM_CTRL 0x18
#define REG_TIM_CD 0x19
#define REG_TIM_INITVAL 0x1A

/* ID REGISTERS */
#define REG_ID0 0x28
#define REG_ID1 0x29
#define REG_ID2 0x2A
#define REG_ID3 0x2B
#define REG_ID4 0x2C
#define REG_ID5 0x2D
#define REG_ID6 0x2E

#define REG_OUTPUT_CTRL 0x30

/*=============== SET VALUE ================*/
#define INT_MSK_DEF 0xE0 // Reset value of INT mask
#define INT_MSK_AL 0x04
#define INT_MSK_TIM 0x08
#define CFG_WRTC 0x01
#define INT_ALAM_EN 0x03
#define INT_TIME_EN 0x14
#define FOUT_ALL_IRQ 0x00

#define TIM_EN 0x80
#define TIM_INT_MODE 0x40
#define TIM_INT_RPT 0x20
#define ALAM_INT_RPT_HS 0x14 // once per seconds
#define TIM_TFS_64HZ  0x01
#define TIM_TFS_1HZ 0x02
#define TIM_TFS_1_64HZ 0x03

#define CFGKEY_OSC 0xA1
#define CFGKEY_SW_RST 0x3C
#define CFGKEY_TRICKLE 0x9D
#define CFGKEY_BREF 0x21
#define CFGKEY_OUTPUT_CTRL 0x9D

#define OSC_RC 0x80 // enable 128Hz RC osc
#define OSC_ACAL 0x40 // enable autocalibration

#endif // AM1805_REG_H