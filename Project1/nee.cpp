#include "nee.h"
#include "Number_Operator.h"

#include <iostream>

int main(int argc, char *argv[]){
	nee::Integer a("-2");
	nee::Integer b("-999");
	nee::Integer c("1");
	nee::Integer d("999");
	nee::Integer e("3565656565665656565656566565656");
	nee::Integer f("133333333333333333333333");
	nee::Float g("-031231231.00010000");
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
	std::cout << (g * a).ToString() << std::endl;
	while (true)
	{

	}
	return 0;
}
