#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <wiringSerial.h>
#include <wiringPi.h>

int main() {
	int fd;

	//Open serial connection

	if((fd = serialOpen("/dev/ttyACM0", 9600)) < 0) {
			fprintf(stderr, "Unable to open serial device: %s\n", strerror(errno));
			return 1;	
	}

	printf("Begin reading\n");

	char input;
	int flag = 0;

	delay(5000);

	//Store motion detection string
	char output[500] = "No motion detected\n";

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
			strcpy(output, "No motion detected\n");
		}

		else if(flag == 1){
			strcpy(output, "Motion detected\n");
		}

		printf(output);

		//Poll Arduino every five sec
		delay(5000);
	}
}
