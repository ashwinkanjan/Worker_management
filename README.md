# Smart Machine Monitoring System (Arduino)

##  Overview

This project monitors the operating time of industrial machines using a vibration sensor and tracks worker interaction using RFID.

##  Components Used

* Arduino Uno
* Vibration Sensor / Push Button (for simulation)
* RFID Module (RC522)
* I2C 16x2 LCD Display
* RTC Module (DS3231)

##  Features

* Detects machine ON/OFF using vibration
* Calculates total operating duration
* Displays working time in minutes
* Identifies worker using RFID
* Shows worker name on LCD

##  Development Process

* Tested vibration sensor separately
* Verified RTC functionality
* Validated RFID UID detection
* Integrated all modules
* Solved sensor instability using software delay

##  Connections

* RFID → SPI (D10–D13, D9)
* RTC + LCD → I2C (A4, A5)
* Vibration Sensor / Button → D2

##  Output

LCD displays:

* Machine operating time
* Worker name

##  Simulation

https://wokwi.com/projects/462292575966362625

##  Future Improvements

* Data logging system
* Web dashboard integration
* Multiple worker tracking
