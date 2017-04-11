/*
 * CalleeSkeleton.h
 *
 *  Created on: 2017. 4. 2.
 *      Author: choi.sungwoon
 */

#ifndef CALLEESKELETON_H_
#define CALLEESKELETON_H_

#include "EventTarget.h"
#include "CalleeSkeletonMacro.h"

enum EFunctionEvents {eTargetFunction = __COUNTER__};

class ArgType {
private:
	int arg;
public:
	int getArg() { return this->arg; }
	void setArg(int arg) { this->arg = arg; }
};

class ReturnType {
private:
	int result;
public:
	int getResult() { return this->result; }
	void setResult(int result) { this->result = result; }
};

EVENTMAP(eTargetFunction, ReturnType, targetFunction, ArgType)
//class CalleeSkeleton: public EventTarget {
//public:
//	CalleeSkeleton(int id): EventTarget(id) {}
//	virtual ~CalleeSkeleton() {}
//	virtual ReturnType* targetFunction(ArgType* pArgs) = 0;
//	void processFunctionEvent(Event* pEvent) {
//		ArgType* pArgs = 0;
//		ReturnType* pResults = 0;
//		Event* pReturnEvent = 0;
//		switch(pEvent->getType()) {
//		case eTargetFunction:
//			pArgs = (ArgType*)pEvent->getPArg();
//			pResults = targetFunction(pArgs);
//			if (pArgs != 0)	delete pArgs;
//
//			pReturnEvent = new Event();
//			pReturnEvent->setType(pEvent->getType());
//			pReturnEvent->setTargetID(pEvent->getSourceID());
//			pReturnEvent->setSourceID(this->getId());
//			pReturnEvent->setPArg((void*)pResults);
//			this->setEvent(pReturnEvent);
//			delete pEvent;
//			break;
//		default:
//			break;
//		}
//	}
//};

#endif /* CALLEESKELETON_H_ */
