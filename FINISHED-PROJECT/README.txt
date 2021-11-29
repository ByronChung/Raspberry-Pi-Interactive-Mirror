LIBRARY INSTALLATION:
sudo apt-get update -y
sudo apt-get install libcurl4-openssl-dev
sudo apt-get install wiringpi
sudo apt-get install build-essential
sudo apt-get install qt5-default
sudo apt-get install libjsoncpp-dev

HARDWARE SETUP:
----ARDUINO----
LED VCC to ARDUINO DIG PIN 13
LED GND to ARDUINO GND
PIR OUTPUT to ARDUINO DIG PIN 3
PIR VCC to ARDUINO 5V
PIR GND to ARDUINO GND

----RASPBERRY PI----
Arduino USB B to Raspberry Pi USB A
Display HDMI to Raspberry Pi HDMI

NOTE:
Due to underlying system architectures it is difficult to configure & install a core library used in the project: WiringPi
Therefore the version of the submitted project only runs on a Raspbian System with an ARM architecture as those come pre-loaded with the correct WiringPi library

COMPILE & RUN:
find . -exec touch {} \;
qmake
make
./SmartMirror