#include "User.h"


User::User(std::string name_v) {
	username = name_v;
}

std::string User::Get_Name(void) {
	return username;
}

