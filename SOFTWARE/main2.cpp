#include "model.h"
#include <iostream>
#include "api_factory.h"
#include "api_interface.h"
#include "api.h"
#include "spoti-api.h"
#include "curl-helper.h"

int main() {
	std::string g;
	std::string h;

	model* m = new model();

	g = "weather";
	h = "spotify";

	m->update(g);
	m->show_out();

	m->update(h);
	m->show_out();
}

