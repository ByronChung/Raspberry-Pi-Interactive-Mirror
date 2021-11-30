#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream> 
#include <string>
//#include <curl/curl.h>
//#include <jsoncpp/json/json.h>
//#include "APIInterface.h"
//#include "CurlHelper.h"

using namespace std;

class Timer
{
	public:
		std::string return_Time();
		int sec_prev;
		std::stringstream buffer;
		int seconds, minutes, hours;
    		std::string str;
		time_t total_seconds;
		struct tm* ct;
		std::string output;
};
#endif
