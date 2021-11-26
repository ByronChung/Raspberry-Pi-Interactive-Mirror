#include "Model.h"
#include <iostream>
#include "APIFactory.h"
#include "APIInterface.h"
#include "WeatherAPI.h"
#include "SpotifyAPI.h"
#include "CurlHelper.h"

int main() {
	std::string g;
	std::string h;

	Model* m = new Model();

	g = "weather";
	h = "spotify";

	m->update(g);
	m->show_out();

	m->update(h);
	m->show_out();
}

