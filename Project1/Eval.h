
#ifndef _EVAL_H_
#include "String.h"
#include "Number.h"
#include "Number_Operator.h"
#include <vector>
#include <string>
#include <cstring>
namespace nee {
	inline bool ____ISDIGIT(char c) {
		if (c >= '0' && c <= '9') {
			return true;
		}
		return false;
	}

	inline std::string eval(const std::vector<std::string> &block) {
		int depth = 0;
		int max_depth = 0;
		for (size_t i = 0; i < block.size(); ++i) {
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

	inline bool is_operator(const std::string &str) {
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

	inline bool is_float(const std::string &str) {
		if (str.size() == 1)return false;//

		size_t point_pos = 0;
		for (size_t i = 0; i < str.size(); ++i) {
			if (str[i] == '.') {
				point_pos = i;
				break;
			}
		}

		for (size_t i = 0; i < str.size(); ++i) {
			if (!____ISDIGIT(str[i]) && i != point_pos) {
				return false;
			}
		}
		return true;
	}

	inline bool is_integer(const std::string &str) {

		for (size_t i = 0; i < str.size(); ++i) {
			if (!____ISDIGIT(str[i])) {
				return false;
			}
		}
		return true;
	}


	inline bool is_number(const std::string &str) {
		if (str.at(0) == '-') {
			return is_float(std::string(str.begin() + 1, str.end())) || is_integer(std::string(str.begin() + 1, str.end()));
		}
		return is_float(str) || is_integer(str);
	}

	inline bool is_string(const std::string &str) {
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

	inline bool is_positive_number(const std::string &str) {
		return is_float(str) || is_integer(str);
	}

	inline bool is_bool(const std::string &str) {
		return (str == "true") || (str == "false");
	}

	inline bool is_legal_value(const std::string &str) {
		return is_bool(str) || is_number(str) || is_string(str) || (str == "nil");
	}


	//+-*/%>< == >= <= != and or not -
	inline bool _getpoint(const std::string &str) {

		for (size_t i = 0; i < str.size(); ++i) {
			if (str[i] == '.') {
				return true;
			}
		}
		return false;
	}
	inline std::string arithmetic(const std::string &op, const std::string &left, const std::string &right) {
		std::string result;
		if (op == "*") {
			bool bool_left = _getpoint(left);
			bool bool_right = _getpoint(right);
			if (bool_left && bool_right) {
				result = (Float(left) * Float(right)).ToString();
			}
			else if (bool_left && !bool_right) {
				result = (Float(left) * Integer(right)).ToString();
			}
			else if (!bool_left&&bool_right) {
				result = (Float(right) * Integer(left)).ToString();
			}
			else {
				result = (Integer(left) * Integer(right)).ToString();
			}
		}
		else if (op == "/") {
			bool bool_left = _getpoint(left);
			bool bool_right = _getpoint(right);
			if (bool_left && bool_right) {
				result = (Float(left) / Float(right)).ToString();
			}
			else if (bool_left && !bool_right) {
				result = (Float(left) / Integer(right)).ToString();
			}
			else if (!bool_left&&bool_right) {
				result = (Integer(left) / Float(right)).ToString();
			}
			else {
				result = (Integer(left) / Integer(right)).ToString();
			}
		}
		else if (op == "+") {
			bool bool_left = _getpoint(left);
			bool bool_right = _getpoint(right);
			if (bool_left && bool_right) {
				result = (Float(left) + Float(right)).ToString();
			}
			else if (bool_left && !bool_right) {
				result = (Float(left) + Integer(right)).ToString();
			}
			else if (!bool_left&&bool_right) {
				result = (Integer(left) + Float(right)).ToString();
			}
			else {
				result = (Integer(left) + Integer(right)).ToString();
			}
		}
		else if (op == "-") {
			bool bool_left = _getpoint(left);
			bool bool_right = _getpoint(right);
			if (bool_left && bool_right) {
				result = (Float(left) - Float(right)).ToString();
			}
			else if (bool_left && !bool_right) {
				result = (Float(left) - Integer(right)).ToString();
			}
			else if (!bool_left&&bool_right) {
				result = (Integer(left) - Float(right)).ToString();
			}
			else {
				result = (Integer(left) - Integer(right)).ToString();
			}
		}
		else if (op == ">") {
			bool bool_left = _getpoint(left);
			bool bool_right = _getpoint(right);
			if (bool_left && bool_right) {
				bool cmp = (Float(left) > Float(right));
				if (cmp) {
					result = "true";
				}
				else result = "false";
			}
			else if (bool_left && !bool_right) {
				bool cmp = (Float(left) > Integer(right));
				if (cmp) {
					result = "true";
				}
				else result = "false";
			}
			else if (!bool_left&&bool_right) {
				bool cmp = (Integer(left) > Float(right));
				if (cmp) {
					result = "true";
				}
				else result = "false";
			}
			else {
				bool cmp = (Integer(left) > Integer(right));
				if (cmp) {
					result = "true";
				}
				else result = "false";
			}
		}
		else if (op == ">=") {
			bool bool_left = _getpoint(left);
			bool bool_right = _getpoint(right);
			if (bool_left && bool_right) {
				bool cmp = (Float(left) >= Float(right));
				if (cmp) {
					result = "true";
				}
				else result = "false";
			}
			else if (bool_left && !bool_right) {
				bool cmp = (Float(left) >= Integer(right));
				if (cmp) {
					result = "true";
				}
				else result = "false";
			}
			else if (!bool_left&&bool_right) {
				bool cmp = (Integer(left) >= Float(right));
				if (cmp) {
					result = "true";
				}
				else result = "false";
			}
			else {
				bool cmp = (Integer(left) >= Integer(right));
				if (cmp) {
					result = "true";
				}
				else result = "false";
			}
		}
		else if (op == "<") {
			bool bool_left = _getpoint(left);
			bool bool_right = _getpoint(right);
			if (bool_left && bool_right) {
				bool cmp = (Float(left) < Float(right));
				if (cmp) {
					result = "true";
				}
				else result = "false";
			}
			else if (bool_left && !bool_right) {
				bool cmp = (Float(left) < Integer(right));
				if (cmp) {
					result = "true";
				}
				else result = "false";
			}
			else if (!bool_left&&bool_right) {
				bool cmp = (Integer(left) < Float(right));
				if (cmp) {
					result = "true";
				}
				else result = "false";
			}
			else {
				bool cmp = (Integer(left) < Integer(right));
				if (cmp) {
					result = "true";
				}
				else result = "false";
			}
		}
		else if (op == "<=") {
			bool bool_left = _getpoint(left);
			bool bool_right = _getpoint(right);
			if (bool_left && bool_right) {
				bool cmp = (Float(left) <= Float(right));
				if (cmp) {
					result = "true";
				}
				else result = "false";
			}
			else if (bool_left && !bool_right) {
				bool cmp = (Float(left) <= Integer(right));
				if (cmp) {
					result = "true";
				}
				else result = "false";
			}
			else if (!bool_left&&bool_right) {
				bool cmp = (Integer(left) <= Float(right));
				if (cmp) {
					result = "true";
				}
				else result = "false";
			}
			else {
				bool cmp = (Integer(left) <= Integer(right));
				if (cmp) {
					result = "true";
				}
				else result = "false";
			}
		}
		else if (op == "==") {
			bool bool_left = _getpoint(left);
			bool bool_right = _getpoint(right);
			if (bool_left && bool_right) {
				bool cmp = (Float(left) == Float(right));
				if (cmp) {
					result = "true";
				}
				else result = "false";
			}
			else if (bool_left && !bool_right) {
				bool cmp = (Float(left) == Integer(right));
				if (cmp) {
					result = "true";
				}
				else result = "false";
			}
			else if (!bool_left&&bool_right) {
				bool cmp = (Integer(left) == Float(right));
				if (cmp) {
					result = "true";
				}
				else result = "false";
			}
			else {
				bool cmp = (Integer(left) == Integer(right));
				if (cmp) {
					result = "true";
				}
				else result = "false";
			}
		}
		else if (op == "!=") {
			bool bool_left = _getpoint(left);
			bool bool_right = _getpoint(right);
			if (bool_left && bool_right) {
				bool cmp = (Float(left) != Float(right));
				if (cmp) {
					result = "true";
				}
				else result = "false";
			}
			else if (bool_left && !bool_right) {
				bool cmp = (Float(left) != Integer(right));
				if (cmp) {
					result = "true";
				}
				else result = "false";
			}
			else if (!bool_left&&bool_right) {
				bool cmp = (Integer(left) != Float(right));
				if (cmp) {
					result = "true";
				}
				else result = "false";
			}
			else {
				bool cmp = (Integer(left) != Integer(right));
				if (cmp) {
					result = "true";
				}
				else result = "false";
			}
		}
		return result;
	}
	inline std::string eval_single(const std::vector<std::string> &block) {
		std::string eval_string;//todo
		std::vector<std::string> temp = block;
		temp.insert(temp.begin(), std::string("("));
		temp.push_back(")");
		std::vector<std::string> tempblock;
		for (size_t i = 1; i < temp.size() - 1; ++i) {
			if (temp[i] == "-" && is_positive_number(temp[i + 1]) && !is_number(temp[i - 1])) {
				std::string number = "-" + temp[i + 1];
				temp.erase(temp.begin() + i, temp.begin() + i + 2);
				temp.insert(temp.begin() + i, number);
				i = 0;
				continue;
			}
		}
		for (size_t i = 1; i < temp.size() - 1; ++i) {
			if ((temp[i] == "*" || temp[i] == "/") && is_number(temp[i - 1]) && is_number(temp[i + 1])) {
				std::string number = arithmetic(temp[i], temp[i - 1], temp[i + 1]);
				//todo
				temp.erase(temp.begin() + i - 1, temp.begin() + i + 2);
				temp.insert(temp.begin() + i - 1, number);
				i = 0;
				continue;
			}
		}
		for (size_t i = 1; i < temp.size() - 1; ++i) {
			if ((temp[i] == "+" || temp[i] == "-") && is_number(temp[i - 1]) && is_number(temp[i + 1])) {
				std::string number = arithmetic(temp[i], temp[i - 1], temp[i + 1]);
				//todo
				temp.erase(temp.begin() + i - 1, temp.begin() + i + 2);
				temp.insert(temp.begin() + i - 1, number);
				i = 0;
				continue;
			}
		}
		for (size_t i = 1; i < temp.size() - 1; ++i) {
			if (temp[i] == ">" || temp[i] == ">=" || temp[i] == "<" || temp[i] == "<=") {
				if (is_string(temp[i - 1]) && is_string(temp[i + 1])) {
					String left(temp[i - 1]);
					String right(temp[i + 1]);
					int res = strcmp(left.ToString().c_str(), right.ToString().c_str());
					std::string res_str;
					if (res == 1 && temp[i] == ">") {
						res_str = "true";
					}
					else if (res == 1 && temp[i] == ">=") {
						res_str = "true";
					}
					else if (res == 1 && temp[i] == "<") {
						res_str = "false";
					}
					else if (res == 1 && temp[i] == "<=") {
						res_str = "false";
					}
					//
					else if (res == 0 && temp[i] == ">") {
						res_str = "false";
					}
					else if (res == 0 && temp[i] == ">=") {
						res_str = "true";
					}
					else if (res == 0 && temp[i] == "<") {
						res_str = "false";
					}
					else if (res == 0 && temp[i] == "<=") {
						res_str = "true";
					}
					//
					else if (res == -1 && temp[i] == ">") {
						res_str = "false";
					}
					else if (res == -1 && temp[i] == ">=") {
						res_str = "false";
					}
					else if (res == -1 && temp[i] == "<") {
						res_str = "true";
					}
					else if (res == -1 && temp[i] == "<=") {
						res_str = "true";
					}

					temp.erase(temp.begin() + i - 1, temp.begin() + i + 2);
					temp.insert(temp.begin() + i - 1, res_str);
					i = 0;
					continue;
				}
				else if (is_number(temp[i - 1]) && is_number(temp[i + 1])) {
					std::string number = arithmetic(temp[i], temp[i - 1], temp[i + 1]);
					temp.erase(temp.begin() + i - 1, temp.begin() + i + 2);
					temp.insert(temp.begin() + i - 1, number);
					i = 0;
					continue;
				}
			}
		}
		for (size_t i = 1; i < temp.size() - 1; ++i) {
			if ((temp[i] == "==" || temp[i] == "!=")) {
				if (is_string(temp[i - 1]) && is_string(temp[i + 1])) {
					bool cmp = String(temp[i - 1]).ToString() == String(temp[i + 1]).ToString();
					std::string res_str;
					if (cmp && temp[i] == "==") {
						res_str = "true";
					}
					else if (!cmp && temp[i] == "!=") {
						res_str = "true";
					}
					else res_str = "false";

					temp.erase(temp.begin() + i - 1, temp.begin() + i + 2);
					temp.insert(temp.begin() + i - 1, res_str);
					i = 0;
					continue;
				}
				else if (is_number(temp[i - 1]) && is_number(temp[i + 1])) {
					std::string number = arithmetic(temp[i], temp[i - 1], temp[i + 1]);
					temp.erase(temp.begin() + i - 1, temp.begin() + i + 2);
					temp.insert(temp.begin() + i - 1, number);
					i = 0;
					continue;
				}
				else if (is_bool(temp[i - 1]) && is_bool(temp[i + 1])) {
					std::string res_str;
					if (temp[i] == "==" && temp[i - 1] == temp[i + 1]) {
						res_str = "true";
					}
					else if (temp[i] == "==" && temp[i - 1] != temp[i + 1]) {
						res_str = "false";
					}
					else if (temp[i] == "!=" && temp[i - 1] == temp[i + 1]) {
						res_str = "false";
					}
					else if (temp[i] == "!=" && temp[i - 1] != temp[i + 1]) {
						res_str = "true";
					}
					temp.erase(temp.begin() + i - 1, temp.begin() + i + 2);
					temp.insert(temp.begin() + i - 1, res_str);
					i = 0;
					continue;

				}
				else if (temp[i - 1] == "nil" && temp[i + 1] == "nil") {
					std::string res_str;
					if (temp[i] == "==") {
						res_str = "true";
					}
					else res_str = "false";
					temp.erase(temp.begin() + i - 1, temp.begin() + i + 2);
					temp.insert(temp.begin() + i - 1, res_str);
					i = 0;
					continue;
				}

			}
		}

		for (size_t i = 1; i < temp.size() - 1; ++i) {
			if (temp[i] == "and" && is_legal_value(temp[i - 1]) && is_legal_value(temp[i + 1])) {
				std::string res_str;
				if (temp[i - 1] == "nil" || temp[i - 1] == "false") {
					res_str = temp[i - 1];
				}
				else res_str = temp[i + 1];
				temp.erase(temp.begin() + i - 1, temp.begin() + i + 2);
				temp.insert(temp.begin() + i - 1, res_str);
				i = 0;
				continue;

			}
		}
		for (size_t i = 1; i < temp.size() - 1; ++i) {
			if (temp[i] == "or" && is_legal_value(temp[i - 1]) && is_legal_value(temp[i + 1])) {
				std::string res_str;
				if (temp[i - 1] == "nil" || temp[i - 1] == "false") {
					res_str = temp[i + 1];
				}
				else res_str = temp[i - 1];
				temp.erase(temp.begin() + i - 1, temp.begin() + i + 2);
				temp.insert(temp.begin() + i - 1, res_str);
				i = 0;
				continue;

			}
		}

		if (temp.size() != 3) {
			throw;
		}
		return temp[1];
	}

}
#endif // !_EVAL_H_

