#ifndef __STRING_H___
#define __STRING_H___

#include "Object.h"
#include <string>
#include <cctype> //isalpha
namespace nee {
	class  String :public Object {
	public:
		String()noexcept : str() , true_str(){}
		String(const std::string &_str):str(_str), true_str(){
			std::string tempStr = std::string(_str.begin() + 1,_str.end() - 1);

			for (size_t i = 0; i < tempStr.size(); ++i) {
				if (tempStr.at(i) == '\\') {
					if (tempStr.at(i + 1) == '"' || tempStr.at(i + 1) == '\\' || tempStr.at(i + 1) == 'b' ||
						tempStr.at(i + 1) == 'f' || tempStr.at(i + 1) == 'n' || tempStr.at(i + 1) == 'r'  || tempStr.at(i + 1) == 't') {
						++i;
					}
					else if (isalpha(static_cast<int>(tempStr.at(i + 1))) 
						  && isalpha(static_cast<int>(tempStr.at(i + 2)))
						  && isalpha(static_cast<int>(tempStr.at(i + 3)))) {
						i += 3;
					}
					else {
						throw;
					}
				}
			}

			_translate(tempStr);


		}
		String(const String & r)noexcept :str(r.str),true_str(r.true_str) {}
		String& operator=(const String & r)noexcept {
			this->str = r.str;
			this->true_str = r.true_str;
			return *this;
		}
		std::string ToString() const noexcept {
			return true_str;
		}

		~String() {}
	private:
		void _translate(const std::string &str) {
			for (size_t i = 0;i < str.size(); ++i) {
				if (str.at(i) == '\\') {
					if (str.at(i + 1) == '"') {
						true_str.push_back('"');
						++i;
					}
					else if(str.at(i + 1) == '\\')
					{
						true_str.push_back('\\');
						++i;
					}
					else if (str.at(i + 1) == 'b')
					{
						true_str.push_back('\b');
						++i;
					}
					else if (str.at(i + 1) == 'f')
					{
						true_str.push_back('\f');
						++i;
					}
					else if (str.at(i + 1) == 'n')
					{
						true_str.push_back('\n');
						++i;
					}
					else if (str.at(i + 1) == 'r')
					{
						true_str.push_back('\r');
						++i;
					}
					else if (str.at(i + 1) == 't')
					{
						true_str.push_back('\t');
						++i;
					}
					else {
						true_str.push_back(static_cast<char>(100 * (str.at(i + 1) - '0') + 10 * (str.at(i + 2) - '0') + (str.at(i + 3) - '0')));
						i += 3;
					}
				}
				else true_str.push_back(str.at(i));
			}
		}

		std::string str;
		std::string true_str;
	};
}
#endif
