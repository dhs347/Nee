#ifndef _library_h_
#define _library_h_
#include <iostream>
#include <cstdlib>
#include <functional>
#include "Type.h"
#include "String.h"


namespace nee {

	
	inline nee_Value print(nee_State &s) {
		//

		for (size_t i = 0; i < s.size(); ++i) {
			//fix String bug
			if (s[i].first.size() >=2 && s[i].first.at(0) == '\"') {
				std::cout << String(s[i].first).ToString();
			}
			else std::cout << s[i].first ;

			if (i != s.size() - 1) {
				std::cout << ' ';
			}

		}

		return "nil";
	}

	inline nee_Value exit(nee_State &s) {
		//
		if (s.size() != 0) {
			throw;
		}

		::exit(0);

		return "nil";
	}

	inline  nee_Value system(nee_State &s) {
		if (s.size() != 1) {
			throw;
		}
		::system(String(s[0].first).ToString().c_str());
		return "nil";
	}

	inline bool is_function(const std::string&str) {
		if (str == "exit" || str == "print" || str == "system") {
			return true;
		}
		return false;
	}


	inline void init_function(std::unordered_map<std::string, std::function<nee_Value(nee_State &)> > & fun) {

		fun["exit"] = exit;
		fun["print"] = print;
		fun["system"] = system;
	
	}

	inline nee_Value do_function(std::unordered_map< std::string, std::function<nee_Value(nee_State &)> > &x ,const char *functionname,nee_State &s) {
		nee_Value temp;

		if(x.empty())
			init_function(x);
		auto it = x.find(std::string(functionname));

		if (it == x.end()) {
			throw;
		}
		else {
			(it->second)(s);
		}

		return temp;
	}

}



#endif // !_library_h_
