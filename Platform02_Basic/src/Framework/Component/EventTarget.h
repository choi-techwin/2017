#pragma once

#include <vector>
using namespace std;

#include "EventSource.h"

class EventTarget : public EventSource
{
private:
	vector<EventSource *> eventSourceVector;
public:
	EventTarget() {}
	virtual ~EventTarget() {}

	bool isEventTarget() { return true; }

	void addEventSource(EventSource *pEventSource){
		this->eventSourceVector.push_back(pEventSource);
	}
	vector<EventSource *> getEventSourceVector() { return this->eventSourceVector; }

	virtual	void processEvent(Event event) = 0;
};
