.. zephyr:code-sample:: i2c-custom-target
   :name: Set timer interrupt out

   Setup AM1805, timer interrupt and send a i2c read command to fetch date time data.

Overview
********

Setup AM1805, timer interrupt and send a i2c read command to fetch date time data.
By default, the timer interrupt is set to 30 seconds. When the timer expires, the
interrupt is triggered and the timer is reset to 30 seconds.

The result will be printed on the console:
...
0-0-1-1 0:7:18:24 - timer: 4
0-0-1-1 0:7:19:24 - timer: 3
0-0-1-1 0:7:20:24 - timer: 2
0-0-1-1 0:7:21:25 - timer: 1
0-0-1-1 0:7:22:25 - timer: 0
Timmy is triggered 
0-0-1-1 0:7:23:26 - timer: 30
0-0-1-1 0:7:24:26 - timer: 29
0-0-1-1 0:7:25:27 - timer: 28
0-0-1-1 0:7:26:27 - timer: 27
...
