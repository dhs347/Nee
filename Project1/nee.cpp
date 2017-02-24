#include "nee.h"


int main(int argc, char *argv[]){

	if (argc != 2) {
		throw;
	}
	//std::string file = "C:\\Users\\42937\\Desktop\\x.nee";

	auto x = nee::TokentoBlock(nee::Tokenizer(argv[1]));
	nee::variable_table vt;
	std::unordered_map< std::string, std::function<nee::nee_Value(nee::nee_State &)> > fun;
	//
	nee::init_function(fun);
	//
	nee::process_block(fun,vt,x);
	//while (1) {}
	return 0;
}
