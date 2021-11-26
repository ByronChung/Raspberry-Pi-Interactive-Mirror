#ifndef WEATHER_API_H
#define WEATHER_API_H

#include <iostream>
#include <string>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>
#include "APIInterface.h"
#include "CurlHelper.h"

class WeatherAPI: public APIInterface {
	public:
		WeatherAPI();
		~WeatherAPI() = default;
		void parseString(std::string& response);
		std::string& call() override;
	private:
		std::string weather_response;
		 CurlHelper *curl_response_make;
};
#endif
