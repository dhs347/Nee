#include "nee.h"
#include "Number_Operator.h"

#include <iostream>


#include "Number.h"
#include "Number_Operator.h"
#include <string>
#include <algorithm> 


int main(int argc, char *argv[]){
	nee::Integer a("-1");
	nee::Integer b("-999");
	nee::Integer c("1");
	nee::Integer d("999");

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
	while (true)
	{

	}
	return 0;
}
