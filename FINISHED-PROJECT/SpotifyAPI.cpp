#include "SpotifyAPI.h"

//Structure of authorization request headers and tokens are according to Spotify authorization flow: https://developer.spotify.com/documentation/general/guides/authorization/code-flow/
SpotifyAPI::SpotifyAPI(void){
	base_64_encoding_auth_request = "Authorization: Basic ODNjYjhjZmI5YTNkNGNkYmJiZDdlZmRmNTdmNzFkNWI6OTQ0ZjEwMDg1YWNmNDg0Mzk3ZDkwN2IzNTg0YTc3MWE=";
	refresh_request = "https://accounts.spotify.com/api/token?grant_type=refresh_token&refresh_token=AQAdqYuGHig8gIwc9rf7ED4KZcPexZWeq3cRBxIUUaS7G3SsC8e7TG9oGEhGtE6PmknM2Pe_L09SQcXnnVudl80QoGhG4A5MsI_mn-hJos2ibLOPt59BWDVKnCRin9MDOv4";
}

void SpotifyAPI::parseAccessToken(std::string& s) {	
	Json::Reader reader;
	Json::Value obj;

	reader.parse(s, obj);
	access_token = obj["access_token"].asString();
}

void SpotifyAPI::getRecentlyPlayedTracks() {
	struct curl_slist *headers;

	headers = NULL;
	headers = curl_slist_append(headers, "Accept: application/json");
	headers = curl_slist_append(headers, "Content-Type: application/json");
	
	std::string auth = "Authorization: Bearer ";
	auth.append(access_token);
	
	headers = curl_slist_append(headers, auth.c_str());

	curl_response_make = new CurlHelper(headers, "https://api.spotify.com/v1/me/player/recently-played?limit=5", "GET");
	spotify_songs_response = curl_response_make->get_response();
}

//Function to parse HTTP response of recently played tracks
void SpotifyAPI::parseRecentTracks() {
	Json::Reader reader;
	Json::Value obj;

	reader.parse(spotify_songs_response, obj);
	recentSongs = "";

	for(Json::Value::ArrayIndex i = 0; i != obj["items"].size(); i++) {
		recentSongs +=	"Song: " + obj["items"][i]["track"]["name"].asString();
	}
}

std::string& SpotifyAPI::call() {
	struct curl_slist *headers;

	//Add refresh token & base-64 encoding of the Spotify API key to generate access key which expires within an hour
	//Therefore must run authentication first on each API call
  	headers = NULL;
  	headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
  	headers = curl_slist_append(headers, base_64_encoding_auth_request);
	
	curl_token_make = new CurlHelper(headers, refresh_request, "POST");
	spotify_auth_response = curl_token_make->get_response();
	
	//Perform remaining API call to retrieve recently played tracks & parsing
	parseAccessToken(spotify_auth_response);
	getRecentlyPlayedTracks();
	parseRecentTracks();

	return recentSongs;
}

