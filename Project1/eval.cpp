#include "String.h"
#include "Number.h"
#include <vector>
#include <string>
namespace nee {
	using Block = std::vector<std::string>;
	std::string eval(const Block &block) {
		int depth = 0;
		int max_depth = 0;
		for (size_t i = 0;i < block.size(); ++i) {
			if (depth < 0) {
				throw;
			}

			if (block[i] == "(") {
				++depth;
				if (depth > max_depth) {
					max_depth = depth;
				}
			}
			else if (block[i] == ")") {
				--depth;
			}
				
		}
		return "";
	}
}