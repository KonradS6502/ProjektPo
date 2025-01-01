#include "Reader.h"

void Reader::Init(void) {
	Event_file = "Events.txt";
	User_file = "Users.txt";
}
Reader& Reader::getInstance() {
	static Reader instance;
	instance.Init();
	return(instance);
}

void Reader::Read_events(void) {
	std::ifstream eventfile;
	eventfile.open(Event_file);
	char buffer_char;
	std::string string_buffer = "";
	std::vector<std::string> values_vector;
	while (eventfile.get(buffer_char)) {
		if (buffer_char == *",") {
			values_vector.push_back(string_buffer);
			string_buffer = "";
		}
		else if (buffer_char == *";") {
			values_vector.push_back(string_buffer);
			string_buffer = "";
			EventManagment::getInstance().AddEvent(values_vector[0], std::stoi(values_vector[1]));
			values_vector.clear();
		}
		else {
			string_buffer += buffer_char;
		}
	}
	eventfile.close();
}

void Reader::Read_users(void) {
	std::ifstream userfile;
	userfile.open(User_file);
	char buffer_char;
	std::string string_buffer = "";
	std::vector<std::string> values_vector;
	while (userfile.get(buffer_char)) {
		if (buffer_char == *",") {
			values_vector.push_back(string_buffer);
			string_buffer = "";
		}
		else if (buffer_char == *";") {
			values_vector.push_back(string_buffer);
			string_buffer = "";
			EventManagment::getInstance().AddUser(values_vector[0]); // First element is the username and second is id
			if (values_vector.size() > 1) {
				for (int i = 1; i < values_vector.size(); i++) {
					EventManagment::getInstance().AddUserToEvent(values_vector[0], values_vector[i]);
				}
			}
			values_vector.clear();
		}
		else {
			string_buffer += buffer_char;
		}
	}
	userfile.close();
}

void Reader::Save_events(void) {
	std::ofstream eventfile(Event_file);
	for (auto i = EventManagment::getInstance().GetAllEvents()->begin(); i != EventManagment::getInstance().GetAllEvents()->end(); ++i) {
		eventfile << i->second.Get_Name() + "," + std::to_string(i->second.Get_Capacity()) + ";";

	}
	eventfile.close();
}

void Reader::Save_users(void) {
	std::ofstream userfile(User_file);
	for (auto i = EventManagment::getInstance().GetAllUsers()->begin(); i != EventManagment::getInstance().GetAllUsers()->end(); ++i) {
		std::string temp_string = "";
		for (auto n = EventManagment::getInstance().GetAllEvents()->begin(); n != EventManagment::getInstance().GetAllEvents()->end(); ++n)
		{

			std::vector<User*> temp_vector = *n->second.Get_AllUsers();
			if (std::find(temp_vector.begin(), temp_vector.end(), &i->second) != temp_vector.end()) {
				temp_string = temp_string + "," + n->second.Get_Name();
			}

		}
		userfile << i->second.Get_Name() + temp_string + ";";
	}
	userfile.close();
}