#ifndef __STRING_H___
#define __STRING_H___

#include "Object.h"
#include <string>
namespace nee {
	class  String :public Object {
	public:
		String()noexcept : str() {}
		String(const std::string &_str)noexcept :str(_str) {}
		String(const String & r)noexcept :str(r.str) {}
		String& operator=(const String & r)noexcept {
			this->str = r.str;
			return *this;
		}
		std::string ToString() const noexcept {
			return str;
		}

		~String() {}
	private:
		std::string str;
	};
}
#endif
