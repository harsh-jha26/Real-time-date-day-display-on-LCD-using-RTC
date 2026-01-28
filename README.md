**Problem Statement**



Traditional microcontroller-based clocks lose track of time when power is disconnected.

There is a need for a simple, reliable, and low-cost system that can maintain and display accurate real-time date and time continuously, even during power interruptions.



**Abstract**



This project presents a real-time date, day, and time display system using Arduino Uno, DS3231 RTC module, and a 16×2 I2C LCD.

The DS3231 RTC maintains precise timekeeping using an inbuilt battery backup. Arduino communicates with both the RTC and LCD via the I2C protocol, ensuring efficient data transfer.

This system is suitable for smart clocks, IoT applications, automation systems, and embedded projects requiring accurate timekeeping.



**Components Required**



* Arduino Uno
* DS3231 Real-Time Clock Module
* 16×2 I2C LCD Display
* Breadboard
* Jumper Wires
* USB / External Power Supply



**Pin Configuration**



|Arduino Uno Pin|DS3231 RTC|16×2 I2C LCD|Description|
|-|-|-|-|
|5V|VCC|VCC|Power supply|
|GND|GND|GND|Ground|
|A4 (SDA)|SDA|SDA|I2C Data|
|A5 (SCL)|SCL|SCL|I2C Clock|



**Notes**



* Both RTC and LCD share the same I2C bus.
* LCD I2C address is usually 0x27 (sometimes 0x3F).
* DS3231 has an onboard coin cell battery for backup.



**Construction**



The DS3231 RTC module connects to Arduino using SDA and SCL pins.



The 16×2 I2C LCD shares the same I2C lines.



Arduino acts as the controller, reading time data from RTC and displaying it on LCD.



Breadboard and jumper wires are used for neat connections.



**Working Principle**



1. Arduino initializes RTC and LCD via I2C.
2. DS3231 continuously keeps track of date, day, and time.
3. Arduino fetches data from RTC at regular intervals.
4. Time and date are formatted and displayed on the LCD.
5. RTC continues running during power loss using battery backup.
6. LCD updates the display every second.



**Key Features**



* Accurate real-time clock
* Displays date, day, and time
* Battery-backed RTC
* Minimal wiring using I2C
* Low-cost and reliable system



**Algorithm**



1. Start the program.
2. Include required libraries.
3. Initialize RTC and LCD.
4. Define array for days of the week.
5. Set RTC time once (manual setup).
6. Read current time from RTC.
7. Display day and time on LCD line 1.
8. Display date on LCD line 2.
9. Delay for 1 second.
10. Repeat continuously.
