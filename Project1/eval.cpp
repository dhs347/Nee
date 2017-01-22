#include "String.h"
#include "Number.h"
#include <vector>
#include <string>
namespace nee {
	inline bool ___ISDIGIT(char c) {
		if (c >= '0' && c <= '9') {
			return true;
		}
		return false;
	}

	using Block = std::vector<std::string>;



	std::string eval(const Block &block) {
		int depth = 0;
		int max_depth = 0;
		for (size_t i = 0;i < block.size(); ++i) {
			if (depth < 0) {
				throw;
			}

			if (block[i] == "(") {
				++depth;
				if (depth > max_depth) {
					max_depth = depth;
				}
			}
			else if (block[i] == ")") {
				--depth;
			}
				
		}

		return "";
	}

	//+-*/%>< == >= <= != and or not -
	void eval_single(const Block &block) {

	}
	bool is_operator(const std::string &str) {
		if( str == "+" ||
		    str == "-" ||
		    str == "*" ||
		    str == "/" || 
		    str == "%" || 
		    str == ">" || 
			str == "<" || 
			str == "==" || 
			str == ">=" || 
			str == "<=" || 
			str == "!=" || 
			str == "and" || 
			str == "or" || 
			str == "not")
			return true;
		
		return false;
	}

	bool is_float(const std::string &str) {
		if (str.size() == 1)return false;//

		size_t point_pos = 0;
		for (size_t i = 0; i < str.size(); ++i) {
			if (str[i] == '.') {
				point_pos = i;
				break;
			}
		}

		for (size_t i = 0; i < str.size(); ++i) {
			if (!___ISDIGIT(str[i]) && i != point_pos) {
				return false;
			}
		}
		return true;
	}

	bool is_integer(const std::string &str) {

		for (size_t i = 0; i < str.size(); ++i) {
			if (!___ISDIGIT(str[i])) {
				return false;
			}
		}
		return true;
	}

	bool is_number(const std::string &str) {
		return is_float(str) || is_integer(str);
	}

	bool is_string(const std::string &str) {
		return true;
	}


}