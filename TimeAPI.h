/*!
@brief Class used to generate current time based on C++ library function
Class returns current time using C time
*/

#ifndef TIMEAPI_H
#define TIMEAPI_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <string>
#include "APIInterface.h"

using namespace std;

class TimeAPI: public APIInterface
{
	public:
		/*!
		@brief Implemented function based on API interface
		Function calls C library local-time function
		@param None
		@return formatted current time
		@author Byron Chung, Pablo Ortega, Ashvinder Suri, Saad Ali
		*/
		std::string& call() override;
	private:
		int sec_prev;
		std::stringstream buffer;
		int seconds, minutes, hours;
    		std::string str;
		time_t total_seconds;
		struct tm* ct;
		std::string output;
};
#endif
