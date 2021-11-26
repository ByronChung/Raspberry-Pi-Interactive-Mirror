//Interface to implement different APIs from; evident as it employs a pure virtual function

#ifndef API_INTERFACE_H
#define API_INTERFACE_H

#include <string>

class APIInterface {
	public:
		virtual std::string& call() = 0;
};
#endif
