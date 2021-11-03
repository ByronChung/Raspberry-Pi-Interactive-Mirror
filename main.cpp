#include "api.h"

int main(){
	boost::asio::io_service io;
	api a(io);
	io.run();

	return 0;
}
