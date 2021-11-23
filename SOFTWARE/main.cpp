#include "api.h"
#include "spoti-api.h"
#include <iostream>

int main(){
	std::string g;
	std::string h;
	
	api* tst_weather = new api();
	spoti_api* tst_music = new spoti_api();
	
	g = tst_weather->call();
	h = tst_music->call();	
	
	std::cout << g << h << std::endl;
	
	return 0;
}
