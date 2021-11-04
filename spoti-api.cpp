#include "spoti-api.h"

spoti_api::spoti_api(void){
	base_64_encoding_auth_request = "Authorization: Basic ODNjYjhjZmI5YTNkNGNkYmJiZDdlZmRmNTdmNzFkNWI6OTQ0ZjEwMDg1YWNmNDg0Mzk3ZDkwN2IzNTg0YTc3MWE=";
	refresh_request = "https://accounts.spotify.com/api/token?grant_type=refresh_token&refresh_token=AQAdqYuGHig8gIwc9rf7ED4KZcPexZWeq3cRBxIUUaS7G3SsC8e7TG9oGEhGtE6PmknM2Pe_L09SQcXnnVudl80QoGhG4A5MsI_mn-hJos2ibLOPt59BWDVKnCRin9MDOv4";
}

size_t spoti_api::writefunc(void *ptr, size_t size, size_t nmemb, std::string *s) {
	s->append((char *) ptr, size*nmemb);
	return size*nmemb;
}

void spoti_api::parseAccessToken(std::string& s) {
	
	Json::Reader reader;
	Json::Value obj;

	reader.parse(s, obj);

	access_token = obj["access_token"].asString();

	std::cout << "Access Token " << access_token << std::endl;
}


void spoti_api::getRecentlyPlayedTracks() {
	struct curl_slist *headers;

	headers = NULL;
	headers = curl_slist_append(headers, "Accept: application/json");
	headers = curl_slist_append(headers, "Content-Type: application/json");
	
	std::string auth = "Authorization: Bearer ";
	auth.append(access_token);
	
	headers = curl_slist_append(headers, auth.c_str());

	CURL *curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, "https://api.spotify.com/v1/me/player/recently-played?limit=5");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.68.0");
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "GET");
		
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &spotify_response);

		CURLcode res = curl_easy_perform(curl);
		std::cout << spotify_response << std::endl;
		curl_easy_cleanup(curl);
	}
}

void spoti_api::parseRecentTracks() {
	Json::Reader reader;
	Json::Value obj;

	reader.parse(spotify_response, obj);
	
	for(Json::Value::ArrayIndex i = 0; i != obj["items"].size(); i++) {
		std::cout << "Song: " << obj["items"][i]["track"]["name"].asString() << std::endl;
		recentSongs.push_back(obj["items"][i]["track"]["name"].asString());
	}
}


void spoti_api::call() {
	struct curl_slist *headers;

  	headers = NULL;
  	headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
  	headers = curl_slist_append(headers, base_64_encoding_auth_request);
	
	CURL *curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, refresh_request);
		curl_easy_setopt(curl, CURLOPT_USERAGENT, "curl/7.68.0");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);		
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
                curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
		
		CURLcode res = curl_easy_perform(curl);
		std::cout << s << std::endl;
                curl_easy_cleanup(curl);
	}
	parseAccessToken(s);
	
	getRecentlyPlayedTracks();
	
	parseRecentTracks();

}

