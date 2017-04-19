#pragma once

#include "EventSource.h"

typedef Vector<EventSource*> EventSourceVector;

class EventTarget : public EventSource
{
private:
	// for source-target event communications
	EventSourceVector eventSourceVector;

protected:
	virtual	void processEvent(Event event) = 0;

public:
	EventTarget(const type_info& typeInfo): EventSource(typeInfo) {}
	virtual ~EventTarget() {}

	bool isEventTarget() { return true; }

	void addEventSource(EventSource *pEventSource){ this->eventSourceVector.push_back(pEventSource); }
	EventSourceVector* getEventSourceVector() { return &(this->eventSourceVector); }

	void putEvent(Event event) {
		this->processEvent(event);
	}
};
