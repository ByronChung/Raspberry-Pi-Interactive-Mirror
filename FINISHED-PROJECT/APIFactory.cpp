#include "APIFactory.h"

APIFactory::APIFactory(void) {}

APIInterface* APIFactory::getAPI(std::string& api_id) {
	
	APIInterface* api_type;
	
	//Depending on string passed to function, return a specific API object
	if(api_id == "weather") {
		api_type = new WeatherAPI();
	}
	else if(api_id == "spotify") {
		api_type = new SpotifyAPI();
	}
	return api_type;
}	

