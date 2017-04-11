/*
 * SkeletonMacro.h
 *
 *  Created on: 2017. 4. 3.
 *      Author: choi.sungwoon
 */

#ifndef CALLEESKELETONMACRO_H_
#define CALLEESKELETONMACRO_H_

#define EVENTMAP_BEGIN(Interface) \
class CalleeSkeleton: public EventTarget, public Interface { \
public: \
	CalleeSkeleton(int id): EventTarget(id) {} \
	virtual ~CalleeSkeleton() {} \
	void returnEvent(Event* pEvent, void *pResults) { \
		Event* pReturnEvent = new Event(); \
		pReturnEvent->setType(pEvent->getType()); \
		pReturnEvent->setTargetID(pEvent->getSourceID()); \
		pReturnEvent->setSourceID(this->getId()); \
		pReturnEvent->setPArg(pResults); \
		this->setEvent(pReturnEvent); \
		delete pEvent; \
	} \
	void processEvent(Event* pEvent) { \
		if (pEvent->getType() == -1) {}
#define EVENTMAP(eEventType, ReturnType, targetFunction, ArgType) \
		else if (pEvent->getType() == eEventType) { \
			ArgType* pArgs = (ArgType*) pEvent->getPArg(); \
			ReturnType* pResults = targetFunction(pArgs); \
			if (pArgs != 0)	delete pArgs; \
			returnEvent(pEvent, (void*)pResults); \
		}
#define EVENTMAP_END \
	} \
}; \

#endif /* CALLEESKELETONMACRO_H_ */
