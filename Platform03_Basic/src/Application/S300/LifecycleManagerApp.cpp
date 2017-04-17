/*
 * LifecycleManagerS300.cpp
 *
 *  Created on: 2017. 4. 12.
 *      Author: choi.sungwoon
 */

#include "../../Framework/LifecycleManager/LifecycleManagerApp.h"
#include "../../Framework/Scheduler/Scheduler.h"
#include "../../Domain/DCLink/DCLink.h"
#include "../../Domain/PWM/PWM.h"

static Scheduler scheduler1;
static Scheduler scheduler2;

static DCLink dcLink0;
static DCLink dcLink1;

static PWM pwm0;
static PWM pwm1;

LifecycleManagerApp::LifecycleManagerApp() {
}

LifecycleManagerApp::~LifecycleManagerApp() {
}

void LifecycleManagerApp::registerSchedulers() {
	this->addScheduler(&scheduler1);
	this->addScheduler(&scheduler2);
}

void LifecycleManagerApp::registerComponents() {
	this->addComponent(&dcLink0, &scheduler1);
	this->addComponent(&dcLink1, &scheduler2);
	this->addComponent(&pwm0);
	this->addComponent(&pwm1);
}

void LifecycleManagerApp::associateComponents() {
	pwm0.addEventSource(&dcLink0);
	pwm1.addEventSource(&dcLink1);
}
