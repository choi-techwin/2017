/*
 * Main.h
 *
 *  Created on: 2017. 4. 2.
 *      Author: choi.sungwoon
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <string>
#include <vector>
using namespace std;

#include "Callee.h"
#include "Caller.h"

class Scheduler {
private:
	vector<Event*> events;
public:
	Scheduler() {}
	virtual ~Scheduler() {}
	void append(vector<Event*> other) {
		for (vector<Event*>::iterator itr=other.begin(); itr!=other.end(); itr++) {
			this->events.push_back((*itr));
		}
	}
	void execute() {
		// new Components
		Caller caller(1);
		Callee callee(2);
		// event-based function invocation association
		caller.associate(callee.getId());

		// prepare start event: caller::eStart
		Event* pEvent = new Event();
		pEvent->setType(eStart);
		pEvent->setTargetID(caller.getId());
		events.push_back(pEvent);

		while(true) {
			// dequeue
			if (!this->events.empty()) {
				// dequeue a event
				pEvent = this->events.front();
				this->events.erase(this->events.begin());

				// dispatch a event to a target component
				if (pEvent->getTargetID() == caller.getId()) {
					caller.processAllEvents(pEvent);
				} else if (pEvent->getTargetID() == callee.getId()) {
					callee.processAllEvents(pEvent);
				}
			}

			// get events from eventSources
			vector<Event*> buffer;

			buffer = caller.generateEvents();
			this->append(buffer);
			caller.clearEvents();

			buffer = callee.generateEvents();
			this->append(buffer);
			callee.clearEvents();
		}
	}
};

#endif /* SCHEDULER_H_ */
