/*
 * CalleeSkeleton.h
 *
 *  Created on: 2017. 4. 2.
 *      Author: choi.sungwoon
 */

#ifndef CALLEESKELETON_H_
#define CALLEESKELETON_H_

#include "EventTarget.h"
#include <iostream>
using namespace std;

enum EFunctionEvents {eTargetFunction = __COUNTER__};

class Args {
private:
	int arg;
public:
	int getArg() { return this->arg; }
	void setArg(int arg) { this->arg = arg; }
};

class Results {
private:
	int result;
public:
	int getResult() { return this->result; }
	void setResult(int result) { this->result = result; }
};

class CalleeSkeleton: public EventTarget {
public:
	CalleeSkeleton(int id): EventTarget(id) {}
	virtual ~CalleeSkeleton() {}

	virtual Results* targetFunction(Args* pArgs) = 0;

	void returnResult(Event* pEvent, Results* pResults) {
		// return results
		Event* pReturnEvent = new Event();
		pReturnEvent->setType(pEvent->getType());
		pReturnEvent->setTargetID(pEvent->getSourceID());
		pReturnEvent->setSourceID(this->getId());
		pReturnEvent->setPArg((void*)pResults);
		this->setEvent(pReturnEvent);

		delete pEvent;
	}
	void processFunctionEvent(Event* pEvent) {
		Args* pArgs = 0;
		Results* pResults = 0;

		switch(pEvent->getType()) {
		case eTargetFunction:
			// invoke targetFunction
			pArgs = (Args*)pEvent->getPArg();
			pResults = targetFunction(pArgs);
			if (pArgs != 0)	delete pArgs;
			// send result
			this->returnResult(pEvent, pResults);
			break;
		default:
			break;
		}

	}
};

#endif /* CALLEESKELETON_H_ */
