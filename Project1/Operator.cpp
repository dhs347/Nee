#include "Number.h"
#include <string>
namespace nee {
	//+
	Integer operator+(const Integer& a, const Integer& b) {
		std::string tempa = a.ToString();
		std::string tempb = b.ToString();

		return Integer();
	}
	Float operator+(const Integer& a, const Float& b) {
		return Float();
	}
	Efloat operator+(const Integer& a, const Efloat& b) {
		return Efloat();
	}
	Float operator+(const Float& a, const Integer& b) {
		return Float();
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
		return Integer();
	}
	Float operator-(const Integer& a, const Float& b) {
		return Float();
	}
	Efloat operator-(const Integer& a, const Efloat& b) {
		return Efloat();
	}
	Float operator-(const Float& a, const Integer& b) {
		return Float();
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
		return Integer();
	}
	Float operator*(const Integer& a, const Float& b) {
		return Float();
	}
	Efloat operator*(const Integer& a, const Efloat& b) {
		return Efloat();
	}
	Float operator*(const Float& a, const Integer& b) {
		return Float();
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
		return Integer();
	}
	Float operator/(const Integer& a, const Float& b) {
		return Float();
	}
	Efloat operator/(const Integer& a, const Efloat& b) {
		return Efloat();
	}
	Float operator/(const Float& a, const Integer& b) {
		return Float();
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
	
}