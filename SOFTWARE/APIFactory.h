#ifndef API_FACTORY
#define API_FACTORY

#include "APIInterface.h"
#include "WeatherAPI.h"
#include "SpotifyAPI.h"
#include "CurlHelper.h"

class APIFactory {
	public:
		APIFactory();
		~APIFactory() = default;
		APIInterface* getAPI(std::string& api_id);
	
};
#endif
