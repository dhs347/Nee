#include "String.h"
#include "Number.h"
#include "Number_Operator.h"
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

	bool is_operator(const std::string &str) {
		if (str == "+" ||
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
		if (str.at(0) == '-') {
			return is_float(std::string(str.begin() + 1, str.end())) || is_integer(std::string(str.begin() + 1, str.end()));
		}
		return is_float(str) || is_integer(str);
	}

	bool is_string(const std::string &str) {
		if (str.size() < 2) {
			return false;
		}
		if (str.at(str.size() - 1) != '\"' || str.at(0) != '\"') {
			return false;
		}
		std::string tempStr = std::string(str.begin() + 1, str.end() - 1);

		for (size_t i = 0; i < tempStr.size(); ++i) {
			if (tempStr.at(i) == '\\') {
				if (tempStr.at(i + 1) == '"' || tempStr.at(i + 1) == '\\' || tempStr.at(i + 1) == 'b' ||
					tempStr.at(i + 1) == 'f' || tempStr.at(i + 1) == 'n' || tempStr.at(i + 1) == 'r' || tempStr.at(i + 1) == 't') {
					++i;
				}
				else if (isalpha(static_cast<int>(tempStr.at(i + 1)))
					&& isalpha(static_cast<int>(tempStr.at(i + 2)))
					&& isalpha(static_cast<int>(tempStr.at(i + 3)))) {
					i += 3;
				}
				else {
					return false;
				}
			}
		}
		return true;
	}

	bool is_positive_number(const std::string &str) {
		return is_float(str) || is_integer(str);
	}

	//+-*/%>< == >= <= != and or not -
	bool _getpoint(const std::string &str) {
		
		for (size_t i = 0; i < str.size(); ++i) {
			if (str[i] == '.') {
				return true;
			}
		}
		return false;
	}

	void eval_single(const Block &block) {
		std::string eval_string;//todo
		Block temp = block;
		temp.insert(temp.begin(), std::string("("));
		temp.push_back(")");
		Block tempblock;
		for (size_t i = 1;i < temp.size() - 1;++i) {
			if (temp[i] == "-" && is_positive_number(temp[i+1]) && !is_number(temp[i - 1])) {
				std::string number = "-" + temp[i + 1];
				temp.erase(temp.begin() + i, temp.begin() + i + 2);
				temp.insert(temp.begin() + i, number);
				i = 0;
				continue;
			}

			if ((temp[i] == "*" || temp[i] == "/") && is_number(temp[i - 1]) && is_number(temp[i + 1])) {
				bool left = _getpoint(temp[i - 1]);
				bool right = _getpoint(temp[i + 1]);
				std::string number;
				//todo
			}


		}
	}



}