#pragma once

#include "../../Common/Utility/Map.h"
#include "../../Common/Utility/Queue.h"

#include "../Component/Component.h"
#include "../Component/EventSource.h"
#include "../Component/EventTarget.h"

#include "Event.h"
using namespace std;

typedef SafeQueue<Event> SafeEventQueue;
typedef Map<int, EventSource *> EventSourceMap;
typedef Map<int, EventTarget *> EventTargetMap;

class Scheduler: public EventTarget {
private:
	SafeEventQueue sourceEventQueue;
	SafeEventQueue targetEventQueue;

	EventSourceMap eventSourceMap;
	EventTargetMap eventTargetMap;

protected:
	// As a component
	virtual void generateEvents() {}
	virtual void processEvent(Event event) {}

	// As a scheduler
	virtual void collectEvents();
	virtual void distributeEvent();

public:
	Scheduler();
	virtual ~Scheduler();
	virtual int initialize();

	void clearSourceEvents() { this->sourceEventQueue.clear(); }
	void clearTargetEvents() { this->targetEventQueue.clear(); }

	EventQueue* getEvents() { return &(this->sourceEventQueue); }
	void putEvent(Event event) { this->targetEventQueue.enQueue(event); }


	void addComponent(Component *pComponent);
	void configureComponents();

	void run();
};


