#ifndef MAINWINDOW_H 
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QMetaType>
#include <QLabel>
#include <string>
#include <iostream>
#include "Model.h"
#include "APIFactory.h"
#include "APIInterface.h"
#include "CurlHelper.h"
#include "SpotifyAPI.h"
#include "WeatherAPI.h"
#include "MotionSensorThread.h"

class mainwindow : public QMainWindow { //Inherit from QMainWindow class to display UI contents into window container
	
	Q_OBJECT //macro that alerts compiler to process additional QT functions needed for handling things such as signals, slots
	
	public:
		explicit mainwindow(QWidget *parent=nullptr); //No parent exists for this window, therefore pass null pointer
		void make_connection(QPushButton *btn, QLabel *label);
	
	public slots:
		void onSensorReading(std::string reading);
	private:
		QPushButton *btn_1;
		QPushButton *btn_2;
		QLabel *text_1;
		QLabel *text_2;
		QLabel *sensor_text;
		Model *m;

		MotionSensorThread *sensor;
};
#endif

