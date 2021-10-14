#include "Task_1.h"
#include "Task_2.h"
#include "Task_3.h"
#include "Task_4.h"

int main()
{
//----------- Task 1
	enterNumber_2();

//----------- Task 2
	endll endl;

	std::cout << "Hello" << endl;
	std::cout << "World";

//----------- Task 3
	Player p("Ivan");
	std::cout << p.IsHitting();

//----------- Task 4, 5	
	Card c(Diamond, Ace);
	Card c2(Spade, Three);
	Card c3(Spade, Ace);
	c.flip();
	c2.flip();
	c3.flip();	
	
	p.addCard(&c);
	p.addCard(&c2);
	p.addCard(&c3);
	
	std::cout << p;

	return 0;
}

