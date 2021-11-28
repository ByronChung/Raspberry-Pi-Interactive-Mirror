#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>
#include "APIFactory.h"

class Model {
	public:
		Model();
		~Model() = default;
		void update(std::string& s);
		std::string& show_out(void);
	private:
		APIInterface* api;
		APIFactory factory;
		std::string api_out;

};
#endif

