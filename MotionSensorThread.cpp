#include "MotionSensorThread.h"

MotionSensorThread::MotionSensorThread(QObject *parent) : QThread(parent) {}


void MotionSensorThread::run() {
	int fd;

	//Open serial connection

	if((fd = serialOpen("/dev/ttyACM0", 9600)) < 0) {
		std::cout << "Error opening connection" << std::endl;	
	}

	char input;
	int flag = 0;

	delay(5000);

	//Store motion detection string
	std::string output = "No motion detected\n";

	for(;;) {
		
		//Only when data is available, grab motion flag from Arduino, parse to int & update string
		if(serialDataAvail(fd)) {
			
			input = serialGetchar(fd);
			int check = input - '0';
			
			if((check == 0) || (check == 1)) {
				flag = input - '0';
			}
		}

		if(flag == 0) {
			output = "No motion detected";
		}

		else if(flag == 1){
			output = "Motion detected";
		}

		emit sendReading(output);  

		//Poll Arduino every five sec
		delay(5000);
	}
}
