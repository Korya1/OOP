#include "Task_1.h"
#include "Task_2.h"

int main()
{
//---- task 1 {	
	run();
//---- task 1 }

//---- task 2 {
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
//---- task 2 }

	return 0;
}



