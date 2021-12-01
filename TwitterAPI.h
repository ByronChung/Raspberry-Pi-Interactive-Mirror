/*!
@brief Class used to interface with Twitter API
Class performs Twitter API authentication using a refresh token & then performs API call to fetch recent tweets from a dummy account
*/

#ifndef TWITTER_API_H
#define TWITTER_API_H

#include <iostream>
#include <string>
#include <curl/curl.h>
#include <jsoncpp/json/json.h>
#include "APIInterface.h"
#include "CurlHelper.h"

class TwitterAPI: public APIInterface {
	public:
		/*!
		@brief Initialize data member auth_request for later use with Twitter API authentication
		@param none
		@return none
		@author Byron Chung, Pablo Ortega, Ashvinder Suri
		*/
		TwitterAPI();
		~TwitterAPI() = default;
		
		/*!
		@brief Using auth_request trigger API call to retrieve recent Tweet
		Retrieve raw JSON response of recent tweet from Twitter API using cURL
		@param None
		@return None
		@author Byron Chung, Pablo Ortega, Ashvinder Suri
		*/
		void getTweets();
        
		/*!
		@brief Parse response to retrieve recent Tweets
		Store parse resonse in appropriate holder variable
		@param None
		@return None
		@author Byron Chung, Pablo Ortega, Ashvinder Suri
		*/
		void parseTweet();
		
		/*!
		@brief Implemented function based on APIInterface; Perform authentication, retrieve tweet and store
		Use auth_request with cURL HTTP request to the Twitter access URL, then call other functions to retrieve twitter data & store
		@param None
		@return None
		@author Byron Chung, Pablo Ortega, Ashvinder Suri
		*/
		std::string& call() override;
	private:
        	const char *auth_request;
		std::string twitter_response;
        	std::string recentTweets;
		std::string name;
		std::string description;
		CurlHelper *curl_response_make;
};
#endif
