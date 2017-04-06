/*
 * CallerStub.h
 *
 *  Created on: 2017. 4. 2.
 *      Author: choi.sungwoon
 */

#ifndef CALLERSTUB_H_
#define CALLERSTUB_H_

#include "EventTarget.h"
#include "CalleeSkeleton.h"

class CallerStub: public EventTarget {
public:
	CallerStub(int id): EventTarget(id) {}
	virtual ~CallerStub() {}

	void invoke(int componentId, int functionId, Args* pArgs) {
		Event* pEvent = new Event();
		pEvent->setType(functionId);
		pEvent->setTargetID(componentId);
		pEvent->setSourceID(this->getId());
		pEvent->setPArg((void*)pArgs);

		this->setEvent(pEvent);
	}
};

#endif /* CALLERSTUB_H_ */
