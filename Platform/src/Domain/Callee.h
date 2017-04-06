/*
 * Callee.h
 *
 *  Created on: 2017. 4. 2.
 *      Author: choi.sungwoon
 */

#ifndef DOMAIN_CALLEE_H_
#define DOMAIN_CALLEE_H_

#include "../../Framework/Component/EventTarget.h"

enum eventType { eInvoke = __COUNTER__ };


class Parameters: public ValueObject{

public:
	int initialize() { return 0; }
	void setValue(void* pValue) { this->pValue = pValue; }
	void* getValue() { return this->pValue; }
};
class ReturnValue: public ValueObject {
public:
	int initialize() { return 0; }
	void setValue(void* pValue) { this->pValue = pValue; }
	void* getValue() { return this->pValue; }
};



#define targetFunctionID __COUNTER__
class CalleeInterface: public EventTarget {
public:
	virtual int targetFunction(int i) = 0;
	void processEvent(Event event) {
		if (event.getType() == eInvoke) {
			if (event.iArg == targetFunctionID) {
				int i = event.getPArg();
			}
		}
	}

};

class Callee: public CalleeInterface {
public:
	Callee() {}
	virtual ~Callee() {}
	int initialize() {
		return 0;
	}

	int targetFunction(int i) {
		return 0;
	}

	vector<Event> generateEventQueue() {
		return 0;
	}
	void processEvent(Event event) {

	}
};




#endif /* DOMAIN_CALLEE_H_ */
