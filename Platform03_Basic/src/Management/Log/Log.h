/*
 * Log.h
 *
 *  Created on: 2017. 4. 17.
 *      Author: choi.sungwoon
 */

#ifndef COMMON_UTILITY_LOG_H_
#define COMMON_UTILITY_LOG_H_

#include "../../Framework/Component/EventTarget.h"

class Log: public EventTarget {
private:
public:
	Log() {}
	virtual ~Log() {}

	void generateEvents() {}
	void processEvent(Event event) {}


};

#endif /* COMMON_UTILITY_LOG_H_ */
