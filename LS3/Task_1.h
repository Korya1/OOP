#pragma once
#include  "Common.h"

struct Figure
{
	Figure() = default;

	virtual void area() = 0;

	virtual ~Figure() = default;
};
//-----------------------------
class Parallelogram : public Figure
{
public:
	Parallelogram() = default;

	Parallelogram(double width, double height, int degrees) :
		width(width),
		height(height),
		degrees(degrees)
	{};

	Parallelogram(double width, double height) :
		width(width),
		height(height)
	{};

	virtual void area() override
	{
		double result;

		if (degrees > 0)
		{
			result = height * width * sin(degrees * PI / 180);
		}
		else
		{
			result = height * width;
		}

		std::cout << "Parallelogram area : S = " << result << "(m^2)\n";
	}

protected:
	double height{ 0 }, width{ 0 };
private:
	int degrees{ 0 };
};
//-----------------------------
class Circle : public Figure
{
public:
	Circle(float r) :
		r(r)
	{};
	virtual void area() override { std::cout << "Circle area : S = " << PI * r * r << "\n"; };

private:
	float r;
};
//-----------------------------

class Rectangle : public Parallelogram
{
public:
	Rectangle(double height, double width) :
		Parallelogram(height, width)
	{};
	virtual void area() override
	{
		std::cout << "Rectangle area : S = " << height * width << "(m)\n";
	}
};

class Square : public Parallelogram
{
public:
	Square(double side) : side(side) {};
	virtual void area() override
	{
		std::cout << "Square area : S = " << pow(side, power) << "(m)\n";
	}
private:
	double side;
	short int power{ 2 };
};

class Rhombus : public Parallelogram
{
public:
	Rhombus(double height, double width) :
		Parallelogram(height, width)
	{};
	virtual void area() override
	{
		std::cout << "Rhombus area : S = " << height * width << "(m)\n";
	}
};