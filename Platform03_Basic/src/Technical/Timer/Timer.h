/*
 * Timer.h
 *
 *  Created on: 2017. 4. 17.
 *      Author: choi.sungwoon
 */

#ifndef TECHNICAL_TIMER_H_
#define TECHNICAL_TIMER_H_

#include "../../Framework/Component/EventTarget.h"

class Timer: public EventTarget {
public:
	Timer();
	virtual ~Timer();
	int initialize();

	void generateEvents();
	void processEvent(Event event);
};

#endif /* TECHNICAL_TIMER_H_ */
