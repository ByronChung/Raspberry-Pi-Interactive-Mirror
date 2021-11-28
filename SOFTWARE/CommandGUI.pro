QT += core widgets
TARGET = CommandGUI
TEMPLATE = app
SOURCES += main.cpp mainwindow.cpp Model.cpp APIFactory.cpp CurlHelper.cpp SpotifyAPI.cpp WeatherAPI.cpp
HEADERS += mainwindow.h Model.h APIFactory.h APIInterface.h CurlHelper.h SpotifyAPI.h WeatherAPI.h 
LIBS += -ljsoncpp -lcurl -lboost_thread -lpthread 
