#pragma once

#include <vector>
using namespace std;

#include "Component.h"
#include "EventTargetID.h"
#include "../../Framework/Scheduler/Event.h"

class EventSource : public Component
{
private:
	vector<EventTargetID> eventTargetIDVector;
	vector<Event> eventVector;
public:
	EventSource() {}
	virtual ~EventSource() {}

	bool isEventSource() { return true; }

	void addEventTargetID(int componentID, int schedulerID) {
		EventTargetID eventTargetID(componentID, schedulerID);
		this->eventTargetIDVector.push_back(eventTargetID);
	}
	vector<EventTargetID> getEventTargetIDVector() { return this->eventTargetIDVector; }

	void addEvent(int type, ValueObject* pArg) {
		Event event;
		event.setType(type);
		event.setPArg(pArg);
		this->eventVector.push_back(event);
	}
	vector<Event> generateEvents() {
		vector<Event> targetEventVector;
		for (vector<Event>::iterator eventItr=this->eventVector.begin(); eventItr!=this->eventVector.end(); eventItr++) {
			for (vector<EventTargetID>::iterator idItr=this->eventTargetIDVector.begin(); idItr!=this->eventTargetIDVector.end(); idItr++) {
				(*eventItr).setSourceID(this->getID());
				(*eventItr).setTargetID(idItr->getComponentID());
				(*eventItr).setTargetSchedulerID(idItr->getSchedulerID());
				targetEventVector.push_back(*eventItr);
			}
		}
		this->eventVector.clear();
		return targetEventVector;
	}

	virtual void prepareEvents() {};
};



