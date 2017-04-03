/*
 * Main.h
 *
 *  Created on: 2017. 4. 2.
 *      Author: choi.sungwoon
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <string>
#include <vector>
using namespace std;

#include "Callee.h"
#include "Caller.h"

class Main {
private:
	vector<Event*> events;
public:
	Main() {}
	virtual ~Main() {}
	void append(vector<Event*>& other) {
		for (vector<Event*>::iterator itr=other.begin(); itr!=other.end(); itr++) {
			this->events.push_back((*itr));
		}
	}
	void execute() {
		Callee callee(1);
		Caller caller(2);
		caller.associate(callee.getId());

		Event event;
		event.setType(eStart);
		event.setTargetID(2);
		events.push_back(&event);

		while(true) {
			Event* pEvent = this->events.front();
			if (pEvent!=0) {
				this->events.erase(this->events.begin());
				if (pEvent->getTargetID() == caller.getId()) {
					caller.processAllEvent(pEvent);
				} else if (pEvent->getTargetID() == callee.getId()) {
					callee.processAllEvent(pEvent);
				}
			}
			vector<Event*> buffer;
			buffer = caller.generateAllEvents();
			this->append(buffer);
			buffer = callee.generateAllEvents();
			this->append(buffer);
		}
	}
};

#endif /* MAIN_H_ */
