#ifndef COMPONENT_EVENTSOURCE_H_
#define COMPONENT_EVENTSOURCE_H_

#include "../../Common/Utility/Collection.h"
#include "Component.h"
#include "EventTargetID.h"
#include "../../Framework/Scheduler/Event.h"

typedef Vector<EventTargetID> EventTargetIDVector;
typedef Queue<Event> EventQueue;

enum EEvents { eEventSourceGenerated = __COUNTER__};

class EventSource : public Component
{
private:
	EventTargetIDVector eventTargetIDs;
	EventQueue sourceEventQueue;

protected:
	virtual void generateEvents() = 0;

	void addEvent(Event event) {
		for (EventTargetIDVector::Iterator itr=this->eventTargetIDs.begin(); itr!=this->eventTargetIDs.end(); itr++) {
			event.setSourceID(this->getID());
			event.setSourceSchedulerID(this->getSchedulerID());
			event.setTargetID(itr->getComponentID());
			event.setTargetSchedulerID(itr->getSchedulerID());
			this->sourceEventQueue.enQueue(event);
		}
	}
	void addEvent(int type, ValueObject* pArg) {
		Event currentEvent;
		currentEvent.setType(type);
		currentEvent.setPArg(pArg);
		this->addEvent(currentEvent);
	}
	EventQueue* getSourceEventQueue() { return &(this->sourceEventQueue); }

public:
	EventSource(const type_info& typeInfo): Component(typeInfo) {}
	virtual ~EventSource() {}
	virtual int initialize() = 0;

	bool isEventSource() { return true; }
	void clearEvents() { this->sourceEventQueue.clear(); }

	void addEventTargetID(int componentID, int schedulerID) {
		EventTargetID eventTargetID(componentID, schedulerID);
		this->eventTargetIDs.push_back(eventTargetID);
	}
	EventQueue* getEvents() {
		this->generateEvents();
		return &(this->sourceEventQueue);
	}
};

#endif  /* COMPONENT_EVENTSOURCE_H_ */

