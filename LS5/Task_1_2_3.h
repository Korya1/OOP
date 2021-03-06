#pragma once
#include "Common.h"


template<typename T>
class Pair1
{
public:
	Pair1(const T& num1, const T& num2) : num1(num1), num2(num2) {};
	const T& first() const { return num1; }
	const T& second() const { return num2; }
private:
	T num1;
	T num2;
};

template<typename T, typename U>
class Pair
{
public:
	Pair(const T& num1, const U& num2) : num1(num1), num2(num2) {};
	const T& first() const { return num1; }
	const U& second() const { return num2; }
private:
	T num1;
	U num2;
};

template<typename T>
class StringValuePair : public Pair<std::string, T>
{
public:
	StringValuePair(const std::string& a, T b)
		:
		Pair<std::string, T>(a, b)
	{};
};