#include "EventManagment.h"


EventManagment& EventManagment::getInstance() {
	static EventManagment instance;
	return(instance);
}

int EventManagment::AddEvent(std::string name_v, int capacity_v) {
	static int id_v = 0;
	if (events_map.find(name_v) == events_map.end()) {
		events_map.insert(std::pair<std::string, Event>(name_v, Event(name_v,capacity_v,id_v++)));
		return 0;
	}
	return 1;
}

int EventManagment::AddUser(std::string username_v) {
	if (users_map.find(username_v) == users_map.end()) {
		users_map.insert(std::pair<std::string, User>(username_v, User(username_v)));
		return 0;
	}
	return 1;
}


int EventManagment::AddUserToEvent(std::string user_username_v, std::string event_name_v)
{
	if ((events_map.find(event_name_v) != events_map.end()) || (users_map.find(user_username_v) != users_map.end())) {
		events_map[event_name_v].AddUser(&users_map[user_username_v]);
		return 0;
	}
	
	return 1;
}


std::map<std::string, Event>* EventManagment :: GetAllEvents(void) {
	return(&events_map);
};

std::map <std::string, User>* EventManagment::GetAllUsers(void) {
	return(&users_map);
}