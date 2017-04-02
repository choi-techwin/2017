/*
 * Callee.h
 *
 *  Created on: 2017. 4. 2.
 *      Author: choi.sungwoon
 */

#ifndef DOMAIN_CALLEE_H_
#define DOMAIN_CALLEE_H_

#include "../../Framework/Component/EventTarget.h"

class Callee: public EventTarget {
public:
	Callee() {}
	virtual ~Callee() {}
	int initialize() {
		return 0;
	}

	int targetFunction() {
		return 0;
	}

	vector<Event> generateEventQueue() {
		return 0;
	}
	void processEvent(Event event) {

	}
};




#endif /* DOMAIN_CALLEE_H_ */
