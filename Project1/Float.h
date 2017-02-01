#ifndef __FLOAT_H__
#define __FLOAT_H__

#include "Object.h"
#include <string>
#include <algorithm>
namespace nee {
	class  Float :public Object {
	public:
		Float()noexcept : float_str() {}
		Float(const std::string &_str)noexcept : float_str(_str) {

			if (is_zero(float_str)) {
				float_str = "0.0";
			}

			eliminate_zero(float_str);
			std::reverse(float_str.begin(), float_str.end());
			eliminate_zero(float_str);
			std::reverse(float_str.begin(), float_str.end());

		}
		Float(const Float& r)noexcept : float_str(r.float_str) {}
		Float& operator=(const Float & r)noexcept {
			this->float_str = r.float_str;
			return *this;
		}
		Float& operator=(const std::string & r)noexcept {
			float_str = r;
			if (is_zero(float_str)) {
				float_str = "0.0";
			}

			eliminate_zero(float_str);
			std::reverse(float_str.begin(), float_str.end());
			eliminate_zero(float_str);
			std::reverse(float_str.begin(), float_str.end());

			return *this;
		}

		std::string ToString()  const noexcept{
			return float_str;
		}

		std::string type_name()  const noexcept {
			return std::string("float");
		}

		~Float() {}
	private:
		std::string float_str;

		bool is_zero(const std::string &str) {
			for (size_t i = 0;i < str.size(); ++i) {
				if (str[i] != '0' && str[i] != '.' && str[i] != '-') {
					return false;
				}
			}
			return true;
		}

		void eliminate_zero(std::string &str) {
			auto it = str.begin();
			if (*it == '-')
				++it;

			for (; it != str.end(); ++it) {
				if (*it != '0') {
					break;
				}
			}
			if (*it == '.') {
				if(*(str.begin()) == '-')
					str = "-0" + std::string(it, str.end());
				else str = "0" + std::string(it, str.end());
			}
			else {
				if (*(str.begin()) == '-')
					str = "-" + std::string(it, str.end());
				else str = std::string(it, str.end());
			}
		}

	};


}

#endif // !__FLOAT_H__