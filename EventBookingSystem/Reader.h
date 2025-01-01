#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "EventManagment.h"
class Reader {

private:
	std::string Event_file;
	std::string User_file;
	void Init(void);

public:
	void Read_events(void);
	void Read_users(void);

	void Save_events(void);
	void Save_users(void);

private:
	Reader() = default;

public:
	static Reader& getInstance();
	Reader(const Reader&) = delete;
	Reader& operator=(const Reader&) = delete;
	Reader(Reader&&) = delete;
	Reader& operator=(Reader&&) = delete;
};