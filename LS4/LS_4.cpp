#include "Task_1.h"
#include "Task_3.h"

int main()
{
//============ task 1
	My::Vector vector;
	vector.push_back(4);
	vector.push_back(1);
	vector.push_back(3);
	vector.push_back(5);
	vector.push_back(2);
	vector.sort();
	vector.print();

//============ task 2

	std::vector<int> vec{ 1, 1, 3, 5, 2, 3, 1, 2 };
	std::sort(begin(vec), end(vec));
	vec.erase(std::unique(begin(vec), end(vec)), end(vec));		
	for (auto value : vec)
	{
		std::cout << value << " ";
	}
//============ task 3
	Hand hand;
	Card card(Diamond, Ace);
	Card card2(Heart, Ace);
	Card card3(Club, Ace);
	Card card4(Club, Three);
	
	hand.addCard(&card);
	hand.addCard(&card2);
	hand.addCard(&card3);
	hand.addCard(&card4);
	
	std::cout << hand.getValue();


	return 0;
}

