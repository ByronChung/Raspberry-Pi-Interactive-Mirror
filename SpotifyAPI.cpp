//Class to retrieve recently played tracks from group's common spotify account

#include "SpotifyAPI.h"

//Constructor to set up Spotify API authorization and refresh tokens
//Structure of authorization request headers and tokens are according to Spotify authorization flow: https://developer.spotify.com/documentation/general/guides/authorization/code-flow/

//Store Spotify client secret and refresh token for authentication
//According to auth standards, client secret must be encoded in base-64 format
SpotifyAPI::SpotifyAPI(void){
	base_64_encoding_auth_request = "Authorization: Basic ODNjYjhjZmI5YTNkNGNkYmJiZDdlZmRmNTdmNzFkNWI6OTQ0ZjEwMDg1YWNmNDg0Mzk3ZDkwN2IzNTg0YTc3MWE=";
	refresh_request = "https://accounts.spotify.com/api/token?grant_type=refresh_token&refresh_token=AQAdqYuGHig8gIwc9rf7ED4KZcPexZWeq3cRBxIUUaS7G3SsC8e7TG9oGEhGtE6PmknM2Pe_L09SQcXnnVudl80QoGhG4A5MsI_mn-hJos2ibLOPt59BWDVKnCRin9MDOv4";
}

//Function to parse the access token from authorization response
void SpotifyAPI::parseAccessToken(std::string& s) {	
	Json::Reader reader;
	Json::Value obj;

	reader.parse(s, obj);
	access_token = obj["access_token"].asString();
}

//Function to retrieve HTTP response of recently played spotify tracks once authorization complete
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

	//Nested JSON structure inside of items section, iterate through it to fetch tracks
	for(Json::Value::ArrayIndex i = 0; i != obj["items"].size(); i++) {
		recentSongs +=	"Song: " + obj["items"][i]["track"]["name"].asString() + ", ";
	}
}

//Function to begin authorization flow & once complete, trigger process of fetching, parsing, returning recently played tracks
std::string& SpotifyAPI::call() {

	//Access token expires every hour, therefore must authenticate on each API call to access song data
	struct curl_slist *headers;

  	headers = NULL;
  	headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
  	headers = curl_slist_append(headers, base_64_encoding_auth_request);
	
	curl_token_make = new CurlHelper(headers, refresh_request, "POST");
	spotify_auth_response = curl_token_make->get_response();
	
	parseAccessToken(spotify_auth_response);
	getRecentlyPlayedTracks();
	parseRecentTracks();

	return recentSongs;
}

