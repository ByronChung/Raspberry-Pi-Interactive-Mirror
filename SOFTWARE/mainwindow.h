/*
Author: Ashwin Singh (250 955 585)
Description: Header file containing imports, function and instance variable declarations
Date: October 5, 2021
*/


#ifndef MAINWINDOW_H //Include header guard to prevent repeated definitions when preprocessor parses file
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QScrollArea>
#include <string>
#include <iostream>
#include "Model.h"
#include "APIFactory.h"
#include "APIInterface.h"
#include "CurlHelper.h"
#include "SpotifyAPI.h"
#include "WeatherAPI.h"

class mainwindow : public QMainWindow { //Inherit from QMainWindow class to display UI contents into window container
	
	Q_OBJECT //macro that alerts compiler to process additional QT functions needed for handling things such as signals, slots
	
	public:
		explicit mainwindow(QWidget *parent=nullptr); //No parent exists for this window, therefore pass null pointer
		void make_connection(QPushButton *btn, QLabel *label);
	
	private slots: //Slot gets called when signal emitted to it; in this case handleButton() executes to create Boost process, return output and error
		//void function(QString& text);
	
	private:
		QPushButton *btn_1;
		QPushButton *btn_2;
		QLabel *text_1;
		QLabel *text_2;
		Model *m;
};
#endif

