#include "Number.h"
#include "Number_Operator.h"
#include <string>
#include <algorithm> 
#include <vector>

#include <iostream>

namespace nee {
	std::string addStrings(std::string num1, std::string num2);
	std::string minusStrings(std::string num1, std::string num2);
	std::string multiplyStrings(std::string num1, std::string num2);
	std::string divideStrings(std::string num1, std::string num2);


	std::string getBigString(std::string num1, std::string num2) {
		if (num1.size() > num2.size()) {
			return num1;
		}
		else if (num1.size() < num2.size())
		{
			return num2;
		}

		if (num1 == num2) {
			return num1;
		}

		for (size_t i = 0; i < num1.size(); ++i) {
			if (num1[i] > num2[i])
			{
				return num1;
			}
			else if (num1[i] < num2[i])
			{
				return num2;
			}
		}
		return num1;
	}
	int getNumber(int a) {
		if (a >= 0) {
			return a;
		}
		return 10 + a;
	}

	std::string getRemainder(std::string num1, std::string num2) {
		//fix 消除前导0
		num1 = Integer(num1).ToString();
		num2 = Integer(num2).ToString();
		//

		if (num2 == std::string("0")) {
			//todo
			throw;
		}
		if (num2 == num1) {
			return std::string("0");
		}
		if (num2 == getBigString(num1,num2)) {
			return num1;
		}

		while (true) {

			if (num2 == getBigString(num1, num2)) {
				break;
			}
			num1 = minusStrings(num1, num2);
		}

		if (num1 == num2) {
			return std::string("0");
		}
		return num1;
	}

	std::string addStrings(std::string num1, std::string num2) {
		int i = static_cast<int>(num1.size() - 1);
		int j = static_cast<int>(num2.size() - 1);
		int carry = 0;
		std::string res = "";
		while (i >= 0 || j >= 0 || carry) {
			long sum = 0;
			if (i >= 0) { sum += (num1[i] - '0'); i--; }
			if (j >= 0) { sum += (num2[j] - '0'); j--; }
			sum += carry;
			carry = sum / 10;
			sum = sum % 10;
			res = res + std::to_string(sum);
		}
		std::reverse(res.begin(), res.end());
		return res;
	}
	std::string minusStrings(std::string num1, std::string num2) {
		if (num1 == num2) {
			return std::string("0");
		}
		std::string temp;

		size_t bigsize = num1.size() > num2.size() ? num1.size() : num2.size();
		size_t smallsize = num1.size() > num2.size() ? num2.size() : num1.size();

		std::string bigstr = getBigString(num1, num2);
		std::string smallstr = (bigstr == num1) ? num2 : num1;

		std::reverse(bigstr.begin(), bigstr.end());
		std::reverse(smallstr.begin(), smallstr.end());
		int carry = 0;

		for (size_t i = 0;i < bigsize; ++i) {
			if (i < smallsize) {
				int number =static_cast<int>( bigstr[i] - smallstr[i] - carry);
				if (number < 0) 
					carry = 1;
				else carry = 0;
				temp += std::to_string(getNumber(number));
			}
			else {
				int number = static_cast<int>(bigstr[i] - '0' - carry);
				if (number < 0)
					carry = 1;
				else carry = 0;
				temp += std::to_string(getNumber(number));

			}

		}
		std::reverse(temp.begin(), temp.end());
		auto it = temp.begin();
		for (; it != temp.end(); ++it) {
			if (*it != '0') {
				break;
			}
		}
		
		if (num1 != getBigString(num1, num2)) {
			return ("-" + std::string(it, temp.end()));
		}
		return std::string(it, temp.end());
	}
	//fix
	std::string __multiplyStrings(std::string num1, std::string num2) {
		std::string bigstr = getBigString(num1, num2);
		std::string smallstr = (bigstr == num1) ? num2 : num1;
		if (bigstr == std::string("0") || smallstr == std::string("0")) {
			return std::string("0");
		}
		std::string number = std::string("0");
		while (true) {
			if (smallstr != std::string("0")) {
				number = addStrings(number, bigstr);
				smallstr = minusStrings(smallstr, std::string("1"));
			}
			else break;
		}
		return number;
	}
	std::string multiplyStrings(std::string num1, std::string num2) {
		std::string bigstr = getBigString(num1, num2);
		std::string smallstr = (bigstr == num1) ? num2 : num1;
		if (bigstr == std::string("0") || smallstr == std::string("0")) {
			return std::string("0");
		}
		std::reverse(smallstr.begin(), smallstr.end());
		std::vector <std::string> vectorNumber;
		for (size_t i = 0; i < smallstr.size();++i) {
			vectorNumber.push_back(__multiplyStrings(bigstr, std::string(1, static_cast<char>(smallstr[i]))) + std::string(i,'0')) ;
		}
		std::string res("0");
		for (size_t i = 0; i < vectorNumber.size(); ++i) {
			res = addStrings(res, vectorNumber[i]);
		}
		return res;
	}
	//fix
	std::string __divideStrings(std::string num1, std::string num2) {

		//fix 消除前导0
		num1 = Integer(num1).ToString();
		num2 = Integer(num2).ToString();
		//
		if (num2 == std::string("0")) {
			throw;
		}
		if (num2 == num1) {
			return std::string("1");
		}

		std::string res("0");

		while (true) {
	
			if (num2 == getBigString(num1, num2)) {
				break;
			}
			num1 = minusStrings(num1, num2);
			res = addStrings(res, std::string("1"));

		}
		//fix
		if (num1 == num2) {
			res = addStrings(res, std::string("1"));
		}

		return res;
	}
	//fix
	std::string divideStrings(std::string num1, std::string num2) {

		if (num2 == std::string("0")) {
			//todo
			throw;
		}
		if (num2 == num1) {
			return std::string("1");
		}
		if (num2 == getBigString(num1, num2)) {
			return std::string("0");
		}

		std::string::iterator it = num1.begin() + num2.size();
		std::string res(num1.begin(), it);
		std::vector<char> vectorChar;
		while (true) {
			if (it == num1.end()) {
				break;
			}
			
			vectorChar.push_back(__divideStrings(res, num2)[0]);
			res = getRemainder(res, num2) + std::string(it, it + 1);
			++it;
		}

		vectorChar.push_back(__divideStrings(res, num2)[0]);
		std::string result;
		for (size_t i = 0; i < vectorChar.size(); ++i) {
			result.push_back(vectorChar[i]);
		}
		return Integer(result).ToString();
	}

