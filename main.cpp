/*
Author: Ashwin Singh
Description: Main program to run user interface
Date October 5, 2021
*/
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	mainwindow mainWindow;
	mainWindow.showMaximized();
	return app.exec();
}
