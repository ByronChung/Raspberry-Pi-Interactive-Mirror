#include "api.h"

api::api(boost::asio::io_service& io) : timer_(io, boost::posix_time::seconds(1)), count_(0) {
        s = "";
       	timer_.async_wait(boost::bind(&api::call, this));
}

size_t api::writefunc(void *ptr, size_t size, size_t nmemb, std::string *s) {
	s->append((char *) ptr, size*nmemb);
	return size*nmemb;
}

void api::parseString(std::string& s) {
	
	Json::Reader reader;
	Json::Value obj;

	reader.parse(s, obj);


	std::cout << "Temperature (C): " << obj["current"]["temp_c"].asString() << ", Feels Like (C): " << obj["current"]["feelslike_c"].asString() << std::endl;
}

void api::call(){
        if (count_ < 5) {
            	CURL *curl = curl_easy_init();
           
            	if(curl) {
                	curl_easy_setopt(curl, CURLOPT_URL, "http://api.weatherapi.com/v1/current.json?key=8237af53843644a486f41015213110&q=London");
                	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
                	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);

                	CURLcode res = curl_easy_perform(curl);
                	std::cout << s << std::endl;
                	curl_easy_cleanup(curl);
            	}

            	parseString(s);

            	++count_;
            	timer_.expires_at(timer_.expires_at() + boost::posix_time::seconds(10));
            	timer_.async_wait(boost::bind(&api::call, this));
        }
}
	
