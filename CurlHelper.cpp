//Class to perform CURL HTTP set-up and execution

#include "CurlHelper.h"

//Callback function to store HTTP response
size_t CurlHelper::writefunc(void *ptr, size_t size, size_t nmemb, std::string *s) {
	s->append((char *) ptr, size*nmemb);
	return size*nmemb;
}

//Constructor to set up HTTP request and retrieve response using CURL
CurlHelper::CurlHelper(struct curl_slist* headers, std::string url, std::string req_type) {
	//cURL a C-based library, therefore convert C++ style strings to C-strings
	const char* curl_url = url.c_str();
	const char* curl_req_type = req_type.c_str();


	CURL *curl = curl_easy_init();

	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, curl_url);
		
		//Append headers if any passed
		if(headers != NULL) {
			curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		}
		
		//Modify user agent so server knows what type of device sends request
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.68.0");
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, curl_req_type);
		
		//Setup callback function to parse transferred data & store to variable
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

		//Perform HTTP request, clean up & exit
		curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
}

//Getter to fetch HTTP response
std::string& CurlHelper::get_response() {
	return response;
}

