//77. Design and implement classes for an event booking system. (5.0)
//https://miro.com/app/board/uXjVLzp9SIo=/

#include "main.h"
#include <fstream>
#include <algorithm>


int main(void) {
	Reader::getInstance().Read_events();
	Reader::getInstance().Read_users();
	std::string input_string;
	std::cout << "Wpisz nazwe uzytkownika:\n";
	std::getline(std::cin, input_string);

	for (auto n = EventManagment::getInstance().GetAllEvents()->begin(); n != EventManagment::getInstance().GetAllEvents()->end(); ++n)
	{

		std::vector<User*> temp_vector = *n->second.Get_AllUsers();
		for (auto i : temp_vector) {
			if (i->Get_Name() == input_string) {
				std::cout << n->first + "\n";
			}
		}

	}
	//for (auto i = EventManagment::getInstance().GetAllEvents()->begin(); i != EventManagment::getInstance().GetAllEvents()->end(); ++i)
	//	std::cout << i->second.Get_Name() << "\n";
	//	//i->second.PrintAllUsers();
	//auto x = EventManagment::getInstance().GetAllEvents();

	//
	//for (auto i = EventManagment::getInstance().GetAllUsers()->begin(); i != EventManagment::getInstance().GetAllUsers()->end(); ++i)
	//	std::cout << i->second.Get_Name() << "\n";
	//auto y = EventManagment::getInstance().GetAllUsers();
	Reader::getInstance().Save_events();
	Reader::getInstance().Save_users();
		
		
	return 0;
 }