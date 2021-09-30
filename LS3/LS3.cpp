#include "Task_1.h"
#include "Task_2.h"
#include "Task_3.h"
#include "Task_4.h"

int main()
{
	//
	//   task 1
	//
	Figure* f = new Circle(4);
	f->area();
	delete f;
	//
	//   task 2
	//
	Minivan m;
	//
	//   task 3
	//

	Fraction a(2, 2), b(2, 0), c;

	c = a + b;

	c.getResult();

	//
	//   task 4
	//
	Card card(Club, Ace);
	std::cout << card.getValue();


	return 0;
}



