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

class CalleeInterface {
public:
	CalleeInterface() {}
	virtual ~CalleeInterface() {}
	virtual ReturnType* targetFunction(ArgType* pArgs) = 0;
};

EVENTMAP_BEGIN(CalleeInterface)
	EVENTMAP(eTargetFunction, ReturnType, targetFunction, ArgType)
EVENTMAP_END

#endif /* CALLEESKELETON_H_ */
