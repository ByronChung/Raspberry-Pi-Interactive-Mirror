#ifndef API_H
#define API_H

#include <iostream>
#include <string>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>
#include "api_interface.h"
#include "curl-helper.h"

class api: public api_interface {
	public:
		api();
		~api() = default;
		//static size_t writefunc(void *ptr, size_t size, size_t nmemb, std::string *s);
		void parseString(std::string& s);
		std::string& call() override;

	private:
		std::string weather_response;
		curl_helper *curl_make;
};
#endif
