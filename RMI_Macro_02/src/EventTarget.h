/*
 * EventTarget.h
 *
 *  Created on: 2017. 4. 2.
 *      Author: choi.sungwoon
 */

#ifndef EVENTTARGET_H_
#define EVENTTARGET_H_

#include <iostream>
#include <vector>
using namespace std;

#include "Event.h"

class EventTarget {
private:
	int id;
	vector<Event*> events;

	void append(vector<Event*>& other) {
		for (vector<Event*>::iterator itr=other.begin(); itr!=other.end(); itr++) {
			this->events.push_back((*itr));
		}
	}
protected:
	virtual void setEvent(Event* pEvent) {
		this->events.push_back(pEvent);
	}

	virtual void processEvent(Event* pEvent) = 0;
	virtual void processReturnEvent(Event* pEvent) {};

public:
	EventTarget(int id): id(id) {}
	virtual ~EventTarget() {}
	virtual void initialize() {}

	int getId() { return this->id; }

	void processAllEvents(Event* pEvent) {
		this->processEvent(pEvent);
		this->processReturnEvent(pEvent);
	}
	vector<Event *> generateEvents() {
		return this->events;
	}
	void clearEvents() {
		this->events.erase(this->events.begin(), this->events.end());
	}
};



#endif /* EVENTTARGET_H_ */
