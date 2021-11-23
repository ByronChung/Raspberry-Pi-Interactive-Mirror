HARDWARE SETUP:

On the Arduino:
LED VCC to ARDUINO DIG PIN 13
LED GND to ARDUINO GND
PIR OUTPUT to ARDUINO DIG PIN 3
PIR VCC to ARDUINO 5V
PIR GND to ARDUINO GND

On the Raspberry Pi:
Arduino USB B to Raspberry Pi USB A
Display HDMI to Raspberry Pi HDMI

To compile and run pir_sensor_rpi.c:
gcc pir_sensor_rpi.c -g -Wall -lwiringPi