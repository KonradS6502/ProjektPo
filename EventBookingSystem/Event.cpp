#include "Event.h"

Event::Event(std::string vname, int vcapacity) : name(vname), capacity(vcapacity) {
	booked = 0;
};

void Event::AddUser(User* user) {
	if (booked < capacity) {
		users.push_back(user);
		booked += 1;
	}
	
}