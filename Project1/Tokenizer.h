#ifndef __TOKENIZER_H__
#define __TOKENIZER_H__
#include <fstream>
namespace nee {

	inline void stringToken(char * &buf) {

	}
	inline void Tokenizer(const std::string &filename) {

		std::ifstream ifs(filename.c_str(), std::ifstream::binary);


		ifs.seekg(0, ifs.end);
		int length = ifs.tellg();
		ifs.seekg(0, ifs.beg);

		// allocate memory:
		char * buffer = new char[length];
		
		// read data as a block:
		ifs.read(buffer, length);
		ifs.close();

		//todo
		
		delete[] buffer;
	}
}

#endif // !1

