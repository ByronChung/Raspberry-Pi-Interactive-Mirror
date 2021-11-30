/*!
 @brief Class used to interface with Weather API
 Class performs API call to fetch recently weather data from London, England
*/

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
		/*!
 		 @brief Parse response from API request to retrieve weather data
 		 Convert JSON response into a dictionary, parse response, retrieve weather data & store
		 @param Raw JSON weather data response string
		 @return None
		 @author Ashwin Singh
		 */
		void parseString(std::string& response);
		/*!
 		 @brief Implemented function based on APIInterface; Perform weather data API call, parse and store response
 		 Using cURL, perform HTTP request to weather data server using API-key for access, then parse the raw JSON response in parseString() member function & return resultant string
		 @param None
		 @return Formatted string of weather statistics 
		 @author Ashwin Singh
		 */
		std::string& call() override;
	private:
		std::string weather_response;
		 CurlHelper *curl_response_make;
};
#endif
