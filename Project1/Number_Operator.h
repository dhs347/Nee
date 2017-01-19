#ifndef __NUMBER_OPERATOR_H__
#define __NUMBER_OPERATOR_H__
#include "Number.h"
namespace nee {
	//ÉùÃ÷
	Integer operator+(const Integer& a, const Integer& b);
	Float operator+(const Integer& a, const Float& b);
	Float operator+(const Float& a, const Integer& b);
	Float operator+(const Float& a, const Float& b);

	Integer operator-(const Integer& a, const Integer& b);
	Float operator-(const Integer& a, const Float& b);
	Float operator-(const Float& a, const Integer& b);
	Float operator-(const Float& a, const Float& b);

	Integer operator*(const Integer& a, const Integer& b);
	Float operator*(const Integer& a, const Float& b);
	Float operator*(const Float& a, const Integer& b);
	Float operator*(const Float& a, const Float& b);

	Integer operator/(const Integer& a, const Integer& b);
	Float operator/(const Integer& a, const Float& b);
	Float operator/(const Float& a, const Integer& b);
	Float operator/(const Float& a, const Float& b);

	bool operator==(const Integer& a, const Integer& b);
	bool operator==(const Integer& a, const Float& b);
	bool operator==(const Float& a, const Integer& b);
	bool operator==(const Float& a, const Float& b);

	bool operator>=(const Integer& a, const Integer& b);
	bool operator>=(const Integer& a, const Float& b);
	bool operator>=(const Float& a, const Integer& b);
	bool operator>=(const Float& a, const Float& b);

	bool operator<=(const Integer& a, const Integer& b);
	bool operator<=(const Integer& a, const Float& b);
	bool operator<=(const Float& a, const Integer& b);
	bool operator<=(const Float& a, const Float& b);


	bool operator!=(const Integer& a, const Integer& b);
	bool operator!=(const Integer& a, const Float& b);
	bool operator!=(const Float& a, const Integer& b);
	bool operator!=(const Float& a, const Float& b);

	bool operator>(const Integer& a, const Integer& b);
	bool operator>(const Integer& a, const Float& b);
	bool operator>(const Float& a, const Integer& b);
	bool operator>(const Float& a, const Float& b);

	bool operator<(const Integer& a, const Integer& b);
	bool operator<(const Integer& a, const Float& b);
	bool operator<(const Float& a, const Integer& b);
	bool operator<(const Float& a, const Float& b);

}
#endif
