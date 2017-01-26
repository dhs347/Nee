
#ifndef _BLOCK_H_
#define _BLOCK_H_
#include <vector>
#include <string>
namespace nee {
	void process_block(std::vector<std::vector<std::string>> &block) {
		for (size_t i = 0;i < block.size(); ++i) {
			if (block[i][0] == "if") {

			}
			else if (block[i][0] == "loop") {

			}
			else if (block[i][0] == "while") {

			}
			//todo
		}
	}
}

#endif // !_BLOCK_H_

