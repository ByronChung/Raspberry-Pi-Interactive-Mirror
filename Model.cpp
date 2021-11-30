//Class used to store the API factory, trigger resulting API call and store the output

#include "Model.h"

Model::Model(void){
}

void Model::update(std::string& api_id) {
	api = factory.getAPI(api_id);
	api_out = api->call();
}

std::string& Model::show_out() {
	std::cout << "Output: " << api_out << std::endl;
	return api_out;
}
