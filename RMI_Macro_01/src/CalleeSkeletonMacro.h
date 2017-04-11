/*
 * SkeletonMacro.h
 *
 *  Created on: 2017. 4. 3.
 *      Author: choi.sungwoon
 */

#ifndef CALLEESKELETONMACRO_H_
#define CALLEESKELETONMACRO_H_

#define EVENTMAP(eEvent_type, ReturnType, targetFunction, ArgType) \
class CalleeSkeleton: public EventTarget { \
public: \
	CalleeSkeleton(int id): EventTarget(id) {} \
	virtual ~CalleeSkeleton() {} \
	\
	virtual ReturnType* targetFunction(ArgType* pArgs) = 0; \
	\
	void processFunctionEvent(Event* pEvent) { \
		ArgType* pArgs = 0; \
		ReturnType* pResults = 0; \
		Event* pReturnEvent = 0; \
		switch(pEvent->getType()) { \
		case eEvent_type: \
			pArgs = (ArgType*)pEvent->getPArg(); \
			pResults = targetFunction(pArgs); \
			if (pArgs != 0)	delete pArgs; \
			\
			pReturnEvent = new Event(); \
			pReturnEvent->setType(pEvent->getType()); \
			pReturnEvent->setTargetID(pEvent->getSourceID()); \
			pReturnEvent->setSourceID(this->getId()); \
			pReturnEvent->setPArg((void*)pResults); \
			this->setEvent(pReturnEvent); \
			delete pEvent; \
			break; \
		default: \
			break; \
		} \
	} \
}; \



#endif /* CALLEESKELETONMACRO_H_ */