	size_t getFloatPosition(const std::string &str) {
		size_t i = 0;
		for (; i < str.size(); ++i) {
			if (str[i] == '.') {
				break;
			}
		}
		return str.size() - 1 - i;
	}



	//+
	Integer operator+(const Integer& a, const Integer& b) {
		
		std::string tempa = a.ToString();
		std::string tempb = b.ToString();
		Integer temp;

		if (tempa[0] != '-'&&tempb[0] != '-') {
			temp = Integer(addStrings(tempa, tempb));
		}else if (tempa[0] == '-'&&tempb[0] != '-') {	
			temp = b - Integer(std::string(tempa.begin() + 1, tempa.end()));
		}else if (tempa[0] != '-'&&tempb[0] == '-') {
			temp = a - b;
		}else if (tempa[0] == '-'&&tempb[0] == '-') {
			temp = Integer("-" + (Integer(std::string(tempa.begin() + 1, tempa.end())) + Integer(std::string(tempb.begin() + 1, tempb.end())))
				.ToString());
		}

		return temp;
	}
	Float operator+(const Integer& a, const Float& b) {
		std::string tempa = a.ToString();
		std::string tempb = b.ToString();
		size_t times = getFloatPosition(tempb);
		tempa += std::string(times, '0');
		tempb.erase(tempb.size() - 1 - times,1);
		std::string tempStr = (Integer(tempa) + Integer(tempb)).ToString(); /*addStrings(tempa, tempInt.ToString()); error*/

		tempStr.insert(tempStr.size() - times , 1, '.');
		Float tempFloat(tempStr);

		return tempFloat;
	}
	Efloat operator+(const Integer& a, const Efloat& b) {
		return Efloat();
	}
	Float operator+(const Float& a, const Integer& b) {
		return b + a;
	}
	Float operator+(const Float& a, const Float& b) {
		return Float();
	}
	Efloat operator+(const Float& a, const Efloat& b) {
		return Efloat();
	}
	Efloat operator+(const Efloat& a, const Integer& b) {
		return Efloat();
	}
	Efloat operator+(const Efloat& a, const Float& b) {
		return Efloat();
	}
	Efloat operator+(const Efloat& a, const Efloat& b) {
		return Efloat();
	}
	//-
	Integer operator-(const Integer& a, const Integer& b) {
		std::string tempa = a.ToString();
		std::string tempb = b.ToString();
		Integer temp;
		if (tempa[0] != '-'&&tempb[0] != '-') {
			temp = Integer(minusStrings(tempa, tempb));
		}
		else if (tempa[0] == '-'&&tempb[0] != '-') {
			temp = Integer("-" + (Integer(std::string(tempa.begin() + 1, tempa.end())) + b).ToString());
		}
		else if (tempa[0] != '-'&&tempb[0] == '-') {
			temp = a + Integer(std::string(tempb.begin() + 1, tempb.end()));
		}
		else if (tempa[0] == '-'&&tempb[0] == '-') {
			temp = Integer(minusStrings(std::string(tempb.begin() +1 ,tempb.end()), std::string(tempa.begin() + 1, tempa.end())));
		}

		return temp;
	}
	Float operator-(const Integer& a, const Float& b) {
		std::string tempa = a.ToString();
		std::string tempb = b.ToString();
		size_t times = getFloatPosition(tempb);
		tempa += std::string(times, '0');
		tempb.erase(tempb.size() - 1 - times, 1);
		std::string tempStr = (Integer(tempa) - Integer(tempb)).ToString(); /*addStrings(tempa, tempInt.ToString()); error*/

		tempStr.insert(tempStr.size() - times, 1, '.');
		Float tempFloat(tempStr);

		return tempFloat;
	}
	Efloat operator-(const Integer& a, const Efloat& b) {
		return Efloat();
	}
	Float operator-(const Float& a, const Integer& b) {
		//fix
		std::string str = (b - a).ToString();
		if (str[0] == '-') {
			str = std::string(str.begin() + 1, str.end());
		}
		else str = "-" + str;
		return Float(str);
	}
	Float operator-(const Float& a, const Float& b) {
		return Float();
	}
	Efloat operator-(const Float& a, const Efloat& b) {
		return Efloat();
	}
	Efloat operator-(const Efloat& a, const Integer& b) {
		return Efloat();
	}
	Efloat operator-(const Efloat& a, const Float& b) {
		return Efloat();
	}
	Efloat operator-(const Efloat& a, const Efloat& b) {
		return Efloat();
	}
	//*
	Integer operator*(const Integer& a, const Integer& b) {
		std::string tempa = a.ToString();
		std::string tempb = b.ToString();
		Integer temp;
		if (tempa[0] != '-'&&tempb[0] != '-') {
			temp = Integer(multiplyStrings(tempa, tempb));
		}
		else if (tempa[0] == '-'&&tempb[0] != '-') {
			temp = Integer("-" + (Integer(std::string(tempa.begin() + 1, tempa.end())) * b).ToString());
		}
		else if (tempa[0] != '-'&&tempb[0] == '-') {
			temp = Integer("-" + (Integer(std::string(tempb.begin() + 1, tempb.end())) * a).ToString());
		}
		else if (tempa[0] == '-'&&tempb[0] == '-') {
			temp = Integer(multiplyStrings(std::string(tempa.begin() + 1, tempa.end()), std::string(tempb.begin() + 1, tempb.end())));
		}

		return temp;
	}
	Float operator*(const Integer& a, const Float& b) {

		//
		std::string tempa = a.ToString();
		std::string tempb = b.ToString();
		size_t times = getFloatPosition(tempb);
		tempb.erase(tempb.size() - 1 - times, 1);
		std::string tempStr = (Integer(tempa) * Integer(tempb)).ToString(); /*addStrings(tempa, tempInt.ToString()); error*/
		tempStr.insert(tempStr.size() - times, 1, '.');

		Float tempFloat(tempStr);

		return tempFloat;
	}
	Efloat operator*(const Integer& a, const Efloat& b) {
		return Efloat();
	}
	Float operator*(const Float& a, const Integer& b) {
		return b * a;
	}
	Float operator*(const Float& a, const Float& b) {
		return Float();
	}
	Efloat operator*(const Float& a, const Efloat& b) {
		return Efloat();
	}
	Efloat operator*(const Efloat& a, const Integer& b) {
		return Efloat();
	}
	Efloat operator*(const Efloat& a, const Float& b) {
		return Efloat();
	}
	Efloat operator*(const Efloat& a, const Efloat& b) {
		return Efloat();
	}
	// /
	Integer operator/(const Integer& a, const Integer& b) {

		std::string tempa = a.ToString();
		std::string tempb = b.ToString();
		Integer temp;
		if (tempa[0] != '-'&&tempb[0] != '-') {
			temp = Integer(divideStrings(tempa, tempb));
		}
		else if (tempa[0] == '-'&&tempb[0] != '-') {
			temp = Integer("-" + (Integer(std::string(tempa.begin() + 1, tempa.end())) / b).ToString());
		}
		else if (tempa[0] != '-'&&tempb[0] == '-') {
			temp = Integer("-" + (a / Integer(std::string(tempb.begin() + 1, tempb.end()))).ToString());
		}
		else if (tempa[0] == '-'&&tempb[0] == '-') {
			temp = Integer(divideStrings(std::string(tempa.begin() + 1, tempa.end()), std::string(tempb.begin() + 1, tempb.end())));
		}
		if (temp.ToString() == std::string("-0")) {
			temp = Integer(std::string("0"));
		}
		return temp;
	}
	Float operator/(const Integer& a, const Float& b) {
		std::string tempa = a.ToString();
		std::string tempb = b.ToString();
		size_t times = getFloatPosition(tempb);
		tempb.erase(tempb.size() - 1 - times, 1);
		std::string tempStr = (Integer(tempa + std::string(16 + times,'0')) / Integer(tempb)).ToString(); /*addStrings(tempa, tempInt.ToString()); error*/
		//fix
		if (tempStr[0] == '-') {
			if (tempStr.size() <= 17) {
				tempStr = "-0." + std::string(17 - tempStr.size(), '0') + std::string(tempStr.begin() + 1, tempStr.end());
				if (getFloatPosition(tempStr) == 16) {
					if (tempStr[tempStr.size() - 1] >= '5') {
						tempStr = (Integer(tempStr) - Integer(std::string("10"))).ToString();
					}
					tempStr.pop_back();
				}
			}
			else {
				if (tempStr[tempStr.size() - 1] >= '5') {
					tempStr = (Integer(tempStr) - Integer(std::string("10"))).ToString();
				}
				tempStr.insert(tempStr.size() - 16, 1, '.');
				tempStr.pop_back();

			}
		}
		else {
			if (tempStr.size() <= 16) {
				tempStr = "0." + std::string(16 - tempStr.size(), '0') + std::string(tempStr.begin(), tempStr.end());
				if (getFloatPosition(tempStr) == 16) {
					if (tempStr[tempStr.size() - 1] >= '5') {
						tempStr = (Integer(tempStr) + Integer(std::string("10"))).ToString();
					}
					tempStr.pop_back();
				}
			}
			else {
				if (tempStr[tempStr.size() - 1] >= '5') {
					tempStr = (Integer(tempStr) + Integer(std::string("10"))).ToString();
				}
				tempStr.insert(tempStr.size() - 16, 1, '.');
				tempStr.pop_back();
			}
		}
		Float tempFloat(tempStr);

		return tempFloat;
	}
	Efloat operator/(const Integer& a, const Efloat& b) {
		return Efloat();
	}
	Float operator/(const Float& a, const Integer& b) {
		std::string tempa = a.ToString();
		std::string tempb = b.ToString();
		size_t times = getFloatPosition(tempa);
		tempa.erase(tempa.size() - 1 - times, 1);
		std::string tempStr = (Integer(tempa + std::string(16, '0')) / Integer(tempb + std::string(times, '0'))).ToString(); /*addStrings(tempa, tempInt.ToString()); error*/
		if (tempStr[0] == '-') {
			if (tempStr.size() <= 17) {
				tempStr = "-0." + std::string(17 - tempStr.size(), '0') + std::string(tempStr.begin() + 1, tempStr.end());

				if (getFloatPosition(tempStr) == 16) {
					if (tempStr[tempStr.size() - 1] >= '5') {
						tempStr = (Integer(tempStr) - Integer(std::string("10"))).ToString();
					}
					tempStr.pop_back();
				}
			}
			else {
				if (tempStr[tempStr.size() - 1] >= '5') {
					tempStr = (Integer(tempStr) - Integer(std::string("10"))).ToString();
				}
				tempStr.insert(tempStr.size() - 16, 1, '.'); 
				tempStr.pop_back();
			}
		}
		else {
			if (tempStr.size() <= 16) {
				tempStr = "0." + std::string(16 - tempStr.size(), '0') + std::string(tempStr.begin(), tempStr.end());
				if (getFloatPosition(tempStr) == 16) {
					if (tempStr[tempStr.size() - 1] >= '5') {
						tempStr = (Integer(tempStr) + Integer(std::string("10"))).ToString();//fix
					}
					tempStr.pop_back();
				}
			}
			else {
				if (tempStr[tempStr.size() - 1] >= '5') {
					tempStr = (Integer(tempStr) + Integer(std::string("10"))).ToString();
				}
				tempStr.insert(tempStr.size() - 16, 1, '.');
				tempStr.pop_back();
			}
		}
		Float tempFloat(tempStr);

		return tempFloat;
	}
	Float operator/(const Float& a, const Float& b) {
		return Float();
	}
	Efloat operator/(const Float& a, const Efloat& b) {
		return Efloat();
	}
	Efloat operator/(const Efloat& a, const Integer& b) {
		return Efloat();
	}
	Efloat operator/(const Efloat& a, const Float& b) {
		return Efloat();
	}
	Efloat operator/(const Efloat& a, const Efloat& b) {
		return Efloat();
	}

	// % etc todo
	
}