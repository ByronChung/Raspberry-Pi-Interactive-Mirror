#include "curl-helper.h"

size_t curl_helper::writefunc(void *ptr, size_t size, size_t nmemb, std::string *s) {
	s->append((char *) ptr, size*nmemb);
	return size*nmemb;
}

curl_helper::curl_helper(struct curl_slist* headers, std::string url, std::string req_type) {
	const char* curl_url = url.c_str();
	const char* curl_req_type = req_type.c_str();


	CURL *curl = curl_easy_init();

	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, curl_url);
		std::cout << curl_url << std::endl;
		
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

std::string& curl_helper::get_response() {
	return response;
}

