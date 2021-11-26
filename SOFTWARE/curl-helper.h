#ifndef CURL_HELPER_H
#define CURL_HELPER_H

#include <curl/curl.h>
#include <string>
#include <iostream>

class curl_helper {
	public:
		curl_helper(struct curl_slist* headers, std::string url, std::string req_type);
		~curl_helper();
		static size_t writefunc(void *ptr, size_t size, size_t nmemb, std::string *s);
		std::string& get_response();
	private:
		std::string response;
};
#endif
