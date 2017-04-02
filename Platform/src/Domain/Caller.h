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

enum eventType { eInvoke = __COUNTER__ };

class ReturnValue: public ValueObject {
};

class Caller: public EventTarget
{
private:
	int calleeID;
public:
	Caller() {

	}
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
