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

	virtual Results* targetFunction(Parameters *pParameters) {
		return 0;
	}
};

#endif /* CALLEE_H_ */
