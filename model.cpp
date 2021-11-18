#include "model.h"

model::model(void){
}

void model::update(std::string& s) {
	api = factory.getAPI(s);
	api_out = api->call();
}

void model::show_out() {
	std::cout << "Output: " << api_out << std::endl;
}
