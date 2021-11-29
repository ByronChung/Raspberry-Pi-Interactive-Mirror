#include "MotionSensorThread.h"

MotionSensorThread::MotionSensorThread(QObject *parent) : QThread(parent) {}

void MotionSensorThread::run() {
	int fd;

	//Open serial connection, essential to access data incoming from Arduino
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
			
			//Arduino passes a character: 0 if no motion detected else 1 if motion detected
			//Convert character to an integer and store that sensor reading as a motion detection flag
			input = serialGetchar(fd);
			int check = input - '0';
			
			if((check == 0) || (check == 1)) {
				flag = input - '0';
			}
		}

		//Depending on motion detection reading, store a certain output string to be displayed later on UI
		if(flag == 0) {
			output = "No motion detected";
		}

		else if(flag == 1){
			output = "Motion detected";
		}

		//Emit a signal containing the motion detection reading string; will eventually be received & processed by the mainwindow thread
		emit sendReading(output);  

		//Poll Arduino every five seconds
		delay(5000);
	}
}
