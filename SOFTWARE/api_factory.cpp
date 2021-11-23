#include "api_factory.h"

api_factory::api_factory(void) {}

api_interface* api_factory::getAPI(std::string& s) {
	api_interface* api_type;
	if(s == "weather") {
		api_type = new api();
	}
	else if(s == "spotify") {
		api_type = new spoti_api();
	}
	return api_type;
}	

