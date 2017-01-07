#ifndef __NUMBER_OPERATOR_H__
#define __NUMBER_OPERATOR_H__
#include "Number.h"
namespace nee {
	//ÉùÃ÷
	Integer operator+(const Integer& a, const Integer& b);
	Float operator+(const Integer& a, const Float& b);
	Efloat operator+(const Integer& a, const Efloat& b);
	Float operator+(const Float& a, const Integer& b);
	Float operator+(const Float& a, const Float& b);
	Efloat operator+(const Float& a, const Efloat& b);
	Efloat operator+(const Efloat& a, const Integer& b);
	Efloat operator+(const Efloat& a, const Float& b);
	Efloat operator+(const Efloat& a, const Efloat& b);
	Integer operator-(const Integer& a, const Integer& b);
	Float operator-(const Integer& a, const Float& b);
	Efloat operator-(const Integer& a, const Efloat& b);
	Float operator-(const Float& a, const Integer& b);
	Float operator-(const Float& a, const Float& b);
	Efloat operator-(const Float& a, const Efloat& b);
	Efloat operator-(const Efloat& a, const Integer& b);
	Efloat operator-(const Efloat& a, const Float& b);
	Efloat operator-(const Efloat& a, const Efloat& b);
	Integer operator*(const Integer& a, const Integer& b);
	Float operator*(const Integer& a, const Float& b);
	Efloat operator*(const Integer& a, const Efloat& b);
	Float operator*(const Float& a, const Integer& b);
	Float operator*(const Float& a, const Float& b);
	Efloat operator*(const Float& a, const Efloat& b);
	Efloat operator*(const Efloat& a, const Integer& b);
	Efloat operator*(const Efloat& a, const Float& b);
	Efloat operator*(const Efloat& a, const Efloat& b);
	Integer operator/(const Integer& a, const Integer& b);
	Float operator/(const Integer& a, const Float& b);
	Efloat operator/(const Integer& a, const Efloat& b);
	Float operator/(const Float& a, const Integer& b);
	Float operator/(const Float& a, const Float& b);
	Efloat operator/(const Float& a, const Efloat& b);
	Efloat operator/(const Efloat& a, const Integer& b);
	Efloat operator/(const Efloat& a, const Float& b);
	Efloat operator/(const Efloat& a, const Efloat& b);
}
#endif
