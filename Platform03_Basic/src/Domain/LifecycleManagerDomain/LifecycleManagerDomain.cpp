/*
 * LifecycleManagerDomain.cpp
 *
 *  Created on: 2017. 4. 17.
 *      Author: choi.sungwoon
 */

#include "LifecycleManagerDomain.h"

LifecycleManagerDomain::LifecycleManagerDomain() {

}

LifecycleManagerDomain::~LifecycleManagerDomain() {

}

void LifecycleManagerDomain::registerSchedulersDomain() {
	this->addScheduler(&scheduler1);
	this->addScheduler(&scheduler2);

}

void LifecycleManagerDomain::registerComponentsDomain() {
	this->addComponent(&dcLink0, &scheduler1);
	this->addComponent(&dcLink1, &scheduler2);
	this->addComponent(&pwm0);
	this->addComponent(&pwm1);

}

void LifecycleManagerDomain::associateComponentsDomain() {
	pwm0.addEventSource(&dcLink0);
	pwm1.addEventSource(&dcLink1);

}
