/*!
 @brief API Factory to return types of API objects depending on what client requested
 Class uses string passed from button labels of UI to generate inherited API class objects (e.g. SpotifyAPI, WeatherAPI)
 @author Ashwin Singh 
 */


#ifndef API_FACTORY
#define API_FACTORY

#include "APIInterface.h"
#include "WeatherAPI.h"
#include "SpotifyAPI.h"
#include "TwitterAPI.h"
#include "TimeAPI.h"
#include "CurlHelper.h"

class APIFactory {
	public:
		APIFactory();
		~APIFactory() = default;
		
		/*!
 		 @brief Return API object given a certain string
 		 Construct specific API object given string passed from button label; API object later used to perform HTTP requests to that API's server
		 @author Ashwin Singh
		 @param Pass address of string specifying API object requested
		 @return Constructed API object 
		*/
		APIInterface* getAPI(std::string& api_id);
	
};
#endif
