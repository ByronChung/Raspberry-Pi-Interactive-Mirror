/*!
 @brief Class used to handle data processing 
 Class generates an API object using the APIFactory Class & then performs HTTP request on the API object, receives a response and stores it
*/

#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <string>
#include "APIFactory.h"

class Model {
	public:
		Model();
		~Model() = default;
		/*!
 		 @brief Store API data depending on button clicked in UI
 		 Formulate API object depending on string passed from UI upon button click, then perform HTTP request and store response to data member api_out
		 @param Address of string passed from UI
		 @return None
		 @author Ashwin Singh
		 */
		void update(std::string& s);
		/*!
 		 @brief Getter to return formatted API response
 		 Return response stored in data member api_out string
		 @param None
		 @return Response string api_out
		 @author Ashwin Singh
		 */
		std::string& show_out(void);
	private:
		APIInterface* api;
		APIFactory factory;
		std::string api_out;

};
#endif

