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

	virtual Results* targetFunction(Args* pArgs) {
		cout << "Callee::targetFunction(" << pArgs->getArg() <<  ")" << endl;
		Results* pResults = new Results();
		pResults->setResult(pArgs->getArg()+1);
		return pResults;
	}
};

#endif /* CALLEE_H_ */
