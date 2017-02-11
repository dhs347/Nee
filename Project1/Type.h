#pragma once
#ifndef _TYPE_H__
#define _TYPE_H__
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

namespace nee {


	enum nee_type
	{
		NEE_STRING, NEE_FLOAT, NEE_INTEGER, NEE_BOOL, NEE_NIL, NEE_FUNCTION//maybe add
	};
	class variable {
	public:
		void set_variable(nee_type type, const std::string&str) {
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
	class variable_table {
	public:
		void insert(const std::string &name, nee_type _type, const std::string &value) {
			auto it = _variable.find(name);
			variable _v;
			_v.set_variable(_type, value);
			if (it == _variable.end()) {
				_variable.insert({ name,_v });
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


	

	using   nee_Value = std::string;
	using   nee_State = std::vector<std::pair<std::string, nee_type>>;
}
#endif // !_TYPE_H__
