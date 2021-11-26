#ifndef SPOTIFY_API_H
#define SPOTIFY_API_H

#include <string>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>
#include "APIInterface.h"
#include "CurlHelper.h"

class SpotifyAPI: public APIInterface{
	public:
		SpotifyAPI();
		~SpotifyAPI() = default;
		static size_t writefunc(void *ptr, size_t size, size_t nmemb, std::string *s);
		void parseAccessToken(std::string &s);
		void getRecentlyPlayedTracks();
		void parseRecentTracks();
		std::string& call() override;
	private:
		std::string spotify_auth_response;
		std::string spotify_songs_response;
		const char* base_64_encoding_auth_request;
		const char* refresh_request;
		std::string  access_token;
		std::string recentSongs;
		CurlHelper* curl_token_make;
		CurlHelper* curl_response_make;
};
#endif
