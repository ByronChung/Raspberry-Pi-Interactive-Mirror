//Class implements Factory design pattern to return specific APIs depending on request from client accessing the UI; type of request classified by string identifier

#include "APIFactory.h"

APIFactory::APIFactory(void) {}

APIInterface* APIFactory::getAPI(std::string& api_id) {
	
	APIInterface* api_type;
	
	if(api_id == "weather") {
		api_type = new WeatherAPI();
	}
	else if(api_id == "spotify") {
		api_type = new SpotifyAPI();
	}
	else if(api_id == "twitter") {
		api_type = new TwitterAPI();
	}
	else if(api_id == "time") {
		api_type = new TimeAPI();
	}
	return api_type;
}	

