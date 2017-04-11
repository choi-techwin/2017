/*
 * Callee.h
 *
 *  Created on: 2017. 4. 2.
 *      Author: choi.sungwoon
 */

#ifndef CALLEE_H_
#define CALLEE_H_

#include "CalleeSkeleton.h"

class Callee: public CalleeSkeleton {
public:
	Callee(int id): CalleeSkeleton(id) {}
	virtual ~Callee() {}

	virtual ReturnType* targetFunction(ArgType* pArgs) {
		ReturnType* pResults = new ReturnType();
		pResults->setResult(pArgs->getArg()+1);
		return pResults;
	}
};

#endif /* CALLEE_H_ */
