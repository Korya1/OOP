#include <iostream>
#include "Task_1.h"
#include "Task_2.h"
#include "Task_3.h"


int main()
{
//================ 1
		try
		{
			int result = Div(2, 0);
			std::cout << result;
		}
		catch (const char* ex)
		{
			std::cerr << ex;
		}
//================ 2

	 Bar b(4);
	 int a;
	 try
	 {
		do
		{
			std::cout << "Input your nuber: ";
			std::cin >> a;

			b.set(a);

		} while (a != 0);

	 }
	 catch (const Ex& e)
	 {
		std::cout << e.x;
	 }

//================ 3

	Bar bar;
	int n;

	do {
		if (!std::cin.good())
		{
			std::cout << "Wrong input, try again.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		try {
			std::cout << "Enter integer value: ";
			std::cin >> n;
			bar.set(static_cast<double> (n));
		}
		catch (Ex& ex) {
			std::cout << "Something interesting has been caught.\n";
			std::cout << "Ex::x = " << ex.x << std::endl;
			break;
		}

	} while (true);
	

	Robot rob;	

	std::string up{ "up" };
	std::string down{ "down" };
	std::string right{ "right" };
	std::string left{ "left" };
	std::string forward{ "forward" };

	
	try {

		rob.move(forward);

	}
	catch (const OffTheField& exception)
	{
		std::cout << exception;
	}
	catch (const IllegalCommand& exception)
	{
		std::cout << exception;
	}	

	return 0;
}
