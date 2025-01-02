//77. Design and implement classes for an event booking system. (5.0)
//https://miro.com/app/board/uXjVLzp9SIo=/

#include "main.h"
#include <fstream>
#include <algorithm>


int main(void) {
	Reader::getInstance().Read_events();
	Reader::getInstance().Read_users();
	std::string user_login_text;
	std::string user_login;
	while(1){

	std::cout << user_login_text << user_login <<"\n";
	
	int i = 0;
	std::cout  << "1. Zaloguj sie\n";
	std::cout  << "2. Dodaj uzytkownika\n";
	std::cout  << "3. Dodaj event\n";
	std::cout  << "4. Zapisz sie na event\n";
	std::cout  << "5. Pokaz moje eventy\n";
	std::cout  << "6. Wypisz sie z eventu\n";
	std::cout  << "7. Zapisz i wyjdz\n";

	int input_menu = 0;
	std::string temp;
	std::string input_string = "";
	std::cout << "\nWybierz funkcje: ";
	std::cin >> input_string;
	try {
		input_menu=std::stoi(input_string);
	}
	catch(...){
		std::cout << "\033[2J\033[H";
		std::cout << "Wpisz poprawnie!!\n";
		continue;
	}
	switch (input_menu) {
	case(1):
		std::cout << "\033[2J\033[H";
		std::cout << "Wpisz nazwe uzytkownika:\n";
		std::getline(std::cin >> std::ws, input_string);
		if (EventManagment::getInstance().GetAllUsers()->find(input_string) != EventManagment::getInstance().GetAllUsers()->end()) {
			user_login_text = "Zalogowano jako: ";
			user_login = input_string;
			std::cout << "\033[2J\033[H";
		}
		else {
			std::cout << "\033[2J\033[H";
			std::cout << "Nie znaleziono takiego uzytkownika.\n";
		}
		break;
	case(2):
		std::cout << "\033[2J\033[H";
		std::cout << "Wpisz nazwe uzytkownika do dodania:\n";
		std::getline(std::cin >> std::ws, input_string);
		EventManagment::getInstance().AddUser(input_string);
		std::cout << "\033[2J\033[H";
		std::cout << "Dodano poprawnie uzytkownika\n";
		break;
	case(3):
		while (1) {
			std::cout << "\033[2J\033[H";
			std::cout << "Wpisz nazwe eventu do dodania:\n";
			std::getline(std::cin >> std::ws, input_string);
			temp = input_string;
			std::cout << "Wpisz pojemnosc eventu:\n";
			std::getline(std::cin >> std::ws, input_string);
			try {
				input_menu = std::stoi(input_string);
			}
			catch (...) {
				std::cout << "\033[2J\033[H";
				std::cout << "Wpisz poprawnie!!\n";
				continue;
			}
			EventManagment::getInstance().AddEvent(temp, input_menu);
			break;
		}

		break;
		case(4):
			std::cout << "\033[2J\033[H";
			if (user_login == "") {
				std::cout << "\033[2J\033[H";
				std::cout << "Musisz byc zalogowany, aby zapisac sie na event.\n";
				break;
			}
			i_events = 1;
			for (auto n = EventManagment::getInstance().GetAllEvents()->begin(); n != EventManagment::getInstance().GetAllEvents()->end(); ++n) {
				std::cout << i_events++<< ". " << n->second.Get_Name() << "\n";
				i_event_vector.push_back(n->second.Get_Name());
			}
			std::cout << "Aby wyjsc wpisz exit.\n";
			std::cout << "\nWybierz event:";
			std::getline(std::cin >> std::ws, input_string);
			if (input_string == "exit") {
				std::cout << "\033[2J\033[H";
				break;
			}
			try {
				input_menu = std::stoi(input_string);
			}
			catch (...) {
				std::cout << "Wpisz poprawnie!!\n";
			}
			EventManagment::getInstance().AddUserToEvent(user_login, i_event_vector[input_menu-1]);
			i_event_vector.clear();
			std::cout << "\033[2J\033[H";
			std::cout << "Zapisano cie na event poprawnie\n";
			break;
		case(5):
			std::cout << "\033[2J\033[H";
			if(user_login == "") {
				std::cout << "\033[2J\033[H";
				std::cout << "Musisz byc zalogowany, aby zobaczyc swoje eventy.\n";
				break;
			}
			i_events = 1;
			for (auto n = EventManagment::getInstance().GetAllEvents()->begin(); n != EventManagment::getInstance().GetAllEvents()->end(); ++n)
			{
				std::vector<User*> temp_vector = *n->second.Get_AllUsers();
				for (auto i : temp_vector) {
					if (i->Get_Name() == user_login) {
						std::cout << i_events++ << ". " << n->first + "\n";
					}
				}

			}
			std::cout << "Wcisnij enter, aby przejsc dalej.\n";
			_getch();
			std::cout << "\033[2J\033[H";
			break;
		
		case(6):
			while (1) {
				if (user_login == "") {
					std::cout << "\033[2J\033[H";
					std::cout << "Musisz byc zalogowany, aby usunac sie z eventu.\n";
					break;
				}
				i_events = 1;
				for (auto n = EventManagment::getInstance().GetAllEvents()->begin(); n != EventManagment::getInstance().GetAllEvents()->end(); ++n)
				{
					std::vector<User*> temp_vector = *n->second.Get_AllUsers();
					for (auto i : temp_vector) {
						if (i->Get_Name() == user_login) {
							i_event_vector.push_back(n->first);
							std::cout << i_events++ << ". " << n->first + "\n";
						}
					}

				}
				std::cout << "Aby wyjsc wpisz exit.\n";
				std::cout << "\nWybierz event:";
				std::getline(std::cin >> std::ws, input_string);
				if (input_string == "exit") {
					std::cout << "\033[2J\033[H";
					break;
				}
				try {
					input_menu = std::stoi(input_string);
				}
				catch (...) {
					std::cout << "Wpisz poprawnie!!\n";
				}
				EventManagment::getInstance().RemoveUserFromEvent(user_login, i_event_vector[input_menu - 1]);
				i_event_vector.clear();
				std::cout << "\033[2J\033[H";
				std::cout << "Usunieto cie z eventu poprawnie\n";
				break;
			}
			break;
		
		case(7):
			Reader::getInstance().Save_events();
			Reader::getInstance().Save_users();
			return(0);
			break;
		default:
			std::cout << "Wpisz poprawnie!!\n";
			break;
	}
	}
	//
	//
	//std::getline(std::cin, input_string);
	//if (EventManagment::getInstance().GetAllUsers()->find(input_string) != EventManagment::getInstance().GetAllUsers()->end()) {
	//	std::cout << "znaleziono\n";
	//}

	//for (auto n = EventManagment::getInstance().GetAllEvents()->begin(); n != EventManagment::getInstance().GetAllEvents()->end(); ++n)
	//{

	//	std::vector<User*> temp_vector = *n->second.Get_AllUsers();
	//	for (auto i : temp_vector) {
	//		if (i->Get_Name() == input_string) {
	//			std::cout << n->first + "\n";
	//		}
	//	}

	//}


	//for (auto i = EventManagment::getInstance().GetAllEvents()->begin(); i != EventManagment::getInstance().GetAllEvents()->end(); ++i)
	//	std::cout << i->second.Get_Name() << "\n";
	//	//i->second.PrintAllUsers();
	//auto x = EventManagment::getInstance().GetAllEvents();

	//
	//for (auto i = EventManagment::getInstance().GetAllUsers()->begin(); i != EventManagment::getInstance().GetAllUsers()->end(); ++i)
	//	std::cout << i->second.Get_Name() << "\n";
	//auto y = EventManagment::getInstance().GetAllUsers();
	
		
		
	return 0;
 }