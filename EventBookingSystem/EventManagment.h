#pragma once
#include <vector>
#include "Event.h"
class EventManagment
{
private:
	std::vector<Event> events_vector;
public:
	void AddEvent(void);
	std::vector<Event>* GetAllEvents(void);
};

