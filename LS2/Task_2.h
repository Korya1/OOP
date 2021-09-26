#pragma once
#include "Common.h"
//
// --------- class Fruit
//
class Fruit
{
public:
	Fruit() {};
	Fruit(std::string color, std::string name)
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
	Apple(std::string color = "green", std::string name = "apple")
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
	Banana(std::string color = "yellow", std::string name = "banana")
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
	GrannySmith(std::string color = "green")
		:
		Apple(color, "Granny Smith apple")
	{}
};