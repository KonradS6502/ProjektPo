#pragma once
#include <string>
#include <vector>
#include "User.h"
#include "Data.h"
class Event
{
	private:
		Data date;
		int capacity;
		int booked;
		std::string name;
		std::vector<User*> users;
		
	public:
		Event(std::string name, int cap);
		void AddUser(User* user);
		
};

