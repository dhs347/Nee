#include "nee.h"
#include "Number_Operator.h"

#include <iostream>
#include "Tokenizer.h"
#include "Eval.h"
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

	std::cout << (a + a).ToString() << std::endl;
	std::cout << (a + b).ToString() << std::endl;
	std::cout << (a + c).ToString() << std::endl;
	std::cout << (a + d).ToString() << std::endl;
	std::cout << (a - a).ToString() << std::endl;
	std::cout << (a - b).ToString() << std::endl;
	std::cout << (a - c).ToString() << std::endl;
	std::cout << (a - d).ToString() << std::endl;
	std::cout << (a * a).ToString() << std::endl;
	std::cout << (a * b).ToString() << std::endl;
	std::cout << (a * c).ToString() << std::endl;
	std::cout << (a * d).ToString() << std::endl;
	std::cout << (a / a).ToString() << std::endl;
	std::cout << (a / b).ToString() << std::endl;
	std::cout << (a / c).ToString() << std::endl;
	std::cout << (a / d).ToString() << std::endl;
	std::cout << (e * f).ToString() << std::endl;
	std::cout << (g / e).ToString() << std::endl;
	std::cout << (h - h).ToString() << std::endl;
	std::cout << (d % c).ToString() << std::endl;
	nee::Tokenizer("C:\\Users\\42937\\Desktop\\x.bf");
	//std::cout << (a/zero).ToString() << std::endl;
	std::vector<std::string> temp{"123","/","123"};
	std::cout << nee::eval_single(temp) << std::endl;
	while (true)
	{

	}
	return 0;
}
