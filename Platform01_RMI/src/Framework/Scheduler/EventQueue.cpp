#include "EventQueue.h"

EventQueue::EventQueue() {
	InitializeCriticalSection(&this->lock);
}

EventQueue::~EventQueue() {
}

void EventQueue::enQueue(Event event) {
	EnterCriticalSection(&this->lock);
	this->eventQueue.push_back(event);
	LeaveCriticalSection(&this->lock);
}

//void EventQueue::enQueue(vector<Event> eventQueue) {
//	if (eventQueue.empty()) return;
//
//	EnterCriticalSection(&this->lock);
//	for (vector<Event>::iterator itr = eventQueue.begin(); itr!=eventQueue.end(); itr++) {
//		this->eventQueue.push_back(*itr);
//	}
//	eventQueue.clear();
//	LeaveCriticalSection(&this->lock);
//}

Event EventQueue::deQueue() {
	Event event;

	EnterCriticalSection(&this->lock);
	event = this->eventQueue.front();
	this->eventQueue.erase(this->eventQueue.begin());
	LeaveCriticalSection(&this->lock);

	return event;
}
