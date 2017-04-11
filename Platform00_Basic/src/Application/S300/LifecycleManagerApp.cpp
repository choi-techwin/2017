/*
 * LifecycleManagerS300.cpp
 *
 *  Created on: 2017. 4. 12.
 *      Author: choi.sungwoon
 */

#include "../../Framework/LifecycleManager/LifecycleManagerApp.h"
#include "../../Domain/DCLink/DCLink.h"
#include "../../Domain/PWM/PWM.h"

static Scheduler scheduler1;
static Scheduler scheduler2;

static DCLink dcLink1;
static DCLink dcLink2;

static PWM pwm1;
static PWM pwm2;

LifecycleManagerApp::LifecycleManagerApp() {
}

LifecycleManagerApp::~LifecycleManagerApp() {
}

void LifecycleManagerApp::registerSchedulers() {
	this->addScheduler(&scheduler1);
	this->addScheduler(&scheduler2);
}

void LifecycleManagerApp::registerComponents() {
	this->addComponent(&dcLink1, &scheduler1);
	this->addComponent(&dcLink2, &scheduler2);
	this->addComponent(&pwm1);
	cout << "LifecycleManager::registerComponents()" << endl;
}

void LifecycleManagerApp::associateComponents() {
	pwm1.addEventSource(&dcLink1);
	pwm1.addEventSource(&dcLink2);
	cout << "LifecycleManager::associateComponents()" << endl;
}

void LifecycleManagerApp::initializeComponents() {
	dcLink1.initialize();
	dcLink2.initialize();
	pwm1.initialize();
}
