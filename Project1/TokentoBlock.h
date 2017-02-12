#ifndef _TOKENTOBLOCK_H_
#define _TOKENTOBLOCK_H_
#include "Tokenizer.h"
#include "Eval.h"
namespace nee {

	inline std::vector<std::vector<std::string>> TokentoBlock(const std::vector<std::string> &token) {
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
		auto beginit = temptoken.begin();
		for (auto it = temptoken.begin();it != temptoken.end(); ++it) {
			//todo
			//loop while if
			if (*it == "loop"|| *it == "while" || *it == "if" ) {
				std::vector <std::string> singal_block;
				size_t depth = 0;
	
				for (;it != temptoken.end(); ++it) {
					singal_block.push_back(*it);
					if (*it == "loop" || *it == "while" || *it == "if") {
						++depth;
					}
					if (*it == "end") {
						//
						//
						--depth;
						if (depth == 0) {
							//do....
							break;
						}
					}
				}
				//dont need add
				//std::cout << "haha2\n";
				//block.push_back(singal_block);
				if (it == temptoken.end()) {
					return block;
				}

			}

			if (*it == ";") {
				//std::cout << "haha\n";
				block.push_back(std::vector<std::string>(beginit, it));
				beginit = it + 1;
			}
		}

		if (beginit != temptoken.end()) {
			throw;
		}
		return block;
	}
}
#endif // !_TOKENTOBLOCK_H_

