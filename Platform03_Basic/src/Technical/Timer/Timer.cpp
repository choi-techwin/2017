/*
 * Timer.cpp
 *
 *  Created on: 2017. 4. 17.
 *      Author: choi.sungwoon
 */

#include "Timer.h"

Timer::Timer(): EventTarget(typeid(*this)) {
}

Timer::~Timer() {
}

int Timer::initialize() {
	return 0;
}

void Timer::generateEvents() {
}
void Timer::processEvent(Event event) {
}
