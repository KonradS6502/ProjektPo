#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include "Event.h"
#include "User.h"
class EventManagment
{
private:
	std::map<std::string, Event> events_map;
	std::map <std::string, User> users_map;
	EventManagment() = default;
public:
	
	int AddEvent(std::string name_v, int capacity_v);
	int AddUser(std::string username_v);
	
	int AddUserToEvent(std::string user_username_v, std::string event_name_v);
	int RemoveUserFromEvent(std::string user_username_v, std::string event_name_v);
	std::map<std::string, Event>* GetAllEvents(void);
	std::map <std::string, User>* GetAllUsers(void);
public:
	static EventManagment& getInstance();
	EventManagment(const EventManagment&) = delete;
	EventManagment& operator=(const EventManagment&) = delete;
	EventManagment(EventManagment&&) = delete;
	EventManagment& operator=(EventManagment&&) = delete;
};

