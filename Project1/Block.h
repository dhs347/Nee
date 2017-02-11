
#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <cctype>
#include "Eval.h"
#include "TokentoBlock.h"


#include <iostream>

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

	inline nee_type get_type(const std::string &str) {
		nee_type _type;
		if (is_string(str)) {
			_type = NEE_STRING;
		}
		if (is_number(str)) {
			if (_getpoint(str)) {
				_type = NEE_FLOAT;
			}
			else _type = NEE_INTEGER;
		}
		if (is_bool(str)) {
			_type = NEE_BOOL;
		}
		if (str == "nil") {
			_type = NEE_NIL;
		}
		return _type;
	}

	inline bool is_variable(const std::string &str) {
		if (str.size() < 1) {
			return false;
		}
		if (str == "if" || str == "elif" || str == "else" || str == "then" ||
			str == "begin" || str == "end" || str == "while" || str == "loop" ||
			str == "and" || str == "or" || str == "not" || str == "function" || str == "do") {
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

	inline void process_block(variable_table& _v_table, std::vector<std::vector<std::string>> &block);

	inline void process_if(variable_table& _vt,const  std::vector<std::string> &_block) {
		if (_block.size() == 1) {
			throw;
		}
		//todo
		std::vector<std::string> _condition;
		std::vector<std::vector<std::string>> blocks;
		int depth = 1,_depth = 0;size_t pos = 0;
		std::vector<std::string> temp;


		for (size_t i = 0; i < _block.size(); ++i) {
			if (_block[i] == "loop" || _block[i] == "if" || _block[i] == "while") {
				++_depth;
			}
			if (_block[i] == "end") {
				--_depth;
			}
		}

		if (_depth != 0) {
			throw;
		}

		for (size_t i = 1; i < _block.size(); ++i) {

			if (_block[i] != "then") {
				temp.push_back(_block[i]);
			}
			else { pos = i + 1; break; }
		}

		//translate
		for (size_t i = 0; i < temp.size(); ++i) {
			if (is_variable(temp[i])) {
				auto _v = _vt.find(temp[i]);
				temp[i] = _v.value();
			}
		}
		//add if condition
		_condition.push_back(eval(temp));
		temp.clear();


		for (size_t i = pos;i < _block.size();++i) {
			
			if (_block[i] == "loop" || _block[i] == "if" || _block[i] == "while") {
				++depth;
			}
			if (_block[i] == "end") {
				--depth;
			}

			if (depth == 1 && (_block[i] == "elif" || _block[i] == "else")) {
				blocks.push_back(temp);
				temp.clear();
				if (_block[i] == "elif") {
					for (size_t j = i + 1; j < _block.size(); ++j) {
						if (_block[j] != "then") {
							temp.push_back(_block[j]);
						}
						else { pos = j; break; }
					}

					//translate
					for (size_t k = 0; k < temp.size(); ++k) {
						if (is_variable(temp[k])) {
							auto _v = _vt.find(temp[k]);
							temp[k] = _v.value();
						}
					}


					
					_condition.push_back(eval(temp));
					temp.clear();
					i = pos;

					//need add blocks

					continue;
				}
				else {
					//else
				
					blocks.push_back(std::vector<std::string>(_block.begin() + i + 1, _block.end() - 1));
					break;
					
				}
			}
			else {
				if (i != _block.size() - 1) {
					temp.push_back(_block[i]);
				}
			}

		}
		

		if (temp.size() != 0) {
			blocks.push_back(temp);
			temp.clear();
		}



		for (auto x : _condition) {
			std::cout << x << std::endl;
		}
		for (auto x : blocks) {
			for (auto y : x) {
				std::cout << y << std::endl;
			}std::cout <<  std::endl;
		}

		size_t _pos_ = 0;
		for (size_t i = 0;i < _condition.size(); ++i) {
			if (_condition[i] != "false" || _condition[i] != "nil") {
				_pos_ = i + 1;
				break;
			}
			
		}

		if (_pos_ == 0) {
			if (_condition.size() < blocks.size()) {
				//do else block
				//make blocks

				auto temp_block = TokentoBlock(blocks.at(blocks.size() - 1));
				process_block(_vt,temp_block);
	
			}
			else {
				//Don't do anything 
			}

		}
		else {
			//do _pos_ block
			//make blocks
			//for{
			//    process_block(_vt, blocks);
			//}

			auto temp_block = TokentoBlock(blocks.at(_pos_ - 1));
			process_block(_vt, temp_block);
		}

	}
	inline void process_loop(variable_table& _vt, const  std::vector<std::string> &_block){

	}
	inline void process_while(variable_table& _vt, const  std::vector<std::string> &_block) {

	}

	inline void process_variable(variable_table& _vt, const  std::vector<std::string> &_block) {
		if (_block.size() == 1) {
			auto _v = _vt.find(_block[0]);
			//std::cout << _v.value();
			//fix bug 
			return;
		}

		if (_block[1] == "=") {
			std::vector<std::string> tempblock = std::vector<std::string>(_block.begin()+2,_block.end());
			//translate
			for (size_t i = 0; i < tempblock.size();++i) {
				if (is_variable(tempblock[i])) {
					auto _v = _vt.find(tempblock[i]);

					tempblock[i] = _v.value();
				}
			}

			std::string value = eval(tempblock);
			//do eval
			//std::cout << value<< " " << get_type(value);

			_vt.insert(_block[0],get_type(value), value);
		}
		else if (_block[1] == "(") {
			//do function

			if (_block[_block.size() - 1] != ")") {
				throw;
			}
			//fix bug
			std::vector<std::string> tempblock = std::vector<std::string>(_block.begin() + 2, _block.end() - 1);

			//translate
			for (size_t i = 0; i < tempblock.size(); ++i) {
				if (is_variable(tempblock[i])) {
					auto _v = _vt.find(tempblock[i]);
					tempblock[i] = _v.value();
				}
			}
			//do hefa
			std::vector<std::string> parameter;

			std::vector<std::pair<std::string, nee_type>> arr_parameter;
			for (size_t i = 0; i < tempblock.size(); ++i) {
				if (tempblock[i] == ",") {
				/*	std::cout << parameter[0] << std::endl;*/
					std::string value = eval(parameter);
					
					arr_parameter.push_back(std::pair<std::string, nee_type>(value, get_type(value)));
					parameter.clear();
				}
				else {
					parameter.push_back(tempblock[i]);
				}
			}

			if (parameter.size() != 0) {
				std::string value = eval(parameter);
				arr_parameter.push_back(std::pair<std::string, nee_type>(value, get_type(value)));
				parameter.clear();
			}

			//todo function
			//std::cout << "function:" << std::endl;
			for (size_t i = 0;i < arr_parameter.size(); ++i) {
				std::cout << arr_parameter[i].first << " " << arr_parameter[i].second << std::endl;
			}

		}
		else {
			//eval

			std::vector<std::string> tempblock = _block;
			//translate
			for (size_t i = 0; i < tempblock.size(); ++i) {
				if (is_variable(tempblock[i])) {
					auto _v = _vt.find(tempblock[i]);

					tempblock[i] = _v.value();
				}
			}

			eval(tempblock);
		}

	}

	inline void process_block(variable_table& _v_table,std::vector<std::vector<std::string>> &block) {
		for (size_t i = 0;i < block.size(); ++i) {

			std::cout << "block:" << std::endl;

			if (block[i].size() == 0) {
				continue;
			}

			if (block[i][0] == "if") {
				process_if(_v_table, block[i]);
			}
			else if (block[i][0] == "loop") {

			}
			else if (block[i][0] == "while") {

			}
			else if (is_variable(block[i][0])) {
				//std::cout << "var";
				process_variable(_v_table, block[i]);
			}
			else {
				throw;
			}
			//todo
		}
	}
}

#endif // !_BLOCK_H_

