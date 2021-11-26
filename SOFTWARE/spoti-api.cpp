#include "spoti-api.h"

spoti_api::spoti_api(void){
	base_64_encoding_auth_request = "Authorization: Basic ODNjYjhjZmI5YTNkNGNkYmJiZDdlZmRmNTdmNzFkNWI6OTQ0ZjEwMDg1YWNmNDg0Mzk3ZDkwN2IzNTg0YTc3MWE=";
	refresh_request = "https://accounts.spotify.com/api/token?grant_type=refresh_token&refresh_token=AQAdqYuGHig8gIwc9rf7ED4KZcPexZWeq3cRBxIUUaS7G3SsC8e7TG9oGEhGtE6PmknM2Pe_L09SQcXnnVudl80QoGhG4A5MsI_mn-hJos2ibLOPt59BWDVKnCRin9MDOv4";
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

	curl_response_make = new curl_helper(headers, "https://api.spotify.com/v1/me/player/recently-played?limit=5", "GET");
	spotify_songs_response = curl_response_make->get_response();

}

void spoti_api::parseRecentTracks() {
	Json::Reader reader;
	Json::Value obj;

	reader.parse(spotify_songs_response, obj);
	recentSongs = "";
	for(Json::Value::ArrayIndex i = 0; i != obj["items"].size(); i++) {
		recentSongs +=	"Song: " + obj["items"][i]["track"]["name"].asString();
	}
}


std::string& spoti_api::call() {
	struct curl_slist *headers;

  	headers = NULL;
  	headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
  	headers = curl_slist_append(headers, base_64_encoding_auth_request);
	
	curl_token_make = new curl_helper(headers, refresh_request, "POST");
	spotify_auth_response = curl_token_make->get_response();
	
	parseAccessToken(spotify_auth_response);
	getRecentlyPlayedTracks();
	parseRecentTracks();

	return recentSongs;

}

