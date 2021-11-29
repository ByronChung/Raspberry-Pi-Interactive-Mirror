/*!
 @brief Main function to initiate start of QApplication
 @author Ashwin Singh 
 */

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
	QApplication app(argc, argv);
	mainwindow mainWindow;
	mainWindow.showMaximized();
	return app.exec();
}
