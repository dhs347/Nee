
#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <vector>
#include <string>
#include <unordered_map>
#include <cctype>
#include "Eval.h"
namespace nee {
	enum nee_type
	{
		NEE_STRING,NEE_FLOAT,NEE_INTEGER,NEE_BOOL,NEE_NIL,NEE_FUNCTION//maybe add
	};
	class variable {
	public:
		void set_variable(nee_type type,const std::string&str) {
			_type = type;
			_value = str;
		}
		std::string value() {
			return _value;
		}
	private:
		nee_type _type;
		std::string _value;
	};
	class variable_table{
	public:
		void insert(const std::string &name,nee_type _type,const std::string &value) {
			auto it = _variable.find(name);
			variable _v;
			_v.set_variable(_type, value);
			if (it == _variable.end()) {
				_variable.insert({name,_v});
			}
			else { _variable[name] = _v; }

		}
		variable find(const std::string &name) {
			auto it = _variable.find(name);
			variable _v;
			if (it == _variable.end()) {
				_v.set_variable(NEE_NIL, "nil");
			}
			else {
				_v = it->second;
			}
			return _v;
		}
	private:
		std::unordered_map<std::string, variable> _variable;
	};

	inline bool is_variable(const std::string &str) {
		if (str.size() < 1) {
			return false;
		}
		if (str == "if" || str == "elif" || str == "else" || str == "then" ||
			str == "begin" || str == "end" || str == "while" || str == "loop" ||
			str == "and" || str == "or" || str == "not" ) {
			return false;
		}

		if (str[0] != '_' && !isalpha(static_cast<int>(str[0]))) {
			return false;
		}
		for (size_t i = 1;i < str.size(); ++i) {
			if (str[i] != '_' && !isalpha(static_cast<int>(str[i])) &&  !isdigit(static_cast<int>(str[i]))) {
				return false;
			}
		}
		return true;
	}
	void process_if(variable_table& _vt,const  std::vector<std::string> &_block) {

	}
	void process_loop(variable_table& _vt, const  std::vector<std::string> &_block){

	}
	void process_while(variable_table& _vt, const  std::vector<std::string> &_block) {

	}

	void process_variable(variable_table& _vt, const  std::vector<std::string> &_block) {
		if (_block.size() == 1) {
			//todo
		}

		if (_block[1] == "=") {
			std::string value = eval()
			//do eval
		}
		else if (_block[1] == "(") {
			//do function
		}
		else {
			throw;
		}

	}

	inline void process_block(std::vector<std::vector<std::string>> &block) {
		variable_table _v_table;
		for (size_t i = 0;i < block.size(); ++i) {
			if (block[i].size() == 0) {
				continue;
			}

			if (block[i][0] == "if") {

			}
			else if (block[i][0] == "loop") {

			}
			else if (block[i][0] == "while") {

			}
			else if (is_variable(block[i][0])) {

			}
			else {
				throw;
			}
			//todo
		}
	}
}

#endif // !_BLOCK_H_

