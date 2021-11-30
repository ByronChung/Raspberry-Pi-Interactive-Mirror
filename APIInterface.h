/*!
 @brief Interface to define general API object
 Different types of API objects implement interface (evident by pure virtual function); created to implement Factory design pattern and reduce coupling
 @author Ashwin Singh 
 */
 
#ifndef API_INTERFACE_H
#define API_INTERFACE_H

#include <string>

class APIInterface {
	public:
		/*!
 		 @brief Call API and return response string
 		 Perform API authentication (if needed), make request, parse raw JSON response into a formatted string and return to UI for display
		 @param None
		 @return Address of response string 
		*/
		virtual std::string& call() = 0;
};
#endif
