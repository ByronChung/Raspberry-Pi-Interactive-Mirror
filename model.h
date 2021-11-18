#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>
#include "api_factory.h"

class model {
	public:
		model();
		~model() = default;
		void update(std::string& s);
		void show_out(void);
	private:
		api_interface* api;
		api_factory factory;
		std::string api_out;

};
#endif

