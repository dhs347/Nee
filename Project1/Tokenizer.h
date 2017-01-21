#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__
#include <fstream>
#include <string>
#include <vector>
#include <cctype> //isalpha


#include <iostream>

namespace nee {

	class Syntax_statement {
	public:
		void addString(const std::string &str) {
			_statement.push_back(str);
		}
	
	//private:
		std::vector<std::string> _statement;
	};

	inline int stringToken(char * buf) {
		int i = 1;
		while (true) {
			if (buf[i] == '\"'|| buf[i] == '\0') {
				break;
			}
			else if (buf[i] == '\\') {
				++i;
			}
			++i;
		}
		return i;
	}
	inline bool ___ISDIGIT(char c) {
		if (c >= '0' && c <= '9') {
			return true;
		}
		return false;
	}
	inline void Tokenizer(const std::string &filename) {
		std::ifstream ifs(filename.c_str(), std::ifstream::binary);
		ifs.seekg(0, ifs.end);
		int length = ifs.tellg();
		ifs.seekg(0, ifs.beg);
		// allocate memory:
		char * buffer = new char[length + 1];
		buffer[length] = 0;
		// read data as a block:
		ifs.read(buffer, length);
		ifs.close();
		//todo
		std::string tempStr;
		Syntax_statement stmt;
		bool number_point_flag = false;
		for (int i = 0; i < length; ++i) {
			if (buffer[i] == '_') {
				tempStr.push_back('_');
				number_point_flag = false;
			}
			else if(isalpha(static_cast<int>(buffer[i]))|| ___ISDIGIT(buffer[i]))//fix
			{
				tempStr.push_back(buffer[i]);
				if (___ISDIGIT(buffer[i])) {
					number_point_flag = true;
				}else number_point_flag = false;
			}
			else if (buffer[i] == ' ' || buffer[i] == '\t' || buffer[i] == '\n' || buffer[i] == '\r') {
				if (tempStr.size() != 0) {
					stmt.addString(tempStr);
				}
				number_point_flag = false;
				tempStr.clear();
			}
			else if (buffer[i] == '\"') {
				if (tempStr.size() != 0) {
					stmt.addString(tempStr);
				}
				tempStr.clear();
				int n = stringToken(&buffer[i]);
				stmt.addString(std::string(&buffer[i], n + 1));
				i += n;
				number_point_flag = false;
			}
			else {//����
				//judge .
				if (buffer[i] == '.'&&number_point_flag) {
					tempStr.push_back('.');
					continue;
				}


				if (tempStr.size() != 0) {
					stmt.addString(tempStr);

				}
				tempStr.clear();
				if (buffer[i] == '>' && buffer[i + 1] == '=') {
					stmt.addString(">=");
					++i;
				}
				else if (buffer[i] == '<' && buffer[i + 1] == '=') {
					stmt.addString("<=");
					++i;
				}
				else if (buffer[i] == '=' && buffer[i + 1] == '=') {
					stmt.addString("==");
					++i;
				}
				else if (buffer[i] == '!' && buffer[i + 1] == '=') {
					stmt.addString("!=");
					++i;
				}
				else {
					stmt.addString(std::string(&buffer[i],1));
				}
				number_point_flag = false;//fix
			}
		}
		for (size_t i = 0; i < stmt._statement.size(); ++i) {
			std::cout << stmt._statement[i] << std::endl;
		}
		delete[] buffer;
	}
}

#endif // !1

