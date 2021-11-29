#include "WeatherAPI.h"

WeatherAPI::WeatherAPI(void) {}

void WeatherAPI::parseString(std::string& response) {	
	Json::Reader reader;
	Json::Value json_response;
	reader.parse(response, json_response);
	weather_response = "Temperature (C): " + json_response["current"]["temp_c"].asString() + ", Feels Like (C): " + json_response["current"]["feelslike_c"].asString();
}

std::string& WeatherAPI::call() {
	//API key hard-coded into URL 
	curl_response_make = new CurlHelper(NULL, "http://api.weatherapi.com/v1/current.json?key=8237af53843644a486f41015213110&q=London", "GET");
    weather_response = curl_response_make->get_response();	
	parseString(weather_response);
	return weather_response;
}

	
