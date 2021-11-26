#include "api.h"

api::api(void) {}

/*size_t api::writefunc(void *ptr, size_t size, size_t nmemb, std::string *s) {
	s->append((char *) ptr, size*nmemb);
	return size*nmemb;
}*/

void api::parseString(std::string& s) {	
	Json::Reader reader;
	Json::Value obj;
	reader.parse(s, obj);
	s = "Temperature (C): " + obj["current"]["temp_c"].asString() + ", Feels Like (C): " + obj["current"]["feelslike_c"].asString();
}

std::string& api::call() {
	curl_make = new curl_helper(NULL, "http://api.weatherapi.com/v1/current.json?key=8237af53843644a486f41015213110&q=London", "GET");
      	weather_response = curl_make->get_response();	
	std::cout << weather_response << std::endl;
	parseString(weather_response);
	return weather_response;
}

	
