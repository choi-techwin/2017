#pragma once

#include <vector>
#include <queue>
using namespace std;

#include "Component.h"
#include "EventTargetID.h"
#include "../../Technical/Device/Sensor.h"
#include "../../Framework/Scheduler/Event.h"

class EventSource : public Component
{
private:
	vector<Sensor *> sensorVector;
protected:
	vector<EventTargetID> eventTargetIDVector;
public:
	EventSource() {}
	virtual ~EventSource() {}

	bool isEventSource() { return true; }

	void addEventTargetID(int componentID, int schedulerID) {
		EventTargetID eventTargetID(componentID, schedulerID);
		this->eventTargetIDVector.push_back(eventTargetID);
	}
	vector<EventTargetID> getEventTargetIDVector() { return this->eventTargetIDVector; }

	void addSensor(Sensor *pSensor) { this->sensorVector.push_back(pSensor); }
	vector<Sensor *> getSensorVector() { return this->sensorVector; }

	virtual vector<Event> generateEventQueue() = 0;
};



