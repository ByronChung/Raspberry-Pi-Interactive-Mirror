/*!
 @brief Class used to interface Raspberry Pi with Passive Infrared (PIR) motion sensor readings from the Arduino
 Class generates polling function that retrieves sensor readings infinitely and emits a signal telling the UI if motion is detected or not every 5 seconds
*/
#ifndef MOTION_SENSOR_THREAD_H
#define MOTION_SENSOR_THREAD_H

#include <QThread>
#include <iostream>
#include <string.h>
#include <wiringSerial.h>
#include <wiringPi.h>
#include <QtCore>

//Class inherits from QThread, therefore must instantiate QThread's run() method later on
//Class can be instantiated as thread from another QObject class resultingly

class MotionSensorThread : public QThread {
	Q_OBJECT
	
	public:
		explicit MotionSensorThread(QObject *parent = 0);
		/*!
 		 @brief Infinitely running function used to poll PIR sensor data
 		 Required to be named run in order for QThread to trigger function when called; function forms connection to Arduino, polls sensor data & emits data to UI
		 @param None
		 @return None
		 @author Ashwin Singh
		 */
		virtual void run(void);
	signals:
		/*!
 		 @brief Function to emit string to UI to check whether motion detected
 		 Emitted signal called every 5 seconds; eventually received by UI thread (mainwindow) & processed there for display
		 @param String containing whether motion detected or not
		 @return None
		 @author Ashwin Singh
		 */
		void sendReading(std::string reading);
	public slots:
};
#endif
