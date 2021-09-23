#include <iostream>
#include <cstdint>
#include <cstdint>
#include <cmath>
//=======================
class Power	
{
public:

	Power()
		:
	      num1(2.2)
		, num2(4.2)	
	{}

	void setNums(double a, double b);
	double calculate();

private:

	double num1;
	double num2;

};

void Power::setNums(double a, double b)
{
	num1 = a;
	num2 = b;
}
double Power::calculate()
{	
	return pow(num1, num2);	
}
//=======================


//=======================
class RGBA
{
public:
	RGBA()
	{
		m_red = m_green = m_blue = 0; ///Как синтаксически реализовать этот способ инициализации во 2-м пути конструктора?
		m_alpha = 255;
	}

	RGBA(std::uint8_t a, std::uint8_t b, std::uint8_t c, std::uint8_t d)
		:
		  m_red(a)
		, m_green(b)
		, m_blue(c)
		, m_alpha(d)
	{}

	void print();

private:
	std::uint8_t m_red, m_green, m_blue, m_alpha;	
};

void RGBA::print()
{
	std::cout << "\nR - " << static_cast<uint16_t>(m_red);
	std::cout << "\nG - " << static_cast<uint16_t>(m_green);
	std::cout << "\nB - " << static_cast<uint16_t>(m_blue);
	std::cout << "\nA - " << static_cast<uint16_t>(m_alpha) << "\n";
}
//=======================


//=======================

class Stack
{
public:
	Stack()      // Нужно ли здесь инициализировать? Или достаточно метода reset() ? 
		         // Просто в ресет у меня цикл до "len", чтобы лишний раз не делать for на все 10 элементов
		: arr{0} 
	    , len(0)
	{}             
	void reset();
	bool push(int a);
	void pop();
	void print();

private:
	int arr[10];
	int len;
};

void Stack::reset()
{	
	for (size_t i = 0; i < len; ++i)
	{
		arr[i] = 0;
	}
	len = 0;
}

bool Stack::push(int a)
{	
	if (arr[len] == 0 && len < 10) 
	{ 
		arr[len] = a; 
		len++; 
	}
	else
	{
		std::cout << "Stack is full\n";
	}

	return (len < 10) ?  true : false;
}

void Stack::pop()
{
	if (len == 0) { std::cout << "Stack is empty"; return; }
	if (arr[len - 1] != 0) { arr[len - 1] = 0;	len--; }
}

void Stack::print()
{
	std::cout << "( ";
	for (size_t i = 0; i < len; ++i)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << ")" << "\n";
	
} 

//=======================

int main()
{
// Task 1 ------------ {
		Power num;
		num.setNums(5.5, 2.3);
		std::cout << "Power - " << num.calculate();
// Task 1 ------------ }

// Task 2 ------------ {
		RGBA obj1;
		obj1.print();

		RGBA obj2(1, 5, 7, 250);
		obj2.print();
// Task 2 ------------ }

// Task 3 ------------ {
	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();	
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();
// Task 3 ------------ }
	return 0;
	
}