#pragma once
#include <string>
class User
{
private:
	std::string username;
public:
	User(std::string name_v);
	std::string Get_Name(void);
	User() = default;
	
};

