#pragma once

#include <vector>
using namespace std;

#include "Component.h"
#include "EventTargetID.h"
#include "../../Framework/Scheduler/Event.h"

class EventSource : public Component
{
private:
	vector<EventTargetID> eventTargetIDs;
	vector<Event> sourceEvents;
protected:
	virtual void prepareEvents() = 0;

	vector<Event> getSourceEvents() { return this->sourceEvents; }

	void addEventTargetID(int componentID, int schedulerID) {
		EventTargetID eventTargetID(componentID, schedulerID);
		this->eventTargetIDs.push_back(eventTargetID);
	}
	void addEvent(int type, ValueObject* pArg) {
		Event event;
		event.setType(type);
		event.setPArg(pArg);
		this->sourceEvents.push_back(event);
	}
	void addEvent(Event event) {
		this->sourceEvents.push_back(event);
	}

public:
	EventSource() {}
	virtual ~EventSource() {}

	bool isEventSource() { return true; }

	vector<Event> generateEvents() {
		this->prepareEvents();
		vector<Event> targetEvents;
		for (vector<Event>::iterator eventItr=this->sourceEvents.begin(); eventItr!=this->sourceEvents.end(); eventItr++) {
			for (vector<EventTargetID>::iterator idItr=this->eventTargetIDs.begin(); idItr!=this->eventTargetIDs.end(); idItr++) {
				(*eventItr).setSourceID(this->getID());
				(*eventItr).setTargetID(idItr->getComponentID());
				(*eventItr).setTargetSchedulerID(idItr->getSchedulerID());
				targetEvents.push_back(*eventItr);
			}
		}
		this->sourceEvents.clear();
		return targetEvents;
	}
};



