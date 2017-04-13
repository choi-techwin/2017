#pragma once

#include <map>
using namespace std;

#include "EventQueue.h"

#include "../Component/Component.h"
#include "../Component/EventSource.h"
#include "../Component/EventTarget.h"

class Scheduler: public EventTarget {
protected:
	EventQueue eventQueue;

	map<int, EventSource *> eventSourceMap;
	map<int, EventTarget *> eventTargetMap;

	void distributeEvent();
	virtual void prepareEvents();
public:
	Scheduler();
	virtual ~Scheduler();
	virtual int initialize();

	void addComponent(Component *pComponent);
	void configureComponents();

	virtual vector<Event> generateEvents();

	virtual void processEvent(Event event) {
		this->eventQueue.enQueue(event);
	}

	void run();
};


