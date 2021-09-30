#pragma once
#include  "Common.h"
class Fraction
{
public:
	Fraction() = default;
	Fraction(int num, int den) 
	{
		this->num = num;
		this->den = den;
		if(den == 0)
		{
			this->den = 1;
			std::cout << "Invalid value for denominator: {0}. Repleced {1}\n\n";
		}
	};
	void getResult();

	Fraction operator -() { return Fraction(-num, -den); };
	friend Fraction operator +(const Fraction& l, const Fraction& r);
	friend Fraction operator -(const Fraction& l, const Fraction& r);
	friend Fraction operator *(const Fraction& l, const Fraction& r);
	friend Fraction operator /(const Fraction& l, const Fraction& r);
	friend bool operator ==(const Fraction& l, const Fraction& r);
	friend bool operator !=(const Fraction& l, const Fraction& r);
	friend bool operator <(const Fraction& l, const Fraction& r);
	friend bool operator <=(const Fraction& l, const Fraction& r);
	friend bool operator >(const Fraction& l, const Fraction& r);
	friend bool operator >=(const Fraction& l, const Fraction& r);

private:
	int num, den;
};

//++++++++++++++++++++++++++++++++++++
Fraction operator +(const Fraction& l, const Fraction& r)
{
	Fraction result{};
	result.num = l.num * r.den + r.num * l.den;
	result.den = l.den * r.den;
	return result;
}
//------------------------------------
Fraction operator -(const Fraction& l, const Fraction& r)
{
	Fraction result{};
	result.num = l.num * r.den - r.num * l.den;
	result.den = l.den * r.den;
	return result;
}
//************************************
Fraction operator *(const Fraction& l, const Fraction& r)
{
	Fraction result{};
	result.num = l.num * r.num;
	result.den = l.den * r.den;
	return result;
}
/////////////////////////////////////
Fraction operator /(const Fraction& l, const Fraction& r)
{
	Fraction result{};
	result.num = l.num * r.den;
	result.den = l.den * r.num;
	return result;
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
bool operator <(const Fraction& l, const Fraction& r)
{
	return (l.num * r.den < l.den* r.num) ? true : false;
}
//<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=<=
bool operator <=(const Fraction& l, const Fraction& r)
{
	return !(l > r);
}
//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
bool operator >(const Fraction& l, const Fraction& r)
{
	return (l.num * r.den > l.den * r.num) ? true : false;
}
//>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>=>
bool operator >=(const Fraction& l, const Fraction& r)
{
	return !(l < r);
}
//==================================
bool operator ==(const Fraction& l, const Fraction& r)
{
	return (l.num == r.num && l.den == r.den) ? true : false;
}
//!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!=!
bool operator !=(const Fraction& l, const Fraction& r)
{
	return (l.num != r.num || l.den != r.den) ? true : false;
}
//
//   
//
void Fraction::getResult()
{
	std::cout << num << "/" << den << "\n";
};