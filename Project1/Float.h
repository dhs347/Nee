#ifndef __FLOAT_H__
#define __FLOAT_H__

#include "Object.h"
#include <string>
namespace nee {
	class  Float :public Object {
	public:
		Float()noexcept : float_str() {}
		Float(const std::string &_str)noexcept : float_str(_str) {}
		Float(const Float& r)noexcept : float_str(r.float_str) {}
		Float& operator=(const Float & r)noexcept {
			this->float_str = r.float_str;
			return *this;
		}
		std::string ToString()  const noexcept{
			return float_str;
		}

		~Float() {}
	private:
		std::string float_str;

	};

	class Efloat :public Object {
	public:
		Efloat()noexcept : efloat_str() {}
		Efloat(const std::string &_str)noexcept : efloat_str(_str) {}
		Efloat(const Efloat& r)noexcept : efloat_str(r.efloat_str) {}
		Efloat& operator=(const Efloat & r)noexcept {
			this->efloat_str = r.efloat_str;
			return *this;
		}
		std::string ToString() const noexcept{
			return efloat_str;
		}

		~Efloat() {}
	private:
		std::string efloat_str;
	

	};
}

#endif // !__FLOAT_H__