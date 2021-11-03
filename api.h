#ifndef API_H
#define API_H

#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <string>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>

class api {
	public:
		api(boost::asio::io_service& io);
		~api() = default;
		static size_t writefunc(void *ptr, size_t size, size_t nmemb, std::string *s);
		void parseString(std::string& s);
		void call();

	private:
		boost::asio::deadline_timer timer_;
		int count_;
		std::string s;
};
#endif
