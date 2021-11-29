/*!
 @brief User Interface class that is driven by data sent from hardware & APIs
 Class implements button triggers for API calls to display Spotify and Weather data, and uses QThreads to display whether motion is detected or not from the MotionSensorThread Class
*/

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

class mainwindow : public QMainWindow { 
	
	Q_OBJECT 
	
	public:
		/*!
 		 @brief Constructor to initiate button-handler connections and thread process for polling PIR sensor data from Raspberry Pi-Arduino set-up
 		 Initialize all button on-click handlers and trigger thread to fetch sensor readings continously in background
		 @parameters Addresses of the button and its label
		 @return None
		 @author Ashwin Singh, Ashvinder Suri
		 */
		
		explicit mainwindow(QWidget *parent=nullptr); 
		/*!
 		 @brief Function to automate QT connection process for a particular button and its label
 		 Connect button to its label such that when the button is pressed, its label is sent as a string to the Model class to generate an API call & retrieve, show data for the UI
		 @parameters Addresses of the button and its label
		 @return None
		 @author Ashwin Singh, Ashvinder Suri
		 */
		void make_connection(QPushButton *btn, QLabel *label);
	
	public slots:
		/*!
 		 @brief Function to retrieve data from MotionSensorThread Class that handles Raspberry Pi-Arduino PIR sensor monitoring
		 Every 5 seconds when sensor readings updated and emitted from MotionSensorThread Class, onSensorReading receives resultant string indicating if motion detected or not
		 @parameters String representing motion detection reading
		 @return None
		 @author Ashwin Singh
		 */
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

