#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "User.h"
#include "Data.h"
class Event
{
	private:
		int id;
		Data date;
		int capacity;
		int booked;
		std::string name;
		std::vector<User*> users;
		
	public:
		Event(std::string name_v, int capacity_v, int id_v);
		int HowManyLeftSeats(void);
		int AddUser(User* user);
		int RemoveUser(User* user);
		void PrintAllUsers(void);
		std::string Get_Name(void);
		int Get_ID(void);
		int Get_Capacity(void);
		std::vector<User*>* Get_AllUsers(void);
		Event() = default;

		
};

