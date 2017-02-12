#include "nee.h"

#include <iostream>
//debug

int main(int argc, char *argv[]){

	nee::Integer a("2");
	nee::Integer zero("-0");
	nee::Integer b("-999");
	nee::Integer c("121312312");
	nee::Integer d("-999");
	nee::Integer e("10");
	nee::Integer f("3000");
	nee::Float g("3.01");
	nee::Float h("-3.0");
	nee::Integer i("444444342342");
	nee::Integer j("31");

	//std::cout << (a + a).ToString() << std::endl;
	//std::cout << (a + b).ToString() << std::endl;
	//std::cout << (a + c).ToString() << std::endl;
	//std::cout << (a + d).ToString() << std::endl;
	//std::cout << (a - a).ToString() << std::endl;
	//std::cout << (a - b).ToString() << std::endl;
	//std::cout << (a - c).ToString() << std::endl;
	//std::cout << (a - d).ToString() << std::endl;
	//std::cout << (a * a).ToString() << std::endl;
	//std::cout << (a * b).ToString() << std::endl;
	//std::cout << (a * c).ToString() << std::endl;
	//std::cout << (a * d).ToString() << std::endl;
	//std::cout << (a / a).ToString() << std::endl;
	//std::cout << (a / b).ToString() << std::endl;
	//std::cout << (a / c).ToString() << std::endl;
	//std::cout << (a / d).ToString() << std::endl;
	//std::cout << (e * f).ToString() << std::endl;
	//std::cout << (g / e).ToString() << std::endl;
	//std::cout << (h - h).ToString() << std::endl;
	//std::cout << (d % c).ToString() << std::endl;
	//auto x = nee::TokentoBlock(nee::Tokenizer("C:\\Users\\42937\\Desktop\\x.bf"));

	//for (auto &i:x) {
	//	for (auto &j:i) {
	//		std::cout << j << std::endl;
	//	}
	//	std::cout << std::endl;
	//}
	//std::cout << (a/zero).ToString() << std::endl;
	auto x = nee::TokentoBlock(nee::Tokenizer("C:\\Users\\42937\\Desktop\\x.nee"));
	//for (auto &i:x) {
	//	for (auto &j:i) {
	//		std::cout << j << std::endl;
	//	}
	//	std::cout << std::endl;
	//}
	nee::variable_table vt;

	std::unordered_map< std::string, std::function<nee::nee_Value(nee::nee_State &)> > fun;
	//
	nee::init_function(fun);
	//
	nee::process_block(fun,vt,x);
	//std::cout << nee::eval(temp) << std::endl;
	while (true)
	{

	}
	return 0;
}
