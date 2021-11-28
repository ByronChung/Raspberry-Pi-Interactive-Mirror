#ifndef MOTION_SENSOR_THREAD_H
#define MOTION_SENSOR_THREAD_H

#include <QThread>
#include <iostream>
#include <string.h>
#include <wiringSerial.h>
#include <wiringPi.h>
#include <QtCore>

class MotionSensorThread : public QThread {
	Q_OBJECT
	
	public:
		explicit MotionSensorThread(QObject *parent = 0);
		virtual void run(void);
	signals:
		void sendReading(std::string reading);
	public slots:
};
#endif
