#ifndef _library_h_
#define _library_h_
#include <iostream>
#include "Type.h"


namespace nee {

	
	inline nee_Value print(nee_State &s) {
		//

		for (size_t i = 0; i < s.size(); ++i) {
			std::cout << s[i].first ;

			if (i != s.size() - 1) {
				std::cout << ' ';
			}

		}

		return "nil";
	}
	inline nee_Value do_function(const char *functionname,nee_State &s) {
		nee_Value temp;

		if (std::string(functionname) == std::string("print")) {
			temp = print(s);
		}
		else {
			// not found
			throw;
		}

		return temp;
	}




	inline void Lib_Init() {
		//
	}





}



#endif // !_library_h_
