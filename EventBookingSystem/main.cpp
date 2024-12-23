//77. Design and implement classes for an event booking system. (5.0)
//https://miro.com/app/board/uXjVLzp9SIo=/

#include "main.h"

int main(void) {
	
	std::vector<int> wektor;
	wektor.push_back(1);
	wektor.push_back(3);
	wektor.push_back(5);
	
	for (auto i = wektor.begin(); i != wektor.end(); ++i)
		std::cout << *i << " ";

	return 0;
}