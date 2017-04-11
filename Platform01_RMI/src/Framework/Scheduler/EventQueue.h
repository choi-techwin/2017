#pragma once
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <queue>
using namespace std;

#include "Event.h"

class EventQueue {
private:
	CRITICAL_SECTION lock;
	vector<Event> eventQueue;
public:
	EventQueue();
	virtual ~EventQueue();
	virtual int initialize() { return 0; }

	bool empty() { return this->eventQueue.empty(); }
	vector<Event> getEventQueue() { return this->eventQueue; }

	void enQueue(Event event);
//	void enQueue(vector<Event> eventQueue);
	Event deQueue();

};

