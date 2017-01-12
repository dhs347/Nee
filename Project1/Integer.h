#ifndef __INTEGER_H__
#define __INTEGER_H__

#include "Object.h"
#include <string>
namespace nee {
	class  Integer :public Object {
	public:
		Integer()noexcept :integer_str() {}
		Integer(const std::string &_str)noexcept :integer_str(_str) {
			eliminate_zero(integer_str);
		}
		Integer(const Integer & r)noexcept : integer_str(r.integer_str) {}
		Integer& operator=(const Integer & r)noexcept {
			this->integer_str = r.integer_str;
			return *this;
		}

		Integer& operator=(const std::string & r)noexcept {
			integer_str = r;
			eliminate_zero(integer_str);
			return *this;
		}
		std::string ToString() const noexcept {
			return integer_str;
		}

		~Integer() {}
	private:
		std::string integer_str;

		void eliminate_zero(std::string &str) {
			auto it = str.begin();
			if (*it == '-')
				++it;

			for (; it != str.end(); ++it) {
				if (*it != '0') {
					break;
				}
			}
			if (*str.begin() == '-') {
				if(it!= str.end())
					str = "-" + std::string(it, str.end());
				else str = "0";//fix
			}
			else {
				if (it != str.end())
					str = std::string(it, str.end());
				else str = "0";
			}
		}
	};
}
#endif // !1