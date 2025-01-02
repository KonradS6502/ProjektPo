#include "Event.h"

Event::Event(std::string name_v, int capacity_v, int id_v) : name(name_v), capacity(capacity_v), id(id_v) {
	booked = 0;
}



//Show how many seats left in this event
int Event::HowManyLeftSeats(void) {
	return(capacity - booked);
}

 
int Event::AddUser(User* user) {
	if (booked < capacity) {
		users.push_back(user);
		booked += 1;
		return 0;
	}
	
	return 1;
}
int Event::RemoveUser(User* user) {
	auto it = std::find(users.begin(), users.end(), user);
	if (it != users.end()) {
		users.erase(it);
		booked -= 1;
		return 0;
	}
	return 1;
}

//Show all registered users
void Event::PrintAllUsers(void) {
	for(auto i : users){
		std::cout <<" - " << i->Get_Name() << "\n";
	}
}

std::string Event::Get_Name(void) {
	return(name);
}

int Event::Get_ID(void) {
	return(id);
}

int Event::Get_Capacity(void) {
	return(capacity);
}

std::vector<User*>* Event::Get_AllUsers(void) {
	return(&users);
}