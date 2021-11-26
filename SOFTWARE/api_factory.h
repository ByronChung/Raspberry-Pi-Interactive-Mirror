#ifndef API_FACTORY
#define API_FACTORY

#include <iostream>
#include "api_interface.h"
#include "api.h"
#include "spoti-api.h"
#include "curl-helper.h"

class api_factory {
	public:
		api_factory();
		~api_factory() = default;
		api_interface* getAPI(std::string& s);
	
};
#endif
