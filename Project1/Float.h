#ifndef __FLOAT_H__
#define __FLOAT_H__

#include "Object.h"
#include <string>
namespace nee {
	class  Float :public Object {
	public:
		std::string ToString()  const noexcept{
			return float_str;
		}
	private:
		std::string float_str;

	};

	class Efloat :public Object {
	public:
		std::string ToString() const noexcept{
			return efloat_str;
		}
	private:
		std::string efloat_str;
	

	};
}

#endif // !__FLOAT_H__