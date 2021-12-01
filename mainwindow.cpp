/*!
 @brief Main function to initiate start of QApplication
 @author Ashwin Singh 
 */

#include "mainwindow.h"

mainwindow:: mainwindow(QWidget *parent) : QMainWindow(parent) {
	qRegisterMetaType<std::string>("std::string");
	sensor = new MotionSensorThread(this);
	connect(sensor, &MotionSensorThread::sendReading, this, &mainwindow::onSensorReading);
	sensor->start();	

	btn_1 = new QPushButton("weather", this);
	btn_2 = new QPushButton("spotify", this);
	btn_3 = new QPushButton("twitter", this);
	btn_4 = new QPushButton("time", this);
	title = new QLabel("Welcome to the MEGA-MIRROR John, how may I help you?", this);
	text_1 = new QLabel("Show me the weather outside", this);
	text_2 = new QLabel("Show me my recently played Spotify tracks", this);
	text_3 = new QLabel("Show me Jack Dorsey's tweets", this);
	text_4 = new QLabel("What's the time?", this);
	sensor_text = new QLabel("Motion Detection", this);

	title->setGeometry(QRect(QPoint(350, 0), QSize(1500,50)));
	text_1->setGeometry(QRect(QPoint(0, 100), QSize(1500, 50)));
	btn_1->setGeometry(QRect(QPoint(0, 200), QSize(1500, 50)));
	btn_2->setGeometry(QRect(QPoint(0, 300), QSize(1500, 50)));
	text_2->setGeometry(QRect(QPoint(0, 400), QSize(1500, 50)));
	btn_3->setGeometry(QRect(QPoint(0, 500), QSize(1500, 50)));
	text_3->setGeometry(QRect(QPoint(0, 600), QSize(1500, 100)));
	text_3->setWordWrap(true);
	btn_4->setGeometry(QRect(QPoint(0, 700), QSize(1500, 50)));
	text_4->setGeometry(QRect(QPoint(0, 800), QSize(1500,50)));

	sensor_text->setGeometry(QRect(QPoint(0, 900), QSize(1500, 50)));

	m = new Model();

	make_connection(btn_1, text_1);
	make_connection(btn_2, text_2);
	make_connection(btn_3, text_3);
	make_connection(btn_4, text_4);
}

void mainwindow::make_connection(QPushButton *btn, QLabel *label) {
	connect(btn, &QPushButton::clicked, this, [this, btn, label] () {
                        std::string s = btn->text().toStdString();
                        std::string output;
                        m->update(s);
                        output = m->show_out();
                        label->setText(QString::fromStdString(output));
           });

}

void mainwindow::onSensorReading(std::string reading) {
	std::cout << "Reading is: " << reading << std::endl;
	sensor_text->setText(QString::fromStdString(reading));
}
