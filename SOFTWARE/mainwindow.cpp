#include "mainwindow.h"

mainwindow:: mainwindow(QWidget *parent) : QMainWindow(parent) {
	qRegisterMetaType<std::string>("std::string");
	sensor = new MotionSensorThread(this);
	connect(sensor, &MotionSensorThread::sendReading, this, &mainwindow::onSensorReading);
	sensor->start();	

	btn_1 = new QPushButton("weather", this);
	btn_2 = new QPushButton("spotify", this);
	text_1 = new QLabel("Weather data shows up here", this);
	text_2 = new QLabel("Music data shows up here", this);
	sensor_text = new QLabel("Sensor readings go here", this);

	text_1->setGeometry(QRect(QPoint(0, 0), QSize(200, 50)));
	btn_1->setGeometry(QRect(QPoint(0, 100), QSize(200, 50)));
	btn_2->setGeometry(QRect(QPoint(0, 200), QSize(200, 50)));
	text_2->setGeometry(QRect(QPoint(0, 300), QSize(200, 50)));
	sensor_text->setGeometry(QRect(QPoint(0, 400), QSize(200, 50)));

	m = new Model();

	make_connection(btn_1, text_1);
	make_connection(btn_2, text_2);
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
