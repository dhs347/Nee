#include "nee.h"
#include "Number_Operator.h"

#include <iostream>
//debug
namespace nee {
	std::string getRemainder(std::string num1, std::string num2);
	std::string  _divideStrings(std::string num1, std::string num2);
}
int main(int argc, char *argv[]){
	nee::Integer a("2");
	nee::Integer zero("-0");
	nee::Integer b("-999");
	nee::Integer c("1");
	nee::Integer d("999");
	nee::Integer e("10");
	nee::Integer f("3000");
	nee::Float g("0.000000000000001");
	nee::Float h("1.3");
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
	std::cout << (e / j).ToString() << std::endl;
	//std::cout << (a/zero).ToString() << std::endl;
	while (true)
	{

	}
	return 0;
}
