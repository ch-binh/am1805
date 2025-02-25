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
#define REG_OSC_STS 0x1D

/* MISCELLANEOUS REGISTERS */
#define REG_CFG_KEY 0x1F

/* Timer REGISTER*/
#define REG_TIM_CTRL 0x18
#define REG_TIM_CD 0x19
#define REG_TIM_INITVAL 0x1A

/* ANALOG CONTROL REGISTERS */
#define REG_TRICKLE 0x20
#define REG_BREF 0x21
#define REG_AFCTRL 0x26
#define REG_BAT_IOREG 0x27
#define REG_ANA_STS 0x2F
#define REG_OUTPUT_CTRL 0x30   

/* ID REGISTERS */
#define REG_ID0 0x28
#define REG_ID1 0x29
#define REG_ID2 0x2A
#define REG_ID3 0x2B
#define REG_ID4 0x2C
#define REG_ID5 0x2D
#define REG_ID6 0x2E

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
#define TIM_RPT_EN 0x20
 

#define RPT_SEC 0x1C // once per seconds
#define RPT_MIN 0x18 //
#define RPT_HOUR 0x14
#define RPT_DAY 0x10
#define RPT_WEEK 0x0C
#define RPT_MON 0x08
#define RPT_YEAR 0x04
#define RPT_ALAM_DISABLE 0x00

#define TFS_128HZ 0x00
#define TFS_64HZ 0x01
#define TFS_1HZ 0x02
#define TFS_1_64HZ 0x03

#define CFGKEY_OSC 0xA1
#define CFGKEY_SW_RST 0x3C
#define CFGKEY_TRICKLE 0x9D
#define CFGKEY_BREF 0x21
#define CFGKEY_OUTPUT_CTRL 0x9D
#define CFGKEY_AFCTRL 0xA0
#define CFGKEY_BAT_IOREG 0x9D

#define OSC_RC 0x80   // enable 128Hz RC osc
#define OSC_ACAL 0x40 // enable autocalibration
#define OSC_OUTB_EN 0x20

#define CTRL1_OUT_EN 0x10

#endif // AM1805_REG_H