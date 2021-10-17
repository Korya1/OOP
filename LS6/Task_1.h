#pragma once
#include "Common.h"

// Это был первый вариант кода, который я написал сам! 
// но он не обробатывал ошибку 1n и выводил 1
void enterNumber_1()
{
	int num;
	bool valid = false;
	do
	{
		std::cout << "Enter a number\n";
		std::cin >> num;
		if (std::cin.fail())
		{
			std::cout << "Error!!!\n\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			valid = true;
		}


	} while (!valid);

	if (valid) { std::cout << "Your number is: " << num; }
}


//Это второй вариант кода, в котором мне помогли и он обробатывает ошибку 1n
void enterNumber_2()
{
	int input;
	while (true)
	{
		std::cout << "Enter a number: " << std::flush;
		std::string line;
		
		if (!getline(std::cin, line)) {
			std::cerr << "Critical error!!!" << '\n';
			return;
		}
		std::istringstream line_stream(line);
		char extra;
		if (line_stream >> input && !(line_stream >> extra))
			break;
		else
			std::cout << "Error!!!" << '\n';
	}
	std::cout << input << '\n';
}