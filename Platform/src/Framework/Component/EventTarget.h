#pragma once

#include <vector>
using namespace std;

#include "EventSource.h"
#include "Component.h"
#include "../../Technical/Device/Actuator.h"
#include "../../Framework/Scheduler/Event.h"

class EventTarget : public EventSource
{
private:
	vector<EventSource *> eventSourceVector;
	vector<Actuator *> actuatorVector;
public:
	EventTarget() {}
	virtual ~EventTarget() {}

	bool isEventTarget() { return true; }

	void addEventSource(EventSource *pEventSource){
		this->eventSourceVector.push_back(pEventSource);
	}
	vector<EventSource *> getEventSourceVector() { return this->eventSourceVector; }

	void addActuator(Actuator *pActuator){
		this->actuatorVector.push_back(pActuator);
	}
	vector<Actuator *> getActuatorVector() { return this->actuatorVector; }

	virtual	void processEvent(Event event) = 0;
};
