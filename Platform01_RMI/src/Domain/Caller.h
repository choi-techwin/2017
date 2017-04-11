/*
 * Caller.h
 *
 *  Created on: 2017. 4. 2.
 *      Author: choi.sungwoon
 */

#ifndef DOMAIN_CALLER_H_
#define DOMAIN_CALLER_H_

#include "../../Framework/Component/EventTarget.h"
#include "Callee.h"

class Caller: public EventTarget
{
private:
	int calleeID;
public:
	Caller() { this->calleeID = 0; }
	virtual ~Caller() {}

	int initialize() {
		return 0;
	}

	vector<Event> generateEventQueue() {
		Event event;
		event.setType(eInvoke);
		event.setSourceID(this->getID());
		event.setTargetID(this->calleeID);
		return 0;
	}
	void processEvent(Event event) {}
};

#endif /* DOMAIN_CALLER_H_ */
