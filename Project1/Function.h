#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include "Object.h"
#include <string>
namespace nee {
	class  Function :public Object {
	public:

		std::string type_name()  const noexcept {
			return std::string("function");
		}
	private:
		size_t parameter_number;
	};
}
#endif // !__FUNCTION_H__
