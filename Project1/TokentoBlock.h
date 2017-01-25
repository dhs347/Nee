#ifndef _TOKENTOBLOCK_H_
#define _TOKENTOBLOCK_H_
#include "Tokenizer.h"
#include "Eval.h"
namespace nee {
	class Block {

	};

	void TokentoBlock(const std::vector<std::string> &token) {
		std::vector<std::string> temptoken = token;
		std::vector<std::vector<std::string>> block;
		temptoken.insert(temptoken.begin(), "");
		temptoken.push_back("");
		for (size_t i = 1; i < temptoken.size() - 1; ++i) {
			if (temptoken[i] == "."&& is_integer(temptoken[i - 1]) && is_integer(temptoken[i + 1])) {
				std::string number = temptoken[i - 1] + "." + temptoken[i + 1];
				temptoken.erase(temptoken.begin() + i - 1, temptoken.begin() + i + 2);
				temptoken.insert(temptoken.begin() + i - 1, number);
				i = 0;
				continue;	
			}
		}
		temptoken.erase(temptoken.begin(), temptoken.begin() + 1);
		temptoken.pop_back();

		for (;;) {
			//todo
		}

	}
}
#endif // !_TOKENTOBLOCK_H_
