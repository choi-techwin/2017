/*
 * CallerStub.h
 *
 *  Created on: 2017. 4. 2.
 *      Author: choi.sungwoon
 */

#ifndef CALLERSTUB_H_
#define CALLERSTUB_H_

#include "EventTarget.h"

class CallerStub: public EventTarget {
public:
	CallerStub(int id): EventTarget(id) {}
	virtual ~CallerStub() {}
	void invoke(int componentId, int functionId, Parameters& parameters) {
		Event event;
		this->setEvent(event);
	}
};

#endif /* CALLERSTUB_H_ */
