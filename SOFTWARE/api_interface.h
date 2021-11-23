#ifndef API_INTERFACE_H
#define API_INTERFACE_H
#include <string>

class api_interface {
	public:
		virtual std::string& call() = 0;
};
#endif
