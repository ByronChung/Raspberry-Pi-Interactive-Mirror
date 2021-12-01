/*!
 @brief Helper class to set up and perform HTTP request using cURL
 Helper class handles header, parameter, HTTP request type (e.g. POST, GET) set-up and returns raw JSON response using cURL library
 @author Ashwin Singh 
 */
 
#ifndef CURL_HELPER_H
#define CURL_HELPER_H

#include <curl/curl.h>
#include <string>

class CurlHelper {
	public:
		/*!
 		 @brief Constructor to perform cURL set up and make request
 		 Setup headers, parameters and HTTP request type, then cURL performs request & stores raw data to the class member response
		 @author Ashwin Singh
		 @param struct containing request headers, URL string, and request-type string
		 @return None
		*/
		CurlHelper(struct curl_slist* headers, std::string url, std::string req_type);
		~CurlHelper();
		/*!
 		 @brief Callback function required to transfer response data into a variable
 		 cURL raw JSON response stored to class member response-string using callback function
		 @param void pointer, data chunk size, number of data chunks required from cURL library, and string variable storing data from request
		 @return unsigned data response code
		*/
		static size_t writefunc(void *ptr, size_t size, size_t nmemb, std::string *s);
		/*!
 		 @brief Getter to return raw JSON response
 		 Return raw JSON response stored to class member response-string
		 @param None
		 @return Address of response string
		*/
		std::string& get_response();
	private:
		std::string response;
};
#endif
