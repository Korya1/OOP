#pragma once
#include "Common.h"
//
// --------- class Fruit
//
class Fruit
{
public:
	Fruit() {};
	Fruit(const std::string& color, const std::string& name)
		:
		color(color),
		name(name)
	{}
	std::string getName();
	std::string getColor();
protected:
	std::string name;
	std::string color;
};
std::string Fruit::getName() { return name; }
std::string Fruit::getColor() { return color; }

//
// --------- class Apple
//
class Apple : public Fruit
{
public:
	Apple(const std::string& color = "green", const std::string& name = "apple")
		:
		Fruit(color, name)
	{}
};
//
// --------- class Banana
//
class Banana : public Fruit
{
public:
	Banana(const std::string& color = "yellow", const std::string& name = "banana")
		:
		Fruit(color, name)
	{}
};
//
// --------- class GrannySmith
//
class GrannySmith : public Apple
{
public:
	GrannySmith(const std::string& color = "green")
		:
		Apple(color, "Granny Smith apple")
	{}
};