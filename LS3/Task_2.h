#pragma once
#include  "Common.h"

class Car
{
public:
	Car() { std::cout << "\nCar\n\n"; }
	virtual ~Car() { std::cout << "~Car\n\n"; }
protected:
	std::string company{ "undefined" };
	std::string model{ "undefined" };
};

class PassengerCar : virtual public Car
{
public:
	PassengerCar() { std::cout << "PassengerCar\n\n"; }
	~PassengerCar() { std::cout << "~PassengerCar\n\n"; }
};

class Bus : virtual public Car
{
public:
	Bus() { std::cout << "Bus\n\n"; }
	~Bus() { std::cout << "~Bus\n\n"; }
};

class Minivan : public Bus, public PassengerCar
{
public:
	Minivan() { std::cout << "Minivan\n\n"; }
	~Minivan() { std::cout << "~Minivan\n\n"; }
};