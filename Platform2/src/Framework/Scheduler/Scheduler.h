#pragma once

#include <map>
using namespace std;

#include "../Component/EventTarget.h"
#include "../Component/Component.h"
#include "EventQueue.h"
#include "../../Domain/PWM/PWM.h"

class Scheduler: public EventTarget {
protected:
	EventQueue eventQueue;
	EventQueue sourceEventQueue;
	map<int, EventSource *> eventSourceMap;
	map<int, EventTarget *> eventTargetMap;

	void sendEvent();
	void collectEvents();
public:
	Scheduler();
	virtual ~Scheduler();
	virtual int initialize();

	void addComponent(Component *pComponent);
	void configureComponents();

	virtual vector<Event> generateEventQueue(){ return this->sourceEventQueue.getEventQueue(); }
	virtual void processEvent(Event event){ this->eventQueue.enQueue(event); }

	void run();
};


