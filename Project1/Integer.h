#ifndef __INTEGER_H__
#define __INTEGER_H__

#include "Object.h"
#include <string>
namespace nee {
	class  Integer :public Object {
	public:
		Integer()noexcept :integer_str() {}
		Integer(std::string _str)noexcept :integer_str(_str) {}
		Integer(const Integer & r)noexcept : integer_str(r.integer_str) {}
		Integer& operator=(const Integer & r)noexcept {
			this->integer_str = r.integer_str;
			return *this;
		}
		std::string ToString() const noexcept {
			return integer_str;
		}

		~Integer() {}
	private:
		std::string integer_str;
	};
}
#endif // !1