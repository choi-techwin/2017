/*
 * CalleeSkeleton.h
 *
 *  Created on: 2017. 4. 2.
 *      Author: choi.sungwoon
 */

#ifndef CALLEESKELETON_H_
#define CALLEESKELETON_H_

#include "EventTarget.h"

class Parameters {

};

class Results {
public:
	Results() {}
};

enum EFunctionEvents {eTargetFunction = __COUNTER__};
class CalleeSkeleton: public EventTarget {
public:
	CalleeSkeleton(int id): EventTarget(id) {}
	virtual ~CalleeSkeleton() {}

	virtual Results* targetFunction(Parameters* pParameters) {
		return 0;
	}
	void processFunctionEvent(Event event) {
		switch(event.getType()) {
		case eTargetFunction:
//			Parameters* pParameters = (Parameters*)(event.getPArg());
//			Results* pResults = targetFunction(pParameters);
			event.setTargetID(event.getSourceID());
			event.setSourceID(this->getId());
//			event.setPArg((void *)pResults);
			setEvent(event);
			break;
		default:
			break;
		}

	}
};

#endif /* CALLEESKELETON_H_ */
