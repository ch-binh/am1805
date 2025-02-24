.. zephyr:code-sample:: set-timer-interrupt-out
   :name: Set Timer Interrupt Out
   :relevant-api: timer_interface

   Setup a timer interrupt output 

Overview
********

This sample demonstrates how to setup a timer interrupt output.

Notice
******

I dont know why but the RTC is reset, exactly 3 minutes is needed for
the countdown timer to work (?). 

By default, the timer will countdown 1 every minutes. If the current value is 0,
it will increase by 1, so the interrupt period will be (n + 1) minutes.

Requirements
************

This sample has been tested on :ref:`nrf52840dk_nrf52840`.

Building and Running
********************

The code for this sample can be found in :zephyr_file:`samples/drivers/timer_interrupt_out`.

To build and flash the application:

.. zephyr-app-commands::
   :zephyr-app: samples/drivers/timer_interrupt_out
   :board: nrf52840dk_nrf52840
   :goals: flash
   :compact:
