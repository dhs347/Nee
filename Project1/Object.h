#ifndef __OBJECT_H__
#define __OBJECT_H__
#include <string>
namespace nee {
	class Object {
	public:
		std::string type_name()  const noexcept {
			return std::string("object");
		}
		virtual ~Object(){}
	};
}
#endif // !__OBJECT_H__
