/*
 * Caller.h
 *
 *  Created on: 2017. 4. 2.
 *      Author: choi.sungwoon
 */

#ifndef CALLER_H_
#define CALLER_H_

#include "CallerStub.h"
#include "Callee.h"

enum ECallerEvent { eStart=__COUNTER__ };

class Caller: public CallerStub {
private:
	int calleeId;
public:
	Caller(int id): CallerStub(id), calleeId(0) {}
	virtual ~Caller() {}

	void associate(int calleeId) {
		this->calleeId = calleeId;
	}
	void processEvent(Event* pEvent) {
		switch(pEvent->getType()) {
		case eStart:
			Parameters parameters;
			invoke(this->calleeId, eTargetFunction, parameters);
			break;
		case eTargetFunction:
//			Results* pResults = (Results*)(pEvent->getPArg());
			break;
		default:
			break;
		}
	}
};

#endif /* CALLER_H_ */
