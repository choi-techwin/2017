/*
 * Caller.h
 *
 *  Created on: 2017. 4. 2.
 *      Author: choi.sungwoon
 */

#ifndef CALLER_H_
#define CALLER_H_

#include "CallerStub.h"

enum ECallerEvent { eStart=__COUNTER__ };

class Caller: public CallerStub {
private:
	int calleeId;
	bool wait;
public:
	Caller(int id): CallerStub(id), calleeId(0), wait(false) {}
	virtual ~Caller() {}

	void associate(int calleeId) {
		this->calleeId = calleeId;
	}
	void processEvent(Event* pEvent) {
		Args *pArgs;
		Results* pResults;

		switch(pEvent->getType()) {
		if (wait) {
			this->setEvent(pEvent);
		}
		else {
			case eStart:
				cout << "Caller::processEvent - " << "eStart" << endl;
				pArgs = new Args();
				pArgs->setArg(3);
				invoke(this->calleeId, eTargetFunction, pArgs);
				// synchronous invocation
				this->wait = true;
				break;
			case eTargetFunction:
				cout << "Caller::processEvent - " << "eTargetFunction(" << endl;
				pResults = (Results*)(pEvent->getPArg());
				cout << "- return result = " << pResults->getResult() << endl;
				this->wait = false;
				break;
			default:
				break;
			}
		}
	}
};

#endif /* CALLER_H_ */
