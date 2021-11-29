#include "CurlHelper.h"

size_t CurlHelper::writefunc(void *ptr, size_t size, size_t nmemb, std::string *s) {
	s->append((char *) ptr, size*nmemb);
	return size*nmemb;
}

CurlHelper::CurlHelper(struct curl_slist* headers, std::string url, std::string req_type) {
	//cURL is a C-Style library, therefore generate C-Style strings to pass into cURL set-up methods
	const char* curl_url = url.c_str();
	const char* curl_req_type = req_type.c_str();

	CURL *curl = curl_easy_init();

	//Perform HTTP request set-up using cURL; in the case where no headers provided must pass NULL to constructor
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, curl_url);
		
		if(headers != NULL) {
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		}
		
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.68.0");
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, curl_req_type);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

		curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
}

std::string& CurlHelper::get_response() {
	return response;
}

