//Class to retrieve pinned Tweet from Jack Dorsey's Twitter account

#include "TwitterAPI.h"

//Constructor to store bearer token
TwitterAPI::TwitterAPI(void){
    auth_request = "Authorization: Bearer AAAAAAAAAAAAAAAAAAAAADQDWQEAAAAAlXOh32lmggqTqEcJnMcUfhx9lB8%3DTdJu6nlmZY5HalE4AfTZ3TMKMtGQ1NPQc46WaZ25hlm0FK6QJE";
}

//Function to retrieve HTTP response of pinned Tweets
void TwitterAPI::getTweets() {
	struct curl_slist *headers;

	headers = NULL;

	headers = curl_slist_append(headers, auth_request);

	curl_response_make = new CurlHelper(headers, "https://api.twitter.com/2/users/by?usernames=jack&user.fields=created_at&expansions=pinned_tweet_id&tweet.fields=author_id,created_at", "GET");
	twitter_response = curl_response_make->get_response();
}

//Function to parse HTTP response
void TwitterAPI::parseTweet() {
	Json::Reader reader;
	Json::Value obj;

	reader.parse(twitter_response, obj);
	for(Json::Value::ArrayIndex i = 0; i != obj["data"].size(); i++){
		name +=  obj["data"][i]["name"].asString();
		description += obj["includes"]["tweets"][i]["text"].asString();
	}

     	name = "Username:  "  + name + " Tweets: " + description;

}
//Function to begin authorization flow, trigger calling, and parsing of data
std::string& TwitterAPI::call() {
	getTweets();
	parseTweet();

	return name;
}
